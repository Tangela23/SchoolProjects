/*
  recipe.H

  Description:
    School project. C++
    Recipe class definition. Describes a cooking recipe with a list of
    ingredients and cooking instructions.
*/

#include <iostream.h>
#include <string.h>

/* Maximum length of a recipe or ingredient Name */
#define RECIPE_NAMELEN 40
/* Maximum length of the recipe instructions */
#define RECIPE_INSTRLEN 150

/* Maximum number of ingredients */
#define RECIPE_INGR_MAXCNT 10

class Recipe
{
  public:
    /*
      Recipe
      Constructor
    */
  	Recipe();
    
    /*
      GetNumber
      Gets the recipe number.
    */
	  int GetNumber();
    
    /*
      GetName
      Gets the recipe name.
    */
	  char *GetName();
    
    /*
      Set
      Initializes this object with the given parameters.
    */
	  void Set(const int _number, 
             const char *_name, 
             char **_ingredients, 
             const int _amounts[RECIPE_INGR_MAXCNT], 
             const char *_instructions)
    
    /*
      Operator '==' overloading to compare two Recipe objects.
    */
	  int operator==(Recipe&);
    
    /*
      ask
      Friend function to get the recipe number and name from console.
    */
	  friend void ask(Recipe&);
    
    /*
      PrintShort
      Prints the recipe number and name to the standard output.
    */
	  void PrintShort();
    
    /*
      Print
      Prints the complete recipe ingredients and instructions to the
      standard output.
    */
	  void Print();
    
    /*
      Clear
      Zero out all of this object's parameters.
    */
	  void Clear();

  private:
    /* Recipe number. */
  	int  Number;
    /* Recipe name. */
  	char Name[RECIPE_NAMELEN];
    /* Preparation instructions. */
  	char Instructions[RECIPE_INSTRLEN];
    /* List of ingredient names. */
	  char Ingredients[RECIPE_INGR_MAXCNT][RECIPE_NAMELEN];
    /* Amount per ingredient. */
	  int  Amounts[RECIPE_INGR_MAXCNT];
};

Recipe::Recipe()
{
	int i;

	Number = 0;
	strcpy(Name, "");
	strcpy(Instructions, "");

	for (i = 0; i < RECIPE_INGR_MAXCNT; i++)
	{
		strcpy(Ingredients[i], "");
		Amounts[i] = 0;
	}
}

int Recipe::GetNumber()
{
	return Number;
}

char *Recipe::GetName()
{
	return Name;
}

void Recipe::Set(const int _number, 
                 const char *_name, 
                 char **_ingredients, 
                 const int _amounts[RECIPE_INGR_MAXCNT], 
                 const char *_instructions)
{
	int i;

	Number = _number;
	strcpy(Name, _name);
	strcpy(Instructions, _instructions);

	for (i = 0; i < RECIPE_INGR_MAXCNT; i++)
	{
		strcpy(Ingredients[i], _ingredients[i]);
		Amounts[i] = _amounts[i];
	}
}

int Recipe::operator==(Recipe&x)
{
	if (x.Number == Number && !strcmp(x.Name, Name))
		return 1;
	else
		return 0;
}

void ask(Recipe&x)
{
	cout<<"Enter the recipe number:"<<endl;
	cin>>x.Number;
	cout<<"Enter the recipe name:"<<endl;
	cin>>x.Name;
}

void Recipe::PrintShort()
{
	int i;
  
  if (Number == 0)
    /* Empty recipe, skip. */
    return;

	cout<<endl<<"RECIPE #"<<Number<<" \t\""<<Name<<"\""<<endl<<endl;
}

void Recipe::Print()
{
	int i;
  
  if (Number == 0)
    /* Empty recipe, skip. */
    return;

  PrintShort();

  cout<<"Ingredients:"<<endl<<endl;  
  for (i = 0; i < RECIPE_INGR_MAXCNT; i++)
  {
    if (Amounts[i] != 0)
    {
      cout<<"  -"<<Amounts[i]<<" \t"<<Ingredients[i]<<endl;
    }
  }

	cout<<endl<<"Preparation: "<<endl<<Instructions<<endl;
}

void Recipe::Clear()
{
	Recipe();
}


