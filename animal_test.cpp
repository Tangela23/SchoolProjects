/*
  animal_test.cpp

  Description:
    Programming exercises. C++
    Simple program to test the animal class. There is a fixed set of animals
    and the user may list the existing animals by type, by specie, or by name.
*/

#include <iostream.h>
#include <string.h>
#include "animal.H"

/* Menu options. */
#defnie ANIMAL_OPTION_TYPE   ((int)1)
#define ANIMAL_OPTION_SPECIE ((int)2)
#define ANIMAL_OPTION_NAME   ((int)3)
#define ANIMAL_OPTION_EXIT   ((int)4)

void main()
{
	Animal animals[15];
	int op, type, i;
	char specie [ANIMAL_MAXSTR];
	char name [ANIMAL_MAXSTR];

  /* Initialize all animals with valid values. */
	animals[0].Init("Lion",      "Momo",   4, 4,  "Hair",     "Meat");
	animals[1].Init("Lion",      "Carlos", 4, 4,  "Hair",     "Meat");
	animals[2].Init("Zebra",     "Fido",   4, 4,  "Hair",     "Grass");
	animals[3].Init("Zebra",     "Karla",  4, 4,  "Hair",     "Grass");
	animals[4].Init("Zebra",     "Pluto",  4, 6,  "Hair",     "Grass");
	animals[5].Init("Bear",      "Teddy",  4, 6,  "Hair",     "Nuts");
	animals[6].Init("Snake",     "Hugo",   0, 9,  "Scales",   "Mice");
	animals[7].Init("Crocodile", "Coco",   4, 10, "Scales",   "Meat");
	animals[8].Init("Crocodile", "Yoshi",  4, 4,  "Scales",   "Meat");
	animals[9].Init("Lizard",    "Marcos", 4, 7,  "Scales",   "Bugs");
	animals[10].Init("Lizard",   "Moki",   4, 7,  "Scales",   "Bugs");
	animals[11].Init("Lizard",   "Lizzy",  4, 7,  "Scales",   "Bugs");
	animals[12].Init("Parrot",   "Niko",   2, 30, "Feathers", "Seeds");
	animals[13].Init("Parrot",   "Paco",   2, 30, "Feathers", "Papaya");
	animals[14].Init("Ostrich",  "Mimi",   2, 14, "Feathers", "Eggs");

	do
	{
    /* Print the main menu and get the user input. */
		cout<<"Welcome \n\n How will your query be?\n\n \t1.By Type \n\t2.By specie \n\t3.By name \n\t4.Exit"<<endl;
		cin>>op;

		switch (op)
		{
		case ANIMAL_OPTION_TYPE:
			cout<<"1.Reptiles\n2.Mammals\n3.Birds\n"<<endl;
			cin>>type;
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
				for (i = 12; i < 15;i++)
					animals[i].Print();
				break;
			}
			break;

		case ANIMAL_OPTION_SPECIE:
			cout<<"Tell me the specie: "<<endl;
			cin>>specie;
			for (i = 0; i < 15; i)
			{
				cout<<"Specie"<<endl;
				if (!strcmp(animals[i].GetSpecie(), specie))
				{
					cout<<"Animal:"<<endl;
					animals[i].Print();
					break;
				}
				else
					i++;
			}
			break;

		case ANIMAL_OPTION_NAME:
			cout<<"Tell me the name: "<<endl;
			cin>>name;
			for (i = 0; i < 15; i++)
			{
				if (!strcmp(animals[i].GetName(), name))
				{
					cout<<"Animal:"<<endl;
					animals[i].Print();
					break;
				}
			}
			break;
		}
	}
	while (op != ANIMAL_OPTION_EXIT);
}
