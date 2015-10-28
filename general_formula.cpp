/*
  general_formula.cpp

  Description:
    Programming exercise. C++
    Simple program that solves the general formula for quadratic equations.
*/

#include "stdio.h"
#include "math.h"

double GeneralX2(const double a, const double b, const double c);

double GeneralX1(const double a, const double b, const double c);

void main()
{
	double a, b, c, x1, x2;

  /* Get the user input. */
	printf("a = ");
	scanf("%f", &a);
	printf("\nb = ");
	scanf("%f", &b);
	printf("\nc = ");
	scanf("%f", &c);

  /* Print the results to the standard output. */
	x1 = GeneralX1(a, b, c);
	printf("x1 = %.4f\n", x1);

	x2 = GeneralX2(a, b, c);
	printf("x2 = %.4f\n", x2);
}

double GeneralX1(const double a, const double b, const double c)
{
  double x1;
	double d = pow(b, 2) - (4 * a * c);

	if (d < 0)
	{
		d = d * (-1);
		x1 = (b * -1) / (2 * a);
	}
	else
		x1 = ((b * -1) + sqrt(d)) / (2 * a);

	return(x1);
}

double GeneralX2(const double a, const double b, const double c)
{
  double x2;
	double d = pow(b, 2) - (4 * a * c);

	if (d < 0)
	{
		d = d * (-1);
		x2 = sqrt(d) / (2 * a);
	}
	else
		x2 = ((b * -1) - sqrt(d)) / (2 * a);

	return(x2);
}
