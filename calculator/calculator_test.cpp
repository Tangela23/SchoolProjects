/*
  calculator_test.cpp

  Description:
    School project. C++
    Simple demonstration of a scientific calculator using the calculator class
    defined in file calculator.H.
*/

#include <iostream.h>
#include <math.h>
#include "calculator.H"

#define CALC_OPTION_SUM            ((int)1)
#define CALC_OPTION_SUBTRACTION    ((int)2)
#define CALC_OPTION_MULTIPLICATION ((int)3)
#define CALC_OPTION_DIVISION       ((int)4)
#define CALC_OPTION_PERCENTAGE     ((int)5)
#define CALC_OPTION_POWER          ((int)6)
#define CALC_OPTION_SQUAREDROOT    ((int)7)
#define CALC_OPTION_SINE           ((int)8)
#define CALC_OPTION_COSINE         ((int)9)
#define CALC_OPTION_TANGENT        ((int)10)
#define CALC_OPTION_INVSINE        ((int)11)
#define CALC_OPTION_INVCOSINE      ((int)12)
#define CALC_OPTION_INVTANGENT     ((int)13)
#define CALC_OPTION_EXIT           ((int)14)

void main()
{
  int op;
  double a, b, c;
  Calculator calc;
  
  do
  {
    /* Print the menu. */
		cout<<"\n\tSCIENTIFIC CALCULATOR SIMULATOR\n"
			<<" 1) Sum\n"
			<<" 2) Subtraction\n"
			<<" 3) Multiplication\n"
			<<" 4) Division\n"
			<<" 5) Percentage\n"
			<<" 6) Power\n"
			<<" 7) Squared root\n"
			<<" 8) Sine\n"
			<<" 9) Cosine\n"
			<<"10) Tangent\n"
			<<"11) Funcion Seno Inverso\n"
			<<"12) Funcion Coseno Inverso\n"
			<<"13) Funcion Tangente Inverso\n"
			<<"14) Exit\n"
			<<"Choose one operation:";
    
    /* Get the user input. */
		cin>>op;
    
    /* Execute the operation selected by the user. */
		switch (op)
		{
		case CALC_OPTION_SUM:
			cout<<"\na = ";
			cin>>a;
			cout<<"\nb = ";
			cin>>b;
			c = calc.Sum(a, b);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_SUBTRACTION:
			cout<<"\na = ";
			cin>>a;
			cout<<"\nb = ";
			cin>>b;
			c = calc.Subtraction(a, b);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_MULTIPLICATION:
			cout<<"\na = ";
			cin>>a;
			cout<<"\nb = ";
			cin>>b;
			c = calc.Multiplication(a, b);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_DIVISION:
			cout<<"\na = ";
			cin>>a;
			cout<<"\nb = ";
			cin>>b;
			c = calc.Division(a, b);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_PERCENTAGE:
			cout<<"\na = ";
			cin>>a;
			cout<<"\nb = ";
			cin>>b;
			c = calc.Percentage(a, b);
			cout<<"\n"<<b<<"% of "<<a<<" = "<<c;
			break;
		case CALC_OPTION_POWER:
			cout<<"\na = ";
			cin>>a;
			cout<<"\nb = ";
			cin>>b;
			c = calc.Power(a, b);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_SQUAREDROOT:
			cout<<"\na = ";
			cin>>a;
			c = calc.SquaredRoot(a);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_SINE:
			cout<<"\na = ";
			cin>>a;
			c = calc.Sine(a);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_COSINE:
			cout<<"\na = ";
			cin>>a;
			c = calc.Cosine(a);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_TANGENT:
			cout<<"\na = ";
			cin>>a;
			c = calc.Tangent(a);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_SINE:
			cout<<"\na = ";
			cin>>a;
			c = calc.InverseSine(a);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_INVCOSINE:
			cout<<"\na = ";
			cin>>a;
			c = calc.InverseCosine(a);
			cout<<"\nresult = "<<c;
			break;
		case CALC_OPTION_INVTANGENT:
			cout<<"\na = ";
			cin>>a;
			c = calc.InverseTangent(a);
			cout<<"\nresult = "<<c;
			break;
    default:
      /* Back to the main menu. */
      break;
		}
    
    cout<<"\n";
    
	} while (op != CALC_OPTION_EXIT);
}
