/*
  calculator.H

  Description:
    School project. C++
    Scientific calculator class definition.
*/

class Calculator
{
  public:
    Calculator();
    double Sum(const double a, const double b);
    double Subtraction(const double a, const double b);
    double Multiplication(const double a, const double b);
    double Division(const double a, const double b);
    double Percentage(const double a, const double b);
    double Power(const double a, const double b);
    double SquaredRoot(const double a);
    double Sine(const double a);
    double Cosine(const double a);
    double Tangent(const double a);
    double InverseSine(const double a);
    double InverseCosine(const double a);
    double InverseTangent(const double a);
    long   Factorial(const long a);
    double GeneralX1(double, double, double);
    double GeneralX2(double, double, double);

  private
    double pi;
};

Calculator::Calculator()
{
  pi = 3.1416;
}

double Calculator::Sum(const double a, const double b)
{
	return(a + b);
}

double Calculator::Subtraction(const double a, const double b)
{
	return(a - b);
}

double Calculator::Multiplication(const double a, const double b)
{
	return(a * b);
}

double Calculator::Division(const double a, const double b)
{
	return(a / b);
}

double Calculator::Percentage(const double a, const double b)
{
	return(a * (b / 100));
}

double Calculator::Power(const double a, const double b)
{
	return(pow(a, b));
}

double Calculator::SquaredRoot(const double a)
{
	return(sqrt(a));
}

double Calculator::Sine(const double a)
{
	return(sin((a * pi) / 180));
}

double Calculator::Cosine(const double a)
{
	return(cos((a * pi) / 180));
}

double Calculator::Tangent(const double a)
{
	return(tan((a * pi) / 180));
}

double Calculator::InverseSine(const double a)
{
	return((asin(a) * 180) / pi);
}

double Calculator::InverseCosine(const double a)
{
	return((acos(a) * 180) / pi);
}

double Calculator::InverseTangent(const double a)
{
	return((atan(a) * 180) / pi);
}

long Calculator::Factorial(const long a)
{
  long factor = 1;
  long i;

	for (i = 0; i < a; i++)
    factor = factor * (i + 1);

	return(factor);
}

double Calculator::GeneralX1(const double a, const double b, const double c)
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

double Calculator::GeneralX2(const double a, const double b, const double c)
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
