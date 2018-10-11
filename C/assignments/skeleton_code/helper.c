/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* helper.c contains all the helper methods for the shell
*
******************************************************************************/

#include "helper.h"

/******************************************************************************
* prints the device's username
******************************************************************************/
void print_user()
{
	printf("%s> ", getenv("USER"));
}

/******************************************************************************
* gets character
******************************************************************************/
char getch(FILE *fp)
{
	if (fp != NULL)
	{
		return fgetc(fp);
	}

	system("stty -echo");
	system("stty -icanon");
	char ch = getchar();
	system("stty sane");
  	return ch;
}

/******************************************************************************
* deletes the current character.
******************************************************************************/
void delete(int len, char* line)
{
	line[len] = '\0';
	printf("\b \b");
}

/******************************************************************************
* Determines which special character is processed.
******************************************************************************/
char switch_keypad(char ch)
{
	switch(ch)
	{
		case 'A': return KEYUP;
		case 'B': return KEYDOWN;
		case 'C': return KEYRIGHT;
		case 'D': return KEYLEFT;
		default:  return ch;
	}
}

/******************************************************************************
 * tokenize each line
 *****************************************************************************/
char **tokenize(char *line)
{
  int bufsize = 64, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, " \t\r\n\a");
  while (token != NULL) {
    tokens[position] = token;
    position++;

      if(position >= bufsize) {
        bufsize += 64;
        tokens = realloc(tokens, bufsize * sizeof(char*));
        if (!tokens) {
          fprintf(stderr, "allocation error\n");
          exit(EXIT_FAILURE);
        }
      }
    token = strtok(NULL, " \t\r\n\a");
  }
  tokens[position] = NULL;
  return tokens;
}

