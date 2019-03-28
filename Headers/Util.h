#ifndef __UTIL__
#define __UTIL__

#define MAXLENNAME 4
#define MAXLEN 100

nodeType* Select(void);

nodeType* Successor(nodeType *,int);

int HashF(keyType);

void GenerateChord(FILE *);

nodeType *closestPrecedingNode(nodeType *,int);

nodeType *Fast_Successor(nodeType *,int id);

#endif
