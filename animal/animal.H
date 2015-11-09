/*
  animal.H

  Description:
    Programming exercises. C++
    Definition for the Animal class.
*/

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

/* Maximum length of any of the string animal characteristics. */
#define ANIMAL_MAXSTR 40

class Animal
{
public:
  Animal();
  void Init(char *_specie, char *_name, int _life, int _feet, char *_hair, char *_food);
  inline char *GetSpecie()
  {
    return Specie;
  }
  inline char *GetName()
  {
    return Name;
  }
  void Print();

private:
  /* Name of the specie */
  char Specie[ANIMAL_MAXSTR];
  /* Animal name */
  char Name[ANIMAL_MAXSTR];
  /* Expected life (years) */
  int Life;
  /* Number of feet */
  int Feet;
  /* Type of hair */
  char Hair[ANIMAL_MAXSTR];
  /* Preferred food */
  char Food[ANIMAL_MAXSTR];
};

Animal::Animal()
{
  strcpy(Specie, "");
  strcpy(Name, "");
  Life = 0;
  Feet = 0;
  strcpy(Hair, "");
  strcpy(Food, "");
}

/*
  Initialize this object with the given parameters.
*/
void Animal::Init(char *_specie, char *_name, int _life, int _feet, char *_hair, char *_food)
{
  strcpy(Specie, _specie);
  strcpy(Name, _name);
  Life = _life;
  Feet = _feet;
  strcpy(Hair, _hair);
  strcpy(Food, _food);
}

/*
  Prints all the animal characteristics to the standard output.
*/
void Animal::Print()
{
  cout<<"ANIMAL: "<<Name<<" ("<<Specie<<")"<<endl;
  cout<<"  Expected life:   "<<Life<<" years"<<endl;
  cout<<"  Number of feet:  "<<Feet<<endl;
  cout<<"  Kind of hair:    "<<Hair<<endl;
  cout<<"  Diet:            "<<Food<<endl;
}

