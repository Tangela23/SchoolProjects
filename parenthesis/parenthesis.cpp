/*
  parenthesis.cpp

  Description:
  Programming exercise. C++

  Evaluates a logical expression composed of parenthesis and squared brackets
  to determine if all open parenthesis and squared brackets are closed in
  order.

  It keeps track of the open and close parenthesis and squared brackets using
  an integer array as a stack.

  Ana Laura Solis Gomez --Laura (2)
  posorge Valencia
  Luis Eduardo Reynoso
*/

#include <iostream>
#include "string.h"

using std::cout;
using std::cin;
using std::endl;

#define EXPRESSION_MAXLEN 50
#define EXPRESSION_PARENTHESIS 1
#define EXPRESSION_BRACKET     2

int main (void)
{
  /* Input expression to evaluate */
  char expression[EXPRESSION_MAXLEN];
  /* Expression length */
  int len;
  /* Integer array to be used as a stack of the parenthesis and squared
   * brackets encountered while evaluating the expression */
  int stack[EXPRESSION_MAXLEN];
  /* Current position in the stack */
  int pos = 0;
  /* Count of open, unclosed squared brackets during evaluation */
  int brackets = 0;
  /* Count of open, unclosed parenthesis during evaluation */
  int parenthesis = 0;
  int i = 0;

  cout<<"Expression: ";
  
  cin.getline(expression, EXPRESSION_MAXLEN);
  len = strlen(expression);

  for (i = 0; i < len; i++)
  {
    if (expression[i] == '(')
    {
      parenthesis++;
      stack[++pos] = EXPRESSION_PARENTHESIS;
    }

    if (expression[i] == ')')
    {
      /* When a close parenthesis is found, decrement the number of open
       * parenthesis and pop the last parenthesis from the stack. If there
       * is not an open parenthesis in the stack, the expression is invalid. */
      if (stack[pos--] != EXPRESSION_PARENTHESIS)
        break;
      parenthesis--;
    }

    if (expression[i] == '[')
    {
      brackets++;
      stack[++pos] = EXPRESSION_BRACKET;
    }

    if (expression[i] == ']')
    {
      if (stack[pos--] != EXPRESSION_BRACKET)
        break;
      brackets--;
    }
  }

  if (parenthesis == 0 && brackets == 0)
    cout<<"The expression is valid."<<endl;
  else
    cout<<"The expression is invalid."<<endl;

  return 0;
}
