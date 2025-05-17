#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree tree;

    // Inisialisasi seluruh simpul kosong
    for (int i = 1; i <= jml_maks; i++) {
        tree[i].info = '\0';
        tree[i].ps_fs = 0;
        tree[i].ps_nb = 0;
        tree[i].ps_pr = 0;
    }

    // Manual sesuai final state gambar (sampai level 2)
    tree[1].info = 'A'; tree[1].ps_fs = 2; tree[1].ps_nb = 0; tree[1].ps_pr = 0;
    tree[2].info = 'B'; tree[2].ps_fs = 4; tree[2].ps_nb = 3; tree[2].ps_pr = 1;
    tree[3].info = 'C'; tree[3].ps_fs = 6; tree[3].ps_nb = 0; tree[3].ps_pr = 1;
    tree[4].info = 'D'; tree[4].ps_fs = 0; tree[4].ps_nb = 5; tree[4].ps_pr = 2;
    tree[5].info = 'E'; tree[5].ps_fs = 0; tree[5].ps_nb = 6; tree[5].ps_pr = 2;
    tree[6].info = 'F'; tree[6].ps_fs = 0; tree[6].ps_nb = 7; tree[6].ps_pr = 3;
    tree[7].info = 'G'; tree[7].ps_fs = 0; tree[7].ps_nb = 8; tree[7].ps_pr = 3;
    tree[8].info = 'H'; tree[8].ps_fs = 0; tree[8].ps_nb = 0; tree[8].ps_pr = 3;

    printf("Final State Pohon (Array Kontigu):\n");
    PrintTree(tree);

    return 0;
}
