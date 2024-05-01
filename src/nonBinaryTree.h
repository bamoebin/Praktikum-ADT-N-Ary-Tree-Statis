#ifndef nbtrees_h
#define nbtrees_h
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20
// Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0
#define Enter printf("\n");
/***************************/
/* Type data */
/***************************/
/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak
dipakai */
/* Kamus */
typedef char infotype;
typedef int address;
typedef struct
{
    infotype info;
    address ps_fs, ps_nb, ps_pr;
    //ps_fs (first son), ps_nb (next brother), ps_pr (parent)
} nbtree;
typedef nbtree Isi_Tree[jml_maks + 1];
/***************************/
/* S P E S I F I K A S I */
/***************************/

void prepareArray(Isi_Tree X);
void init_tree(Isi_Tree X);

// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input
void Create_tree(Isi_Tree X, int Jml_Node);
/* Mengirimkan true jika Isi_Tree KOSONG */
bool IsEmpty(Isi_Tree P);

/***** Traversal *****/

/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent,
fs, nb */
void PreOrder(Isi_Tree P);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent,
Sisa anak lain */
void InOrder(Isi_Tree T, address P);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb,
Parent */
void PostOrder(Isi_Tree T, address P);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */
void LevelOrder(Isi_Tree T, address Akar);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */
void PrintTree(Isi_Tree P);


/***** Search *****/

/* Mengirimkan true jika ada node dari P yang bernilai X */
bool Search(Isi_Tree T, address Akar, infotype X);

/***** Fungsi Lain *****/

/* Mengirimkan banyak elemen (node) di pohon non biner P */                          
int nbElmt(Isi_Tree T, address Akar);
/* Mengirimkan banyak daun (node) pohon non biner P */
int nbDaun(Isi_Tree T, address Akar);
/* Mengirimkan level dari node X yang merupakan salah satu simpul */
int Level(Isi_Tree T, address Akar, infotype X);
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari
Pohon */
/* Basis : Pohon Kosong, tingginya Nol */
int Depth(Isi_Tree T, address Akar);
/* Mengirimkan Nilai terbesar dari dua data */
int Max(infotype X, infotype Y);
#endif