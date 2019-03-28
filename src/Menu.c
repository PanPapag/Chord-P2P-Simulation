#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../Headers/ChordInterface.h"
#include "../Headers/Menu.h"
#include "../Headers/Util.h"

int menu(void) {
    int option;

    printf("\n------------------------------------------------------\n\t\t      Chord Menu\n------------------------------------------------------\n");
    printf("1.\tConstruct a Chord network giving an input file\n");
    printf("2.\tInsert an element\n");
    printf("3.\tSearch for an element with key\n");
    printf("0.\tQuit\n\n");
    printf("Q: Make your selection: ");

    while( (scanf(" %d", &option) != 1) /* non-numeric input */
          || (option < 0)               /* number too small */
          || (option > 8))              /* number too large */
    {
      fflush(stdin);                    /* clear bad data from buffer */
      printf("INFO: That selection isn't valid. Please try again.\n\n");
      printf("Q: Your choice? ");
    }
    printf("------------------------------------------------------\n");
    return option;
}

int menu_initialize(void) {
  if(initialize())
     return VALID;
  else
    return ERROR;
}


void menu_quit(void) {
    printf("INFO: Quiting...Bye!\n");
    fflush(stdin);   /* clear bad data from buffer */
    exit(0);
}

/*read the name of a file and store it in the string array user_filename */
void menu_get_input_file(char * user_filename) {
  printf("Q: Enter the filename of the input file: ");
  scanf("%s", user_filename);
  printf("\n");
}

void menu_insert_from_file(char * user_filename) {
 FILE *file=fopen(user_filename, "r");
 if (!file) {
   printf("ERROR: Error opening the file %s !\n",user_filename);
   return;
 }
 else {
   GenerateChord(file);
 }
}

int menu_insert(void) {
  int node_id;
  nodeType *node;
  keyType  key;
  valueType value;

  node = Select();
  if (node == NULL) {
    fprintf(stderr,"INFO: ERROR! Chord network has no nodes connected\n");
    return ERROR;
  }
  /*Allocate memory for key and value */
  key = malloc((MAXLEN+1) * sizeof(keyType));
  value = malloc((MAXLEN+1) * sizeof(valueType));
  /*Read key and value */
  printf("Q: Enter the key: ");
  scanf("%s",key);
  printf("\n");
  printf("Q: Enter the value: ");
  scanf("%s",value);
  printf("\n");

  insert(node,key,value);
  /* Deallocate memory */
  free(key);
  free(value);

  return 1;
}

int menu_search(void) {
  int choice;
  double time_taken;
  nodeType *node;
  valueType value;
  keyType key;

  do {
    choice = search_options();
    switch(choice) {
      case LOOKUP:

          node = Select();
          if(node == NULL) {
            fprintf(stderr,"INFO: ERROR! Chord network has no nodes connected\n");
            return ERROR;
          }

          /*Allocate memory for key and value */
          key = malloc((MAXLEN+1) * sizeof(keyType));
          value = malloc((MAXLEN+1) * sizeof(valueType));

          printf("\nQ: Enter the key: ");
          scanf("%s",key);
          printf("\n");

          clock_t t;
          t = clock();
          //copy value of the key in the string value //
          strcpy(value,lookup(node,key));
          t = clock() - t;
          time_taken = ((double)t)/CLOCKS_PER_SEC;

          printf("Giving the key '%s' the correspodent value is: %s\n",key,value);
          printf("Lookup took %f seconds to execute \n", time_taken);
          /* Deallocate memory */
          free(value);
          free(key);
          break;
      case SMARTLOOKUP:
          node = Select();
          if(node == NULL) {
            fprintf(stderr,"INFO: ERROR! Chord network has no nodes connected\n");
            return ERROR;
          }

          /*Allocate memory for key and value */
          key = malloc((MAXLEN+1) * sizeof(keyType));
          value = malloc((MAXLEN+1) * sizeof(valueType));

          printf("\nQ: Enter the key: ");
          scanf("%s",key);
          printf("\n");

          t = clock();
          //copy value of the key in the string value //
          strcpy(value,smartLookup(node,key));
          t = clock() - t;
          time_taken = ((double)t)/CLOCKS_PER_SEC;

          printf("Giving the key '%s' the correspodent value is: %s\n",key,value);
          printf("Smart Lookup took %f seconds to execute \n", time_taken);
          /* Deallocate memory */
          free(value);
          free(key);
          break;
      default:
          printf("\nINFO: Bad input.\n");
          printf("INFO: Please try again.\n\n");
    }
  } while(choice != 1 && choice != 2 );

  return VALID;
}

int search_options(void) {
  int option;
  printf("1.Search using lookup algorithm\n");
  printf("2.Search using smart lookup algorithm\n");
  printf("\nQ: Make your selection: ");
  scanf("%d",&option);
  return option;
}
