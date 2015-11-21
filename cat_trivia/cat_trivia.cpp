/*
  cat_trivia.cpp

  Description:
    Programming exercise. C++
    Displays the user a set of 10 random multiple-choice questions about cats,
    if the user can answer the question correctly it gets 1 point. At the end
    it shows the final score.
    The entire set of questions are written to a file and then 10 random
    questions are read from the file to present them to the user. This exercise
    demonstrates how to open/close/read/write files using the FILE data type.
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define FILE_NAME "tempfile.txt"

/*
  Represents a multiple-choice question.
*/
struct trivia
{
  /* Null-terminated string with the question. */
  char question[100];
  /* Null-terminated string with option #1. */
  char option1[50];
  /* Null-terminated string with option #2. */
  char option2[50];
  /* Null-terminated string with option #3. */
  char option3[50];
  /* Correct answer (1, 2, or */
  int  correct_answer;
};

/*
  build_dataset

  Writes a set of 22 questions to the temporary file.
*/
int build_dataset();

/*
  ask_one
  
  Retrieves the specified question from the temporary file containing
  all interview questions. Prints the multiple-option question to the
  standard output and asks the user for an answer. If the user answers
  correctly, returns TRUE; otherwise returns FALSE.
*/
bool ask_one(const int question_num);

int main(void)
{
/* Number of questions asked each time this program is executed. */
#define QUESTIONNAIRE_SIZE 10

  int question_num;
  int score = 0, i;
  
  /* Write the entire set of questions. */
  if (build_dataset())
    return -1;
  
  /* Print instructions to the standard output. */
  printf("-*-*-*-*-*-*WELCOME*-*-*-*-*-*-\n\n");
  printf("Answer the following %d questions by typing the number that ",
         QUESTIONNAIRE_SIZE);
  printf("corresponds to the correct answer.\n");

  /* Ask the user 10 random questions out of the data set. */
  for (i = 0; i < QUESTIONNAIRE_SIZE; i++)
  {
    question_num = rand() % 23;
    if (ask_one(question_num))
      score++;
  }

  /* Print the final score. */
  printf("\n---*---*--- Final score: %d/%d ---*---*---\n\n",
         score, QUESTIONNAIRE_SIZE);

  return 0;
}

