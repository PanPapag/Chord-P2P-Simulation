#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/Menu.h"

#define CHORDCONSTRUCTION 1
#define INSERT 2
#define SEARCH 3
#define QUIT 0

int main(void)
{ int choice,pos,on,off;
  char user_filename[100];

  if(!menu_initialize()){
    printf("INFO: ERROR! Quiting...\n");
    fflush(stdin);
    exit(0);
  }
  /* get user's first selection */
  choice = menu();

  while(choice != QUIT){
      switch(choice){
        case CHORDCONSTRUCTION:
            menu_get_input_file(user_filename);
            menu_insert_from_file(user_filename);
            break;
        case INSERT:
            if (menu_insert())
              printf("INFO: Key inserted successfully.\n");
            break;
        case SEARCH:
            menu_search();
            break;
        default:
            printf("INFO: Bad input.\n");
            printf("INFO: Please try again.\n");
      }
      /* get user's subsequent selections */
      choice = menu();
  }
  /* exit, destroy structures */
  menu_quit();
}
