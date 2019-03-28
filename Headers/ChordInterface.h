#ifndef __CHORDINTERFACE__
#define __CHORDINTERFACE__

#include "ChordTypes.h"

int CreateNode(int);

void Fix_fingertable();

void InsertRing(nodeType *);

void InsertAfter(nodeType *,nodeType *);

void PrintRing();

void InsertBefore(nodeType *,nodeType *);

int initialize(void);

void insert(nodeType*,keyType,valueType);

valueType lookup(nodeType*,keyType);

valueType smartLookup(nodeType*,keyType);

#endif
