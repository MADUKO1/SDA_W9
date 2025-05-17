#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree tree;
    int pilihan;    

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



    do {
        printf("\nMenu Operasi Non Binary Tree\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch(pilihan) {
            case 1: MenuPreOrder(tree); break;
            case 2: MenuInOrder(tree); break;
            case 3: MenuPostOrder(tree); break;
            case 4: MenuLevelOrder(tree); break;
            case 5: MenuPrintTree(tree); break;
            case 6: MenuSearch(tree); break;
            case 7: MenuJumlahDaun(tree); break;
            case 8: MenuCariLevel(tree); break;
            case 9: MenuKedalaman(tree); break;
            case 10: MenuBandingkanNode(tree); break;
            case 11: printf("Terima kasih!\n"); break;
            default: printf("Pilihan tidak valid.\n"); break;
        }

        if (pilihan != 11) {
            printf("\nKlik apapun untuk melanjutkan...");
            getchar();
        }

    } while (pilihan != 11);

    return 0;
}
