#include <stdio.h> 
#include <conio.h> /* getch () */

/* Macros: */
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

/* Variables globales: */
BOOLEAN acertado;
int posiciones_en_columna[8];
BOOLEAN reina_en_fila[8];
BOOLEAN reina_en_diagonal_normal[15];
BOOLEAN reina_en_diagonal_inversa[15];

#define c(i) posiciones_en_columna[(i) - 1]
/* rango de índice: 1..8 */

#define f(i) reina_en_fila[(i) - 1]
/* rango de índice: 1..8 */

#define dn(i) reina_en_diagonal_normal[(i) + 7]
/* rango de índice: -7..7 */

#define di(i) reina_en_diagonal_inversa[(i) - 2]
/* rango de índice: 2..16 */

/* Prototipos de las funciones: */
void proceso ();
void ensayar (int i);

void main ()
{
  printf("\n\nPROBLEMA DE LAS OCHO REINAS:\n ");
  proceso();
}

void proceso ()
{
  register int i, j;
  for (i = 1; i <= 8; i++)
    f(i) = TRUE;
  for (i = 2; i <= 16; i++)
    di(i) = TRUE;
  for (i = -7; i <= 7; i++)
    dn(i) = TRUE;
  ensayar(1);
  if (acertado)
  for (printf("\n\nLA SOLUCION ES:\n\n"), i = 1; i<= 8; i++)
  {
    for (j = 1;j< = 8;j++)
      printf("%2d", c(j) = i ? 1 : 0);
    printf ("\n");
  }
  else
    printf ("\n\nNO HAY SOLUCION.\n");
}

void ensayar(int i)
{
  int j = 0;
  do
  {
    j++;
    acertado = FALSE;
    if (f(j) && di(i+j) && dn(i-j))
    {
      c(i) = j;
      f(j) = di(i+j) = dn(i-j) = FALSE;
      if (i<8)
      {
        ensayar(i+1);
        if (!acertado)
          f(j) = di(i+j) = dn(i-j) = TRUE;
      }
      else
        acertado = TRUE;
    }
  } while (!acertado && j != 8);
}

