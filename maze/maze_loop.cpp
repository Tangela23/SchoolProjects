/*
  maze_loop.cpp

  Description:
    School project. C++
    Solves a maze defined as an integer matrix by using a loop.

  Team members:
    Laura
    Luis
    Jorge
*/

#include <iostream.h>
#include <stdio.h>
#include <stack>
using namespace std;

#define MAZE_ROAD    0
#define MAZE_WALL    1
#define MAZE_PATH    2
#define MAZE_EXIT    3
#define MAZE_DEADEND 4

#define MAZESIZE_X 8
#define MAZESIZE_Y 8

/*
  Maze definition
  The cursor can move through the 0's in the maze, but not
  through the 1's.
*/
int maze[ MAZESIZE_Y ][ MAZESIZE_X ]={
	{0, 1, 0, 1, 1, 1, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{0, 1, 0, 1, 1, 0, 0, MAZE_EXIT},
	{0, 1, 0, 0, 0, 1, 0, 1}, 
	{0, 0, 0, 1, 0, 0, 0, 1}};

/* Start coordinates */
int x = 0, y = 0;

/* Helper stack to keep track of the path to the maze exit. */
stack <char> mystack;

/*
  NextStep
  Gets a character indicating the direction in which the cursor can move.
*/
char NextStep();

/*
  GoBack
  Go back one step.
*/
void GoBack();	

/*
  PrintMaze
  Prints the maze to the standard output.
*/
void PrintMaze();

/*
  PrintStack
  Prints the current state of the stack to the standard output.
  The characters in the stack describe the steps needed to go from the
  start coordinates to the maze exit.
*/
void PrintStack();

/*
  Move
  Move one step further.
*/
void Move();

void main(){

	PrintMaze();

  /* While the current position is not the maze exit. */
	while( maze[ y ][ x ] != MAZE_EXIT ){
    Move();
	}

	PrintStack();
	PrintMaze();
}

void Move(){

  /* Get the direction in which the cursor can move. */
  switch( NextStep() ){
	
	case 0:	
    /* The cursor cannot move any further, go back one step. */
	  GoBack();
		break;
	case '>':
    /* The current position is part of the path to the maze exit. */
		maze[ y ][ x ] = MAZE_PATH;
    /* Move right. */
		x ++;
    /* Push this movement into the stack. */
		mystack.push('>');
		break;
	case '<':
		maze[ y ][ x ] = MAZE_PATH;
    /* Move left. */
		x --;
		mystack.push('<');
		break;
	case 'v':
		maze[ y ][ x ] = MAZE_PATH;
    /* Move down. */
		y ++;
		mystack.push('v');
		break;
	case '^':
		maze[ y ][ x ] = MAZE_PATH;
    /* Move up. */
		y --;
		mystack.push('^');
		break;
	}
}

char NextStep(){

  /* Check for the maze boundaries. */
	if( x < (MAZESIZE_X - 1) )
		if( (maze[ y ][ x + 1 ] == MAZE_ROAD) ||
        (maze[ y ][ x + 1 ] == MAZE_EXIT) )
      return '>';	/* Go right */

	if( x > 0 )
		if( (maze[ y ][ x - 1 ] == MAZE_ROAD) ||
        (maze[ y ][ x - 1 ] == MAZE_EXIT) )
      return '<';	/* Go left */

	if( y < (MAZESIZE_Y - 1) )
		if( (maze[ y + 1 ][ x ] == MAZE_ROAD) ||
        (maze[ y + 1 ][ x ] == MAZE_EXIT) )
      return 'v';	// Go Down

	if( y > 0 )
		if( (maze[ y - 1 ][ x ] == MAZE_ROAD) ||
        (maze[ y - 1 ][ x ] == MAZE_EXIT) )
      return '^';	// Go Up

  /* The cursor cannot move in any direction, this is a dead end. */
	return 0;
}

void GoBack(){

	if(mystack.empty()){
    /* The stack is empty and we are trying to go back. This means
       there is no solution to this maze. */
		cout<<"No solution";
    /* Convert the current position into the maze exit to end the program. */
		maze[ y ][ x ] = MAZE_EXIT;
		return;
	}

  /* Remember the current position lead to a dead end. */
	maze[ y ][ x ] = MAZE_DEADEND;

  /* If the previous movement was 'right', go left.*/
	if(mystack.top() == '>')	x --;
	if(mystack.top() == '<')	x ++;
	if(mystack.top() == '^')	y ++;
	if(mystack.top() == 'v')	y --;

  /* Pop the previous movement from the stack, as it is no
     longer part of the solution. */
	mystack.pop();
}

void PrintMaze(){

	cout<<endl<<endl<<"\1"<<endl;
	for(int i = 0; i < MAZESIZE_Y; i ++){
		for(int j = 0; j < MAZESIZE_X; j ++){
			if( maze[i][j] == MAZE_ROAD || maze[ i ][ j ] == MAZE_DEADEND)
				cout<<" ";
			else if(maze[ i ][ j ] == MAZE_EXIT)
				cout<<"!"<<"->\1";
			else if(maze[ i ][ j ] == MAZE_PATH)
				cout<<".";
			else if(maze[ i ][ j ] == MAZE_WALL)
				cout<<"#";
		}	
		cout<<endl;
	}
}

void PrintStack() {

	char path [ ( MAZESIZE_X * MAZESIZE_Y ) ];
	int i = 0;

	while( ! mystack.empty()){
		path[ i ] = mystack.top();
		mystack.pop();
		i++;
	}
	cout<<endl<<"Path: ";
	for( -- i  ; i >= 0; i --)
		cout<<path[ i ]<<" ";
}
