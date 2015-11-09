/*
  animal2.H

  Description:
    Programming exercises. C++
    Definition for the Animal class (version 2).
*/

#include <iostream>
#include <string.h>

using namespace std;

enum class DietType    {UNKNOWN, CARNIVORE, HERBIVORE};
enum class HabitatType {UNKNOWN, MARINE, TERRESTRIAL, AERIAL};
enum class ClassType   {UNKNOWN, MAMMAL, REPTILE, FISH, BIRD};
enum class GenreType   {UNKNOWN, FEMALE, MALE};

#define ANIMAL_NAMELEN 40

class Animal
{
public:
  /* 
    Animal::Animal
    Constructor.
  */
  Animal();

  inline char *GetName()
  {
    return Name;
  }

  inline DietType GetDiet()
  {
    return Diet;
  }

  inline HabitatType GetHabitat()
  {
    return Habitat;
  }

  inline ClassType GetClass()
  {
    return Class;
  }

  inline GenreType GetGenre()
  {
    return Genre;
  }

  inline int GetGestation()
  {
    return Gestation;
  }

  inline int GetFeet()
  {
    return Feet;
  }

  /*
    Animal::Init
    Initializes the animal with the given characteristics.
  */
  void Init(const char       *_name,
            const DietType    _diet,
            const HabitatType _habitat,
            const ClassType   _class,
            const GenreType   _genre,
            const int         _gestation,
            const int         _feet);

  /*
    Animal::Print
    Prints all the animal characteristics to the standard output.
  */
  void Print();

private:
  /* Name of the animal. */
  char Name[ANIMAL_NAMELEN];

  /* Type of diet. */
  DietType Diet;

  /* Type of habitat. */
  HabitatType Habitat;

  /* Class. */
  ClassType Class;

  /* Genre. */
  GenreType Genre;

  /* Gestation period (months). */
  int Gestation;

  /* Number of feet. */
  int Feet;
};

Animal::Animal()
{
  strcpy(Name, "");
  Diet      = DietType::UNKNOWN;
  Habitat   = HabitatType::UNKNOWN;
  Class     = ClassType::UNKNOWN;
  Genre     = GenreType::UNKNOWN;
  Gestation = 0;
  Feet      = 0;
}

void Animal::Init(const char       *_name,
                  const DietType    _diet,
                  const HabitatType _habitat,
                  const ClassType   _class,
                  const GenreType   _genre,
                  const int         _gestation,
                  const int         _feet)
{
  strcpy(Name, _name);
  Diet      = _diet;
  Habitat   = _habitat;
  Class     = _class;
  Genre     = _genre;
  Gestation = _gestation;
  Feet      = _feet;
}

void Animal::Print()
{
  cout<<"Name: "<<Name<<endl;

  switch (Diet)
  {
    case DietType::UNKNOWN:   cout<<"Type of diet: Unknown"<<endl;   break;
    case DietType::CARNIVORE:  cout<<"Type of diet: Carnivore"<<endl; break;
    case DietType::HERBIVORE: cout<<"Type of diet: Herbivore"<<endl; break;
  }

  switch(Habitat)
  {
    case HabitatType::UNKNOWN:     cout<<"Type of habitat: Unknown"<<endl;     break;
    case HabitatType::MARINE:       cout<<"Type of habitat: Marine"<<endl;       break;
    case HabitatType::TERRESTRIAL: cout<<"Type of habitat: Terrestrial"<<endl; break;
    case HabitatType::AERIAL:       cout<<"Type of habitat: Aerial"<<endl;       break;
  }

  switch(Class)
  {
  case ClassType::UNKNOWN: cout<<"Class: Unknown"<<endl; break;
  case ClassType::MAMMAL:   cout<<"Class: Mammal"<<endl;   break;
  case ClassType::REPTILE: cout<<"Class: Reptile"<<endl; break;
  case ClassType::FISH:     cout<<"Class: Fish"<<endl;     break;
  case ClassType::BIRD:     cout<<"Class: Bird"<<endl;     break;
  }

  switch (Genre)
  {
    case GenreType::UNKNOWN: cout<<"Genre: Unknown"<<endl; break;
    case GenreType::FEMALE:   cout<<"Genre: Female"<<endl;  break;
    case GenreType::MALE:    cout<<"Genre: Male"<<endl;    break;
  }

  cout<<"Gestation period (months): "<<Gestation<<endl;

  cout<<"Number of feet: "<<Feet<<endl;
}

