/*
  animal_test2.cpp

  Description:
    Programming exercises. C++
    Simple program to test the animal class.
*/

#include <iostream>
#include <string.h>
#include "animal2.H"

using namespace std;

int main(void)
{
#define ANIMAL_MAXNUM 10
  Animal animals[ANIMAL_MAXNUM];

  char        name[ANIMAL_NAMELEN];
  int         diet    = 0;
  int         habitat = 0;
  int         sclass  = 0;
  int         genre   = 0;
  int         gestation;
  int         feet;
  int         tmp;

  int op, i;

  do
  {
    /* Print the main menu. */
    cout<<"Search for an animal in the data set based on the following criteria:"<<endl;
    cout<<"Type of diet: 1.Carnivore 2.Herbivore"<<endl;
    cin>>diet;
    cout<<"Type of habitat: 1.Marine 2.Terrestrial 3.Aerial"<<endl;
    cin>>habitat;
    cout<<"Class: 1.Mammal 2.Reptile 3.Fish 4.Bird"<<endl;
    cin>>sclass;
    cout<<"Genre: 1.Female 2.Male"<<endl;
    cin>>genre;
    cout<<"Gestation (months):"<<endl;
    cin>>gestation;
    cout<<"Number of feet:"<<endl;
    cin>>feet;

    /* Search for an animal in the data set matching the user input. */
    for (i = 0; i < ANIMAL_MAXNUM; i++)
    {
      if (animals[i].GetDiet() == (DietType)diet &&
          animals[i].GetHabitat() == (HabitatType)habitat &&
          animals[i].GetGestation() == gestation &&
          animals[i].GetClass() == (ClassType)sclass &&
          animals[i].GetGenre() == (GenreType)genre &&
          animals[i].GetFeet() == feet)
      {
        /* The animal exists in the data set. Print the name. */
        cout<<"Name:"<<animals[i].GetName()<<endl;
        break;
      }
    }

    if (i >= ANIMAL_MAXNUM)
    {
      /* The animal was not found in the data set. */
      cout<<"The animal was not found"<<endl;

      cout<<"Would you like to add the animal to the data set?"<<endl<<"\t1.Yes"<<endl<<"\t2.No"<<endl;
      cin>>op;
      if (op == 1)
      {
        /* Add the animal to an empty slot in the array. */
        cout<<"Enter the animal name:"<<endl;
        cin>>name;
        /* Search for an empty slot in the data set. */
        for (i = 0; i < ANIMAL_MAXNUM; i++)
        {
          if (animals[i].GetClass() == ClassType::UNKNOWN)
          {
            animals[i].Init(name, (DietType)diet, (HabitatType)habitat,
                            (ClassType)sclass, (GenreType)genre, gestation, feet);
            break;
          }
        }
      }
    }

    cout<<"Would you like to make a new search?"<<endl<<"\t1.Yes"<<endl<<"\t2.No"<<endl;
    cin>>op;

  }  while (op == 1);

  return 0;
}

