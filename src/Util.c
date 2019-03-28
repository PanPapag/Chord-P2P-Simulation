#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../Headers/ChordInterface.h"
#include "../Headers/Util.h"

extern Ring *ChordRing;

nodeType *Select(void) {
  return ChordRing->firstnode;
}
/* A good hash function for strings */
int HashF(keyType key) {
  int h = 0, a = 127;
  for (; *key!='\0'; key++)
    h = (a*h + *key) % MAXNODENUMBER;

  return h;
}

/* Function to create a chord ring via a input file */
void GenerateChord(FILE *file) {
  char name[MAXLENNAME];
  int id;
  while (fscanf(file, "%s",name) != EOF ) {
    id = HashF(name);
    if(!CreateNode(id))
      return;
  }
  Fix_fingertable();
  printf("INFO: Chord network was constructed successfully\n");
  printf("INFO: Chord network consists of %d nodes\n",ChordRing->size);

}

/*Function to find the successor of a node */
nodeType *Successor(nodeType *node,int id) {
  if (node->predecessor != NULL && (id > node->predecessor->id && id <= node->id))
    return node;
  else if (id > node->id && id <= node->successor->id)
    return node->successor;
  else
    return Successor(node->successor,id);

}

/*Function to find the successor of a node using finger table */
nodeType *Fast_Successor(nodeType *node,int id) {
  if (node->predecessor != NULL && (id > node->predecessor->id && id <= node->id))
    return node;
  else if (id > node->id && id <= node->successor->id)
    return node->successor;
  else {
      nodeType *pnode = closestPrecedingNode(node,id);
      return Fast_Successor(pnode,id);
  }
}

nodeType *closestPrecedingNode(nodeType *node,int id) {
  for (int i = M - 1; i >= 0; i--){
    if ((node->finger_table[i]->id > node->id) && (node->finger_table[i]->id < id))
      return node->finger_table[i];
  }
}
