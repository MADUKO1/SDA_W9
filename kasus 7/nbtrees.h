#ifndef nbtrees_h
#define nbtrees_h

#include "boolean.h"

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

// Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0

/***************************/
/* Type data */
/***************************/
typedef char infotype;
typedef int address;

typedef struct {
    infotype info;
    address ps_fs;  // posisi first son
    address ps_nb;  // posisi next brother
    address ps_pr;  // posisi parent
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

/***************************/
/* S P E S I F I K A S I */
/***************************/

// Konstruktor
void Create_tree(Isi_Tree X, int Jml_Node);

// Validasi
boolean IsEmpty(Isi_Tree P);

// Traversal
void PreOrder(Isi_Tree P, int root);
void InOrder(Isi_Tree P, int root);
void PostOrder(Isi_Tree P, int root);
void Level_order(Isi_Tree P, int Jml_Node);

// Utility
void PrintTree(Isi_Tree P);
boolean Search(Isi_Tree P, infotype X);
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype X);
int Depth(Isi_Tree P);
int Max(int Data1, int Data2);

#endif
