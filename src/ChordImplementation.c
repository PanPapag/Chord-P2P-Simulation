#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../Headers/ChordInterface.h"
#include "../Headers/Util.h"

Ring *ChordRing;

/*Allocate memomy for the ChordRing*/
int initialize(void) {
  if ((ChordRing = malloc(sizeof(Ring)) ) == NULL ) {
    fprintf(stderr, "INFO: ERROR! Fail in allocated memomy for the Chord Ring\n");
    return 0;
  }
  ChordRing->size = 0;
  ChordRing->firstnode = NULL;
  ChordRing->lastnode = NULL;
  return 1;
}

void insert(nodeType *node, keyType key, valueType value) {
  int id;
  nodeType *suc_node;
  // extract the id of the key through hash function //
  id = HashF(key);
  suc_node = Successor(node,id);
  //Allocate memmory//
  suc_node->key = malloc(MAXLEN * sizeof(keyType));
  suc_node->value = malloc(MAXLEN * sizeof(valueType));
  //Store pair <key,node> //
  strcpy(suc_node->key,key);
  strcpy(suc_node->value,value);
}

valueType lookup(nodeType *node,keyType key) {
  int id;
  nodeType *suc_node;
  // extract the id of the key through hash function //
  id = HashF(key);
  suc_node = Successor(node,id);

  return suc_node->value;

}

valueType smartLookup(nodeType *node,keyType key){
  int id;
  nodeType *suc_node;
  // extract the id of the key through hash function //
  id = HashF(key);
  suc_node = Fast_Successor(node,id);

  return suc_node->value;
}

int CreateNode(int id) {
  nodeType *node;

  if ((node = malloc(sizeof(nodeType)) ) == NULL ){
    fprintf(stderr, "Fail in allocated memomy for a node in the Chord Ring\n");
    return 0;
  }
  else { 
    node->id = id;              // save node id in the proper field //
    ChordRing->size++;          // with each node being added in the chord ring increase its size by 1 //
    InsertRing(node);           // Insert node in the Chord Ring //
  }
  return 1;
}
/* Function to adjust the finger_table for each node of Chord Ring */
void Fix_fingertable(void) {
  int id;
  nodeType *suc_node, *start_node, *current;

  start_node = Select();
  current = Select();

  while (current != NULL) {
    for(int i = 0; i < M; i++) {
      id = current->id + pow(2,i);
      //bear in mind the cyclic property of Chord Ring//
      if (id >= MAXNODENUMBER)
        id = id - ChordRing->size;
      //Find its successor //
      suc_node = Successor(start_node,id);
      current->finger_table[i] = suc_node;
    }
    current = current->successor;
  }
}

void InsertRing(nodeType *node) {
  nodeType *current;
  /* if Chord Ring is empty do as following */
  if (ChordRing->firstnode == NULL) {
    node->predecessor = NULL;
    node->successor = NULL;
    ChordRing->firstnode = node;
    ChordRing->lastnode = node;
  }
  // in other case insert the node in the right position of the ring //
  else {
    current = ChordRing->firstnode;
    while (current != NULL) {
      // if we are in the end //
      if (current->successor == NULL) {
        if (node->id > current->id )
          InsertAfter(current,node);
        else if (node->id < current->id )
          InsertBefore(current,node);
        break;
      }
      else {
        if ((node->id > current->id) && (node->id < current->successor->id)) {
          InsertAfter(current,node);
          break;
        }
        else if ((node->id < current->id) && ((current->predecessor == NULL) || (node->id > current->predecessor->id))){
          InsertBefore(current,node);
          break;
        }
      }
      current = current->successor;
    }
    // Update first and last node if neccessary //
    if (node->id < ChordRing->firstnode->id)
      ChordRing->firstnode = node;
    else if (node->id > ChordRing->lastnode->id)
      ChordRing->lastnode = node;
  }
}

void InsertAfter(nodeType *current, nodeType *node) {
  node->predecessor = current;
  node->successor = current->successor;
  if (current->successor == NULL)
    ChordRing->lastnode = node;
  else
    current->successor->predecessor = current;
  current->successor = node;
}

void InsertBefore(nodeType *current, nodeType *node) {
  node->predecessor = current->predecessor;
  node->successor = current;
  if (current->predecessor == NULL)
    ChordRing->firstnode = node;
  else
    current->predecessor->successor = current;
  current->predecessor = node;
}

void PrintRing() {
  nodeType *current;
  current = ChordRing->firstnode;
  while (current!=NULL){
    printf("id: %d\n",current->id);
    current = current->successor;
  }
}
