#ifndef __MENU__
#define __MENU__

#define ERROR 0
#define VALID 1
#define MAXNODENUMBER 8192
#define MAXLEN 100
#define LOOKUP 1
#define SMARTLOOKUP 2

void menu_get_input_file(char * user_filename);

void menu_insert_from_file(char * user_filename);

int menu_initialize(void);

int menu_insert(void);

int menu_search(void);

int search_options();

void menu_quit(void);

int menu(void);

#endif
