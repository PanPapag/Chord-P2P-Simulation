#ifndef __CHORDTYPES__
#define __CHORDTYPES__

#define MAXNODENUMBER 8192
#define M 13    // M = LOG(MAXNODENUMBER);

typedef char* keyType;
typedef char* valueType;


typedef struct Node{
  int id;
  keyType key;
  valueType value;
  struct Node *finger_table[M];
  struct Node *predecessor;
  struct Node *successor;
}nodeType;

typedef struct ring{
  int size;
  nodeType *firstnode;
  nodeType *lastnode;
}Ring;

#endif
