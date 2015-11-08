/*
  recipe_test.cpp

  Description:
    School project. C++
    Simple program to demonstrate the use of the Recipe class.
    Add/delete/search cooking recipes.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "recipe.H"

/* Maximum number of recipes */
#define RECIPE_MAXCNT 15

/* Menu options */
#define RECIPE_OPTION_ADD          ((int)1)
#define RECIPE_OPTION_DELETE       ((int)2)
#define RECIPE_OPTION_SEARCHBYNAME ((int)3)
#define RECIPE_OPTION_SEARCHBYNUM  ((int)4)
#define RECIPE_OPTION_RECIPES      ((int)5)
#define RECIPE_OPTION_EXIT         ((int)6)

void main()
{
	Recipe recipes[RECIPE_MAXCNT];
  
  /* Number of recipes in the data set. */
  int recipe_cnt = 0;

  /* Recipe name */
	char name[RECIPE_NAMELEN];
  /* Recipe instructions */
  char instr[RECIPE_INSTRLEN];

  /* Total number of ingredients */
  int  ingr_cnt;
  /* List of ingredient names */
  char ingr_name[RECIPE_INGR_MAXCNT][RECIPE_NAMELEN];
  /* List of ingredient amounts. */
  int  ingr_amnt[RECIPE_INGR_MAXCNT];

	int op, i, number;  

	do
	{
    /* Clear screen */
		system("cls");

    /* Print main menu. */
		cout<<"\n\tWELCOME TO MY RECIPE BOOK"<<endl<<endl;
		cout<<"\t1.Add recipe \n\t2.Delete recipe\n\t3.Search recipes by name\n\t4.Search recipes by number\n\t5.Display Recipes List\n\t6.Exit\t";
		cin>>op;

		switch(op)
		{
		case RECIPE_OPTION_ADD:
      /* Get the recipe info from the user. */
			cout<<endl<<"Enter the recipe number: ";
			cin>>number;

			cout<<endl<<"Enter the recipe name: ";
			cin>>name;

			cout<<endl<<"Number of ingredients ("<<RECIPE_INGR_MAXCNT<<" or less): ";
			cin>>ingr_cnt;
      ingr_cnt = (ingr_cnt <= RECIPE_INGR_MAXCNT ? ingr_cnt : RECIPE_INGR_MAXCNT);

			cout<<endl<<"List of ingredients:  ";
			for (i = 0; i < ingr_cnt; i++)
			{
				cout<<endl<<"Name the ingredient "<<i+1<<" of "<<ingr_cnt<<": ";
				cin.getline(ingr_name[i], RECIPE_NAMELEN);
				cin.getline(ingr_name[i], RECIPE_NAMELEN);
				cout<<"Amount: ";
				cin>>ingr_amnt[i];
			}
      /* Zero out the ingredients that were not specified. */
			for (i = ingr_cnt; i < RECIPE_INGR_MAXCNT; i++)
			{
				strcpy(ingr_name[i], " ");
				ingr_amnt[i] = 0;
			}

			cout<<endl<<"Enter the cooking instructions (press Enter when done):  ";
			cin.getline(instr, RECIPE_INSTRLEN);
			cin.getline(instr, RECIPE_INSTRLEN);

      /* Look for an empty slot in the data set. */
      for (i = 0; i < RECIPE_MAXCNT; i++)
			{
        if (recipes[i].GetNumber() == 0)
        {
          /* Add the new recipe. */
			    recipes[i].Set(number, name, ingr_name[ingr_cnt], ingr_amnt, instr);
          recipe_cnt++;
			    cout<<"Recipe added."<<endl;
        }
      }
      if (i >= RECIPE_MAXCNT)
        cout<<"Error: The recipe was not added. Maximum number of recipes reached."<<endl;

      cout<<"\nPress any key to continue..."<<endl;
			getchar();
			break;

		case RECIPE_OPTION_DELETE:
      /* Get the recipe number to delete: */
			cout<<"\nEnter the recipe number to delete: ";
			cin>>number;
      
      for (i = 0; i < RECIPE_MAXCNT; i++)
      {
        if (recipes[i].GetNumber() == number)
        {
          /* Recipe found, delete it. */
			    recipes[i].Clear();
          recipe_cnt--;
			    cout<<"Recipe deleted."<<endl;
        }
      }
      if (i >= RECIPE_MAXCNT)
        cout<<"Recipe not found."<<endl;

      cout<<"\nPress any key to continue..."<<endl;
			getchar();
			break;

		case RECIPE_OPTION_SEARCHBYNAME:
			cout<<"Enter the recipe name:  ";
			cin>>name;

      for (i = 0; i < RECIPE_MAXCNT; i++)
			{
			  if (!strcmp(recipes[i].GetName(), name))
        {
          /* Recipe found, print the recipe details. */
			    recipes[i].Print();
        }
      }
      if (i >= RECIPE_MAXCNT)
        cout<<"Recipe not found."<<endl;

			cout<<"\nPress any key to continue..."<<endl;
			getchar();
			break;

		case RECIPE_OPTION_SEARCHBYNUM:
			cout<<"Enter the recipe number:  ";
			cin>>number;
			for (i = 0; i < RECIPE_MAXCNT; i++)
      {
        if (recipes[i].GetNumber() == number)
        {
          /* Recipe found, print the recipe details. */
			    recipes[i].Print();
        }
      }
      if (i >= RECIPE_MAXCNT)
        cout<<"Recipe not found."<<endl;

			cout<<"\nPress any key to continue..."<<endl;
			getchar();
			break;

		case RECIPE_OPTION_RECIPES:
      /* List all existing recipes. */
      for (i = 0; i < RECIPE_MAXCNT; i++)
      {
        recipes[i].PrintShort();
      }

			cout<<"\nPress any key to continue..."<<endl;
			getchar();
			break;
		}
	}	while (op != RECIPE_OPTION_EXIT);
}
