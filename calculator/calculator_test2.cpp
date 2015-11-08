/*
  calculator_test2.cpp

  Description:
    School project. C++
    Simple program that solves the general formula for quadratic equations or a factorial.
*/

#include <iostream.h>
#include <math.h>
#include "calculator.H"

#define CALC2_OPTION_FACTORIAL      ((int)1)
#define CALC2_OPTION_GENERALFORMULA ((int)2)
#define CALC2_OPTION_EXIT           ((int)3)

void main()
{
  int op;
  double a, b, c;
  double x1, x2;
  Calculator calc;

	do
  {
    /* Print the menu. */
    cout<<"\n\tSCIENTIFIC CALCULATOR SIMULATOR\n"
			<<" 1) Factorial\n"
			<<" 2) General formula for quadratic equations\n"
			<<" 3) Exit\n"
			<<"Choose one operation:";
    
    /* Get the user input. */
		cin>>op;
    
    /* Execute the operation selected by the user. */
		switch (op)
		{
		case CALC2_OPTION_FACTORIAL:
			cout<<"\na = ";
			cin>>a;
			c = calc.Factorial(a);
			cout<<"\nresult = "<<c;
			break;
		case CALC2_OPTION_GENERALFORMULA:
			cout<<"\na = ";
			cin>>a;
			cout<<"\nb = ";
			cin>>b;
			cout<<"\nc = ";
			cin>>c;
			if ((pow(b, 2) - (4 * a * c)) >= 0)
			{
				x1 = calc.GeneralX1(a, b, c);
				x2 = calc.GeneralX2(a, b, c);
			cout<<"\nx1 = "<<x1;
			cout<<"\nx2 = "<<x2;
			}
			else
			{
				x1 = calc.GeneralX1(a, b, c);
				x2 = calc.GeneralX2(a, b, c);
				cout<<"\nx1 = "
					<<x1<<" + "
					<<x2<<"i";
				cout<<"\nx2 = "
					<<x1<<" - "
					<<x2<<"i";
			}
			break;
    default:
      /* Back to the main menu. */
      break;
		}
    
    cout<<"\n";
    
	} while (op != CALC2_OPTION_EXIT);
}
