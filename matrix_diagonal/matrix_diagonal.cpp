/*
  matrix_diagonal.cpp

  Description:
    Programming exercise. C++
    This program prints a matrix to the standard output with a set of numbers
    in diagonal order.
*/

#include <iostream>

using std::cout;
using std::endl;

#define MAXROWS 10
#define MAXCOLS 4

int matrix[MAXCOLS][MAXROWS];

/*
  PrintMatrix
  Prints the matrix to the standard output.
*/
void PrintMatrix();

int main(void)
{
  int i, j;
  int start = 0, rownum = 0, curval, offset;

  /* For each column */
  for (i = 0; i < MAXCOLS; i++)
  {
    /* Increment the row number each iteration. */
    rownum++;
    /* The initial column value is incremented each iteration
     * (+1, +2, +3, ...) */
    start += rownum;
    curval = start;
    
    /* The offset goes from 0 to MAXCOLS, and it is incremented each row. */
    offset = i;

    /* For each row */
    for (j = 0; j < MAXROWS; j++)
    {
      /* Set the current value in the matrix. */
      matrix[i][j] = curval;

      /* Increment <offset> until it gets to MAXCOLS, to create the initial
       * diagonal. */
      if (j < (MAXCOLS - i))
        offset++;
      /* Decrement <offset> to create the final diagonal. */
      if (j >= (MAXROWS - 1 - i))
        offset--;

      curval += offset;
    }
  }

  PrintMatrix();

  return 0;
}

void PrintMatrix()
{
  int i, j;

  for (i = 0; i < MAXROWS; i++)
  {
    cout<<"\n\n\t";
    for (j = 0; j < MAXCOLS; j++)
      cout<<(matrix[j][i] < 10 ? " " : "")<<matrix[j][i]<<"  ";
  }
  cout<<endl<<endl;
}

