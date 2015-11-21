/*
  chutes_and_ladders.cpp
  
  Programming exercise. C++
*/

#include <iostream>
#include "stdafx.h"

using namespace std;

#define MAX_PLAYERS        6
#define BOARD_SIZE       100
#define GOAL_POSITION    100
#define MAX_DICE_THROWS 1000
#define MAX_DICE_VALUE    12
#defnie NO_WINNER       (MAX_PLAYERS + 1)

int dice_results[MAX_DICE_THROWS];

/* Position of every chute and ladder.
 *
 * Column 0 of this matrix indicates the board position that contains a chute
 * or ladder. Column 1 indicates the target position the player will go to if
 * he happens to step on that chute/ladder.
 *
 * Chutes take the player to a later position in the board while ladders take
 * him to a previous position in the board. There is no need to keep separate
 * arrays for chutes and ladders. */
int ladders[2][BOARD_SIZE];

// Numero de serpientes/escaleras
int ladder_count;

/*
  play
  
  Executes each player's turn until someone wins the game or the
  number of dice throws is over.
  Returns the index of the winner player; else if nobody won returns NO_WINNER.
*/
int play(const int player_count, const int dice_rounds);

int main(void)
{
	int turnIndex = 0;
  int player_count;
  int dice_rounds;
  int winner;
  int i;
  
  cout<<"CHUTES AND LADDERS"<<endl<<endl;

  /* Get the number of players. */
  cout<<"Enter the number of players (maximum "<<MAX_PLAYERS<<"): ";
  cin>>player_count;
  player_count = (player_count <= MAX_PLAYERS) ? player_count : MAX_PLAYERS;
  cout<<endl;
  
  /* End the game now if nobody is playing. */
  if (player_count == 0)
    return 0;

  /* Get the location of each chute and ladder. */
  ladder_count = 0;
  cout<<"Configure the set of chutes and ladders in the board by entering";
  cout<<"the location of the chute/ladder and the target position it will";
  cout<<"take the player to. The board has a total of "<<BOARD_SIZE<<" ";
  cout<<"positions (from 0 to "<<BOARD_SIZE<<"). When done, enter 0 and 0.";
  cout<<endl;
  do
  {
    cout<<"Chute/ladder #"<<(ladder_count + 1)<<" at position: ";
    cin>>ladders[0][ladder_count];
    cout<<", target position: ";
    cin>>ladders[1][ladder_count];
    cout<<endl;
      
    /* End the configuration when the user types 0 and 0. */
    if (ladders[0][ladder_count] == 0 && ladders[1][ladder_count] == 0)
      break;

    ladder_count++;
    
    /* Keep the array of chutes and ladders in board-position ascending
     * order using insertion sort. */
    i = ladder_count;
    while (i > 0 && ladders[0][i] < ladders[0][i - 1])
    {
      int temp[2] = {ladders[0][i], ladders[1][i]};
      ladders[0][i] = ladders[0][i - 1];
      ladders[1][i] = ladders[1][i - 1];
      ladders[0][i - 1] = temp[0];
      ladders[1][i - 1] = temp[1];
      i --;
    }
  } while (ladder_count < BOARD_SIZE);
  cout<<endl;

  /* Let the user enter the dice result for each round. */
  dice_rounds = 0;
  cout<<"Enter the dice result for each round. When done, enter 0."<<endl;
  while (dice_rounds < MAX_DICE_THROWS)
  {
    cin<<dice_results[dice_rounds];
    
    /* Limit the dice result to the maximum allowable value. */
    if (dice_results[dice_rounds] > MAX_DICE_VALUE)
      dice_results[dice_rounds] = MAX_DICE_VALUE;

    /* End the configuration when the user types 0. */
    if (dice_results[dice_rounds] == 0)
      break;

    dice_rounds++;
  }
  cout<<endl;

  /* Play chutes and ladders. */
  winner = play(player_count);

  /* Display the result of the game. */
  cout<<endl;
  if (winner != NO_WINNER)
	  cout<<"Player #"<<(winner + 1)<<" wins!"<<endl;
  else
    cout<<"Nobody reached the goal."<<endl;

  return 0;
}

int play(const int player_count, const int dice_rounds)
{
  /* Current board position per player. */
  int position[MAX_PLAYERS];
  /* Current player index. */
  int player;
  /* Number of lost turns per player. */
  int lost_turns[MAX_PLAYERS];
  int i;
	int diceIndex = 0, turnIndex = 0;

  /* All players start at the beginning of the board. */
  for (i = 0; i < MAX_PLAYERS; i++)
    position[i] = 0;
    
  /* Initialize the lost_turns array. */
  for (i = 0; i < MAX_PLAYERS; i++)
    lost_turns[i] = 0;

  /* Player 0 is the first to play. */
  player = 0;

  /* Roll the dice as many times as we can. */
	while (diceIndex < dice_rounds)
	{
    /* If the player lost one turn, skip it. */
    if (lost_turns[player] > 0)
    {
      lost_turns[player]--;

      /* Choose the next player. */
      player++;
      player = (player < player_count ? player : 0);

      continue;
    }

    /* Advance the player to the next position, based on the dice results.
     * The player cannot go beyond the board size and he cannot advance if
     * the dice result is greater than the number of positions left in the
     * board. */
    if ((position[player] + dice_results[diceIndex]) <= BOARD_SIZE)
      position[player] += dice_results[diceIndex];

    /* Check of there is a chute/ladder at the current player's position.
     * NOTE: The ladders array is sorted in board-position ascending order,
     * with this heuristic we don't need to traverse the whole array. */
    for (i = 0; (i < ladder_count) && (ladders[0][i] <= position[player]); i++)
    {
      if (ladders[0][i] == position[player])
      {
        /* Move the player to the target position of this chute/ladder. */
        position[player] = ladders[1][i];
        break;
      }
    }

    /* A player wins the game upon reaching the goal position. */
    if (position[player] == GOAL_POSITION)
      return player;

    /* Choose the next player. */
    player++;
    player = (player < player_count ? player : 0);

    /* Roll the dice for the next player. */
    diceIndex ++;
	}

  /* Nobody reached the goal position. */
  return NO_WINNER;
}