int build_dataset()
{
  FILE *output_file;
  struct trivia mytrivia;

  /* Open the file for writing. */
  output_file = fopen(FILE_NAME, "w");
  if (!output_file)
  {
    printf("Failed to open file: %s\n", FILE_NAME);
    return -1;
  }
  
  strcpy(mytrivia.question, (const char *)"Pais que considera a los gatos como dioses");
  strcpy(mytrivia.option1, (const char *)"Mexico");
  strcpy(mytrivia.option2, (const char *)"Egipto");
  strcpy(mytrivia.option3, (const char *)"Grecia");
  mytrivia.correct_answer = 2;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Principal caracteristica del gato persa");
  strcpy(mytrivia.option1, (const char *)"Pelo largo");
  strcpy(mytrivia.option2, (const char *)"Pelo mas oscuro en las patas, cola y cabeza");
  strcpy(mytrivia.option3, (const char *)"Cabeza bien definida");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Por que los gatos siempre caen de pie?");
  strcpy(mytrivia.option1, (const char *)"Por miedo a las alturas");
  strcpy(mytrivia.option2, (const char *)"Saben que no es bueno car de espalda");
  strcpy(mytrivia.option3, (const char *)"Tratan de encontar su punto de gravedad");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Es verdad que los gatos siempre recuerdan el camino a casa?");
  strcpy(mytrivia.option1, (const char *)"No");
  strcpy(mytrivia.option2, (const char *)"Si");
  strcpy(mytrivia.option3, (const char *)"Cada caso es diferente");
  mytrivia.correct_answer = 2;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"En que casos es conveniente cortarle las unas a un gato?");
  strcpy(mytrivia.option1, (const char *)"Cada ves que les crecen");
  strcpy(mytrivia.option2, (const char *)"Al nacer");
  strcpy(mytrivia.option3, (const char *)"Solo en casos realmente necesarios");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Cual es la manera de lograr que un gato te preste su atencion?");
  strcpy(mytrivia.option1, (const char *)"Comportandote como el espera");
  strcpy(mytrivia.option2, (const char *)"Llamandolo por su nombre");
  strcpy(mytrivia.option3, (const char *)"Con un juguete en la mano");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Como puedes descubrir rapidamente el estado de animo de un gato");
  strcpy(mytrivia.option1, (const char *)"Observando sus gestos y posicion");
  strcpy(mytrivia.option2, (const char *)"Dilatacion de sus pupilas");
  strcpy(mytrivia.option3, (const char *)"Agudez del maullido");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Que significa el ronrroneo de un gato?");
  strcpy(mytrivia.option1, (const char *)"Que esta enfermo");
  strcpy(mytrivia.option2, (const char *)"Malestar, no que este sano");
  strcpy(mytrivia.option3, (const char *)"Bienestar y buena salud");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Que genera el comportamiento de miedo y defensa en un gato?");
  strcpy(mytrivia.option1, (const char *)"Celos");
  strcpy(mytrivia.option2, (const char *)"La presencia de otros gatos");
  strcpy(mytrivia.option3, (const char *)"Mala actitud en las personas");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Por que le brillan los ojos a los gatos en la oscuridad?");
  strcpy(mytrivia.option1, (const char *)"Por grasas acumuladas");
  strcpy(mytrivia.option2, (const char *)"Funcionan como espejos");
  strcpy(mytrivia.option3, (const char *)"Tinenen brillo propio");
  mytrivia.correct_answer = 2;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Enfermedad que adquiere un gato por consumir grandes cantidades de higado");
  strcpy(mytrivia.option1, (const char *)"Anemia");
  strcpy(mytrivia.option2, (const char *)"Osteoporosis");
  strcpy(mytrivia.option3, (const char *)"Melatitis");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Unas probadas de chocolate pueden matar a un gato?");
  strcpy(mytrivia.option1, (const char *)"No");
  strcpy(mytrivia.option2, (const char *)"Si");
  strcpy(mytrivia.option3, (const char *)"Algunas veces");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Se le puede dar alcohol a un gato?");
  strcpy(mytrivia.option1, (const char *)"No, nunca");
  strcpy(mytrivia.option2, (const char *)"Solo en pequenas cantidades");
  strcpy(mytrivia.option3, (const char *)"Si");
  mytrivia.correct_answer = 2;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Como se les llama a los gatos sin pelo?");
  strcpy(mytrivia.option1, (const char *)"Feos");
  strcpy(mytrivia.option2, (const char *)"Leucemicos");
  strcpy(mytrivia.option3, (const char *)"Esfinge");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"De que sirve cepillar a un gato?");
  strcpy(mytrivia.option1, (const char *)"Para quitarles el pelo suelto");
  strcpy(mytrivia.option2, (const char *)"Que no esten despeinados");
  strcpy(mytrivia.option3, (const char *)"Les gusta");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Como se limpian los gatos?");
  strcpy(mytrivia.option1, (const char *)"Con un trapo humedo");
  strcpy(mytrivia.option2, (const char *)"Con su propia lengua");
  strcpy(mytrivia.option3, (const char *)"Con cuidado");
  mytrivia.correct_answer = 2;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Cuando crece y se desarrolla un gato?");
  strcpy(mytrivia.option1, (const char *)"Cuando come");
  strcpy(mytrivia.option2, (const char *)"Cuando juega");
  strcpy(mytrivia.option3, (const char *)"En su primer ano de vida");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Como logras que un gato no le tenga miedo a la gente?");
  strcpy(mytrivia.option1, (const char *)"Si desde pequeno se acostumbra a la gente");
  strcpy(mytrivia.option2, (const char *)"Si lo lanzas al aire");
  strcpy(mytrivia.option3, (const char *)"Si lo golpeas");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Por que se porta mal un gato?");
  strcpy(mytrivia.option1, (const char *)"Porque quiere jugar");
  strcpy(mytrivia.option2, (const char *)"Porque es un maleducado");
  strcpy(mytrivia.option3, (const char *)"Porque tiene sueno");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Cada cuendo se cepilla un gato de pelo largo?");
  strcpy(mytrivia.option1, (const char *)"Cada dos horas");
  strcpy(mytrivia.option2, (const char *)"Todos los miercoles");
  strcpy(mytrivia.option3, (const char *)"Diario");
  mytrivia.correct_answer = 3;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Cada cuando se cepilla un gato de pelo corto?");
  strcpy(mytrivia.option1, (const char *)"Tres veces por semana");
  strcpy(mytrivia.option2, (const char *)"Cada mes");
  strcpy(mytrivia.option3, (const char *)"Todos los jueves");
  mytrivia.correct_answer = 1;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

  strcpy(mytrivia.question, (const char *)"Los gatos duermen siestas?");
  strcpy(mytrivia.option1, (const char *)"Nunca duermen");
  strcpy(mytrivia.option2, (const char *)"Si");
  strcpy(mytrivia.option3, (const char *)"Un poquito y en veces");
  mytrivia.correct_answer = 2;
  fwrite(&mytrivia, sizeof(struct trivia), 1, output_file);

   /* Close the file descriptor. */
  fclose(output_file);

  return 0;
}

bool ask_one(const int question_num)
{
  FILE *input_file;
  struct trivia mytrivia;
  int answer;
  
  /* Open the input file for reading. */
  input_file = fopen(FILE_NAME, "r");
  if (!input_file)
  {
    printf("Failed to open file: %s\n", FILE_NAME);
    return false;
  }

  /* Read the requested question from the input file. */
  fseek(input_file, question_num * sizeof(struct trivia), SEEK_SET);
  fread(&mytrivia, sizeof(struct trivia), 1, input_file);
    
  /* Close the file descriptor. */
  fclose(input_file);
  
  /* Print the question to the standard output. */
  printf("\n%s\n1) %s\n2) %s\n3) %s\nAnswer: ", mytrivia.question,
         mytrivia.option1, mytrivia.option2, mytrivia.option3);

  /* Get the answer from the user. */
  scanf("%d", &answer);

  return !!(answer == mytrivia.correct_answer);
}
