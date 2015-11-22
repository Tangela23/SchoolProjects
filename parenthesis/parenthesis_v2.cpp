/*
  parenthesis_v2.cpp

  Description:
  School project. C++

  Evaluates a logical expression that consists of numerical operations and
  parenthesis to produce the result of that operation or determine that the
  expression is invalid (malformed).

  It uses a stack to keep track of the tokens in the expression and evaluate
  the order of the operands.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
  closed_parenthesis

  Description:
  Evaluates the expression when a closing parenthesis is found. If the
  expression is valid, there will be a single number or an open parenthesis
  at the rop of the stack.
*/
int closed_parenthesis();

/*
  process_number

  Description:
  Evaluates the expression when the given number if found. If there is a
  sign at the top of the stack, performs the operation against the previous
  number and pushes the result into the stack.
*/
int process_number(int number);

/* Helper structure to describe the tokens in the expression. */
struct token
{
  int type;
#define TOKENTYPE_PARENTHESIS  ((int)0)
#define TOKENTYPE_SIGN         ((int)1)
#define TOKENTYPE_NUMBER       ((int)2)
  char parenthesis;
  char sign;
  float number;
};

/* Stack of tokens used for evaluating the expression. */
stack <token> mystack;

int main(void)
{
  char c;
  int i;
  bool isvalid = true;
  float result;

  /* Array of tokens in the input expression */
  token tokens[50];
  /* Count of tokens in the espression */
  int token_cnt = 0;

  /* Read the whole expression from console and fill the array of tokens. */
  cout<<"Expression: ";
  while (cin.get(c) && c != '\n')
  {
    if (c == '(' || c == ')')
    {
      tokens[token_cnt].type = TOKENTYPE_PARENTHESIS;
      tokens[token_cnt++].parenthesis = c;
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/')
    {
      tokens[token_cnt].type = TOKENTYPE_SIGN;
      tokens[token_cnt++].sign = c;
    }
    else if (c >= 48 && c < 58)
    {
      tokens[token_cnt].type = TOKENTYPE_NUMBER;
      tokens[token_cnt++].number = c - '0';
    }
  }

  /* Process each token in the array */
  for (i = 0; i < token_cnt; i ++)
  {
    if (tokens[i].type == TOKENTYPE_PARENTHESIS)
    {
      if (tokens[i].parenthesis == '(')
      {
        /* Push all open parenthesis into the stack */
        mystack.push(tokens[i]);
      }
      else if (tokens[i].parenthesis == ')')
      {
        /* Validate the stack when a close parenthesis is found */
        if (closed_parenthesis())
        {
          /* The expression is invalid. */
          isvalid = false;
          break;
        }
      }
    }
    else if (tokens[i].type == TOKENTYPE_SIGN)
    {
      /* Push all signs into the stack */
      mystack.push(tokens[i]);
    }
    else if (tokens[i].type == TOKENTYPE_NUMBER)
    {
      /* Process the numbers */
      if (process_number(tokens[i].number))
      {
        /* The expression is invalid. */
        isvalid = false;
        break;
      }
    }
  }

  if (isvalid && !mystack.empty() && mystack.top().type == TOKENTYPE_NUMBER)
  {
    result = mystack.top().number;
    mystack.pop();

    /* If there were unclosed parenthesis, the expression is invalid. */
    if (!mystack.empty())
      isvalid = false;
  }
  else
    isvalid = false;

  if (isvalid)
    cout<<"Result: "<<result<<endl;
  else
    cout<<"The expression is invalid."<<endl;

  return 0;
}

int closed_parenthesis()
{
  int number;

  if (mystack.top().type == TOKENTYPE_NUMBER)
  {
    /* If there is a number prior to this close parenthesis, it is expected to
     * be the only token inside the parenthesis, i.e. '( number )', remove the
     * opening parenthesis and process the number alone. */
    number = mystack.top().number;
    mystack.pop();

    if (mystack.top().type == TOKENTYPE_PARENTHESIS && mystack.top().parenthesis == '(')
    {
      mystack.pop();

      process_number(number);
    }
    else
    {
      /* Otherwise, the expression is invalid. */
      return -1;
    }
  }
  else if (mystack.top().type == TOKENTYPE_PARENTHESIS && mystack.top().parenthesis == '(')
  {
    /* If there is an open parenthesis prior to this close parenthesis,
     * i.e. '( )', simply remove it from the stack. */
    mystack.pop();
  }
  else
  {
    /* Otherwise, the expression is invalid. */
    return -1;
  }

  return 0;
}

int process_number(int number)
{
  token mytoken;
  char sign;
  int numA;
  int result = 0;

  if (mystack.empty() ||
      (mystack.top().type == TOKENTYPE_PARENTHESIS && mystack.top().parenthesis == '('))
  {
    /* If the stack is empty or it has an open parenthesis, simply add the
     * number to the stack. */
    mytoken.type = TOKENTYPE_NUMBER;
    mytoken.number = number;
    mystack.push(mytoken);
  }
  else if (mystack.top().type == TOKENTYPE_SIGN)
  {
    /* If there is a sign at the top of the stack, perform the operation and
     * push the result into the stack. */
    sign = mystack.top().sign;
    mystack.pop();

    /* There must be another number prior to the sign, otherwise the
     * expression is invalid. */
    if (mystack.top().type != TOKENTYPE_NUMBER)
    {
      return -1;
    }

    numA = mystack.top().number;
    mystack.pop();

    switch (sign)
    {
      case '+': result = numA + number; break;
      case '-': result = numA - number; break;
      case '*': result = numA * number; break;
      case '/': result = numA / number; break;
    }

    /* Process the result of this operation. */
    process_number(result);
  }

  return 0;
}

