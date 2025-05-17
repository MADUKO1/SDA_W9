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

void MenuPreOrder(Isi_Tree tree) {
    printf("PreOrder: ");
    PreOrder(tree, 1);
    printf("\n");
}

void MenuInOrder(Isi_Tree tree) {
    printf("InOrder: ");
    InOrder(tree, 1);
    printf("\n");
}

void MenuPostOrder(Isi_Tree tree) {
    printf("PostOrder: ");
    PostOrder(tree, 1);
    printf("\n");
}

void MenuLevelOrder(Isi_Tree tree) {
    printf("Level Order: ");
    Level_order(tree, jml_maks);
    printf("\n");
}

void MenuPrintTree(Isi_Tree tree) {
    for (int i = 1; i <= jml_maks; i++) {
        if (tree[i].info != '\0') {
            printf("\n--> Indeks ke-%d\n", i);
            printf("-------------------------------\n");
            printf("info array ke %d        : %c\n", i, tree[i].info);
            printf("first son array ke %d   : %d\n", i, tree[i].ps_fs);
            printf("next brother array ke %d: %d\n", i, tree[i].ps_nb);
            printf("parent array ke %d      : %d\n", i, tree[i].ps_pr);
        }
    }
}

void MenuSearch(Isi_Tree tree) {
    char cari;
    printf("Masukkan node yang dicari: ");
    scanf(" %c", &cari);
    if (Search(tree, cari))
        printf("Node %c ditemukan.\n", cari);
    else
        printf("Node %c tidak ditemukan.\n", cari);
}

void MenuJumlahDaun(Isi_Tree tree) {
    printf("Jumlah daun/leaf: %d\n", nbDaun(tree));
}

void MenuCariLevel(Isi_Tree tree) {
    char node;
    printf("Masukkan node: ");
    scanf(" %c", &node);
    int lvl = Level(tree, node);
    if (lvl != -1)
        printf("Level dari node %c adalah: %d\n", node, lvl);
    else
        printf("Node %c tidak ditemukan.\n", node);
}

void MenuKedalaman(Isi_Tree tree) {
    printf("Kedalaman pohon (Depth): %d\n", Depth(tree));
}

void MenuBandingkanNode(Isi_Tree tree) {
    char n1, n2;
    printf("Masukkan dua node yang ingin dibandingkan (misal A B): ");
    scanf(" %c %c", &n1, &n2);
    int l1 = Level(tree, n1);
    int l2 = Level(tree, n2);
    if (l1 == -1 || l2 == -1)
        printf("Salah satu node tidak ditemukan.\n");
    else if (l1 == l2)
        printf("Node %c dan %c berada di level yang sama (%d).\n", n1, n2, l1);
    else
        printf("Node %c di level %d dan %c di level %d.\n", n1, l1, n2, l2);
}