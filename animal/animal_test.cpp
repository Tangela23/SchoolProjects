/*
  animal_test.cpp

  Description:
    Programming exercises. C++
    Simple program to test the animal class. There is a fixed set of animals
    and the user may list the existing animals by type, by specie, or by name.
*/

#include <iostream>
#include <string.h>
#include "animal.H"

using std::cout;
using std::endl;
using std::cin;

/* Number of animals in the data set. */
#define ANIMAL_COUNT 15

/* Menu options. */
#define ANIMAL_OPTION_TYPE   ((int)1)
#define ANIMAL_OPTION_SPECIE ((int)2)
#define ANIMAL_OPTION_NAME   ((int)3)
#define ANIMAL_OPTION_EXIT   ((int)4)

int main(void)
{
  Animal animals[ANIMAL_COUNT];
  int op, type, i;
  char specie [ANIMAL_MAXSTR];
  char name [ANIMAL_MAXSTR];

  /* Initialize all animals with valid values. */
  animals[0].Init((char *)"Lion", (char *)"Momo",   4, 4, (char *)"Hair", (char *)"Meat");
  animals[1].Init((char *)"Lion", (char *)"Carlos", 4, 4, (char *)"Hair", (char *)"Meat");
  animals[2].Init((char *)"Zebra", (char *)"Fido",   4, 4, (char *)"Hair", (char *)"Grass");
  animals[3].Init((char *)"Zebra", (char *)"Karla",  4, 4, (char *)"Hair", (char *)"Grass");
  animals[4].Init((char *)"Zebra", (char *)"Pluto",  4, 6, (char *)"Hair", (char *)"Grass");
  animals[5].Init((char *)"Bear", (char *)"Teddy",  4, 6, (char *)"Hair", (char *)"Nuts");
  animals[6].Init((char *)"Snake", (char *)"Hugo",   0, 9, (char *)"Scales", (char *)"Mice");
  animals[7].Init((char *)"Crocodile", (char *)"Coco",   4, 10, (char *)"Scales", (char *)"Meat");
  animals[8].Init((char *)"Crocodile", (char *)"Yoshi",  4, 4, (char *)"Scales", (char *)"Meat");
  animals[9].Init((char *)"Lizard", (char *)"Marcos", 4, 7, (char *)"Scales", (char *)"Bugs");
  animals[10].Init((char *)"Lizard", (char *)"Moki",   4, 7, (char *)"Scales", (char *)"Bugs");
  animals[11].Init((char *)"Lizard", (char *)"Lizzy",  4, 7, (char *)"Scales", (char *)"Bugs");
  animals[12].Init((char *)"Parrot", (char *)"Niko",   2, 30, (char *)"Feathers", (char *)"Seeds");
  animals[13].Init((char *)"Parrot", (char *)"Paco",   2, 30, (char *)"Feathers", (char *)"Papaya");
  animals[14].Init((char *)"Ostrich", (char *)"Mimi",   2, 14, (char *)"Feathers", (char *)"Eggs");

  do
  {
    /* Print the main menu and get the user input. */
    cout<<"\n";
    cout<<"Search the animal database:\n\n";
    cout<<"1) By Type\n2) By specie\n3) By name\n4) Exit\n";
    cout<<"Select an option: ";
    cin>>op;
    cout<<"\n";

    switch (op)
    {
    case ANIMAL_OPTION_TYPE:
      cout<<"Types of animals:\n\n";
      cout<<"1) Reptiles\n2) Mammals\n3) Birds\n";
      cout<<"Select an option: ";
      cin>>type;
      cout<<"\n";
      switch(type)
      {
      case 2:
        for (i = 0; i < 6; i++)
          animals[i].Print();
        break;
      case 1:
        for (i = 6; i < 12; i++)
          animals[i].Print();
        break;
      case 3:
        for (i = 12; i < ANIMAL_COUNT;i++)
          animals[i].Print();
        break;
      }
      break;

    case ANIMAL_OPTION_SPECIE:
      cout<<"Enter the name of the specie: ";
      cin>>specie;
      for (i = 0; i < ANIMAL_COUNT; i++)
      {
        if (!strcmp(animals[i].GetSpecie(), specie))
        {
          cout<<"\n";
          animals[i].Print();
          break;
        }
      }
      if (i == ANIMAL_COUNT)
        cout<<"No "<<specie<<"s were found in the data set.\n";
      break;

    case ANIMAL_OPTION_NAME:
      cout<<"Enter the animal name: ";
      cin>>name;
      for (i = 0; i < ANIMAL_COUNT; i++)
      {
        if (!strcmp(animals[i].GetName(), name))
        {
          cout<<"\n";
          animals[i].Print();
          break;
        }
      }
      if (i == ANIMAL_COUNT)
        cout<<"No animals were found in the data set with the name '"<<name<<"'.\n";
      break;
    }
  }
  while (op != ANIMAL_OPTION_EXIT);

  return 0;
}
