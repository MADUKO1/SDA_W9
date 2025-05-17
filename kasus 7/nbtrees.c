#include <stdio.h>
#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    for (int i = 1; i <= Jml_Node; i++) {
        X[i].info = '\0';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
    }
}

boolean IsEmpty(Isi_Tree P) {
    return P[1].info == '\0';
}

void PreOrder(Isi_Tree P, int root) {
    if (root != 0) {
        printf("%c ", P[root].info);
        PreOrder(P, P[root].ps_fs);
        PreOrder(P, P[root].ps_nb);
    }
}

void InOrder(Isi_Tree P, int root) {
    if (root != 0) {
        InOrder(P, P[root].ps_fs);
        printf("%c ", P[root].info);
        InOrder(P, P[root].ps_nb);
    }
}

void PostOrder(Isi_Tree P, int root) {
    if (root != 0) {
        PostOrder(P, P[root].ps_fs);
        PostOrder(P, P[root].ps_nb);
        printf("%c ", P[root].info);
    }
}

void Level_order(Isi_Tree P, int Jml_Node) {
    for (int i = 1; i <= Jml_Node; i++) {
        if (P[i].info != '\0') {
            printf("%c ", P[i].info);
        }
    }
}

void PrintTree(Isi_Tree P) {
    printf("PreOrder   : ");
    PreOrder(P, 1);
    printf("\nInOrder    : ");
    InOrder(P, 1);
    printf("\nPostOrder  : ");
    PostOrder(P, 1);
    printf("\nLevelOrder : ");
    Level_order(P, jml_maks);
    printf("\n");
}

boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == 0) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0, idx = i;
            while (P[idx].ps_pr != 0) {
                level++;
                idx = P[idx].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    int maxLevel = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int level = Level(P, P[i].info);
            if (level > maxLevel) {
                maxLevel = level;
            }
        }
    }
    return maxLevel;
}

int Max(int Data1, int Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
