#include "nonBinaryTree.h"

void init_tree(Isi_Tree X)
{
    for (int i = 0; i <= jml_maks; i++)
    {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

void Create_tree(Isi_Tree X, int Jml_Node)
{
    init_tree(X);

    printf("\nMasukkan Root : ");
    infotype rootInfo;
    scanf(" %c", &rootInfo);
    X[1].info = rootInfo;

    int totalNodes = 1;
    int currentIndex = 1;

    while (currentIndex <= totalNodes)
    {
        infotype parentInfo = X[currentIndex].info;
        printf("Parent : %c\nJumlah anak : ", parentInfo);
        int numChildern;
        scanf("%d", &numChildern);

        if (numChildern > 0)
        {
            int firstChildernIndex = totalNodes + 1; // Indeks array yang sudah terisi + 1
            int lastChildernIndex = firstChildernIndex + (numChildern - 1);

            if (lastChildernIndex > Jml_Node)
            {
                printf("Error, overflow");
                return;
            }

            for (int j = 0; j < numChildern; j++)
            {
                int childernIndex = firstChildernIndex + j;
                printf("Anak ke %d : ", j + 1);
                infotype childInfo;
                scanf(" %c", &childInfo);

                X[childernIndex].info = childInfo;
                X[childernIndex].ps_pr = currentIndex;

                if (j == 0)
                {
                    X[currentIndex].ps_fs = childernIndex;
                    if ((j + 1) != numChildern)
                    {
                        X[firstChildernIndex + j].ps_nb = firstChildernIndex + j + 1;
                    }
                }
                else if ((j + 1) != numChildern)
                {
                    X[firstChildernIndex + j].ps_nb = firstChildernIndex + j + 1;
                }
                else
                {
                    X[firstChildernIndex + j].ps_nb = 0;
                }
                totalNodes++;
            }
        }
        currentIndex++;
    }
};

void PrintTree(Isi_Tree P)
{
    system("cls");
    int i = 1;
    printf("\nudah nyampe sini lho\n");
    while (P[i].info != nil && i < jml_maks)
    {
        printf("--> indeks ke-%d\n", i);
        printf("================================================\n");
        printf("ingfo array ke-%d          : %c\n", i, P[i].info);
        printf("first son array ke-%d     : %d\n", i, P[i].ps_fs);
        printf("next brother array ke-%d  : %d\n", i, P[i].ps_nb);
        printf("parent array ke-%d        : %d\n", i, P[i].ps_pr);
        printf("================================================\n\n");
        i++;
    }
}

bool IsEmpty(Isi_Tree P)
{
    return P[1].info == '\0';
};

void PreOrder(Isi_Tree P)
{
    if (!IsEmpty(P))
    {
        int i = 1;
        while (i != nil)
        {
            printf("%c ", P[i].info);
            if (P[i].ps_fs != nil)
            {
                i = P[i].ps_fs;
            }
            else if (P[i].ps_nb != nil)
            {
                i = P[i].ps_nb;
            }
            else
            {
                while (i != 1 && P[P[i].ps_pr].ps_nb == nil)
                {
                    i = P[i].ps_pr;
                }
                if (i == 1 && P[i].ps_nb == nil)
                {
                    // Sudah mencapai node akar dan tidak memiliki saudara, keluar dari perulangan
                    break;
                }
                if (i != 1)
                {
                    i = P[P[i].ps_pr].ps_nb;
                }
            }
        }
    }
    printf("\n");
};

/*Berikut Algoritma PreOrder juga tapi rekursif dan lebih efektif

void PreOrder(Isi_Tree T, address P) {
    if (P != nil) {
        printf("%c ", T[P].info); // Kunjungi node
        PreOrder(T, T[P].ps_fs); // Traverse ke anak pertama
        PreOrder(T, T[P].ps_nb); // Traverse ke saudara setelahnya
    }
}
*/

void InOrder(Isi_Tree T, address Akar) {
    if (Akar != nil) {
        address Anak = T[Akar].ps_fs; // Alamat anak pertama

        InOrder(T, Anak); // Rekursi untuk anak pertama

        printf("%c ", T[Akar].info); // Cetak nilai node saat ini

        Anak = T[Anak].ps_nb; // Pindah ke saudara berikutnya
        while (Anak != nil) {
            InOrder(T, Anak); // Rekursi untuk saudara berikutnya
            Anak = T[Anak].ps_nb;
        }
    }
}

void PostOrder(Isi_Tree T, address P) {
    if (P != nil) {
        PostOrder(T, T[P].ps_fs); // Traverse ke anak pertama
        printf("%c ", T[P].info); // Kunjungi node
        PostOrder(T, T[P].ps_nb); // Traverse ke saudara setelahnya
    }
}

void LevelOrder(Isi_Tree T, address Akar) {
    address Q[jml_maks];  // Queue untuk menyimpan alamat node
    int head = 0, tail = 0;  // Indeks head dan tail

    if (Akar != nil) {
        Q[tail++] = Akar;  // Masukkan akar ke dalam antrian

        while (head != tail) {
            address Node = Q[head++];  // Ambil node dari antrian

            printf("%c ", T[Node].info);  // Cetak nilai node

            address Anak = T[Node].ps_fs;  // Alamat anak pertama
            while (Anak != nil) {
                Q[tail++] = Anak;  // Masukkan anak ke dalam antrian
                Anak = T[Anak].ps_nb;  // Pindah ke saudara berikutnya
            }
        }
    }
}

bool Search(Isi_Tree T, address Akar, infotype X) {
    if (Akar != nil) {
        if (T[Akar].info == X) {
            return true;  // Jika nilai node sama dengan X, kembalikan true
        } else {
            address Anak = T[Akar].ps_fs;  // Alamat anak pertama
            while (Anak != nil) {
                if (Search(T, Anak, X)) {
                    return true;  // Jika nilai ditemukan di subtree, kembalikan true
                }
                Anak = T[Anak].ps_nb;  // Pindah ke saudara berikutnya
            }
        }
    }
    return false;  // Jika tidak ditemukan, kembalikan false
}

int nbElmt(Isi_Tree T, address Akar) {
    if (Akar != nil) {
        int count = 1;  // Hitung node saat ini
        address Anak = T[Akar].ps_fs;  // Alamat anak pertama
        while (Anak != nil) {
            count += nbElmt(T, Anak);  // Rekursi untuk menghitung subtree
            Anak = T[Anak].ps_nb;  // Pindah ke saudara berikutnya
        }
        return count;
    }
    return 0;  // Jika node kosong, kembalikan 0
}

int nbDaun(Isi_Tree T, address Akar) {
    if (Akar != nil) {
        address Anak = T[Akar].ps_fs;  // Alamat anak pertama
        if (Anak == nil) {
            return 1;  // Jika tidak memiliki anak, maka node ini adalah daun
        } else {
            int count = 0;
            while (Anak != nil) {
                count += nbDaun(T, Anak);  // Rekursi untuk menghitung subtree
                Anak = T[Anak].ps_nb;  // Pindah ke saudara berikutnya
            }
            return count;
        }
    }
    return 0;  // Jika node kosong, kembalikan 0
}

int Level(Isi_Tree T, address Akar, infotype X) {
    if (Akar != nil) {
        if (T[Akar].info == X) {
            return 1;  // Jika nilai node sama dengan X, kembalikan level 1
        } else {
            address Anak = T[Akar].ps_fs;  // Alamat anak pertama
            int level = 2;  // Level dimulai dari 2 untuk anak
            while (Anak != nil) {
                int foundLevel = Level(T, Anak, X);
                if (foundLevel != 0) {
                    return foundLevel + 1;  // Jika nilai ditemukan di subtree, kembalikan level + 1
                }
                Anak = T[Anak].ps_nb;  // Pindah ke saudara berikutnya
            }
        }
    }
    return 0;  // Jika tidak ditemukan, kembalikan 0
}

int Depth(Isi_Tree T, address Akar) {
    if (Akar != nil) {
        int maxDepth = 0;
        address Anak = T[Akar].ps_fs;  // Alamat anak pertama
        while (Anak != nil) {
            int childDepth = Depth(T, Anak);
            if (childDepth > maxDepth) {
                maxDepth = childDepth;  // Ambil depth maksimum dari semua anak
            }
            Anak = T[Anak].ps_nb;  // Pindah ke saudara berikutnya
        }
        return maxDepth + 1;  // Kembalikan depth maksimum + 1 (untuk node saat ini)
    }
    return 0;  // Jika node kosong, kembalikan 0
}

int Max(infotype X, infotype Y) {
    return (X > Y) ? X : Y;  // Kembalikan nilai terbesar antara X dan Y
}