#ifndef	graphdinamis_h
#define graphdinamis_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Nil NULL
#define namaStasiun(P) (P)->namaStasiun
#define next(P) (P)->next
#define arc(P) (P)->arc
#define jarakJalur(P) (P)->jarakJalur
#define tujuan(P) (P)->tujuan
#define nextJalur(P) (P)->nextJalur
#define nama(P) (P)->nama
#define jarak(P) (P)->jarak
#define fs(P) (P)->fs
#define nb(P) (P)->nb
#define pr(P) (P)->pr

typedef struct stasiun *address1;
typedef struct jalur *address2;
typedef struct Tree *node;

typedef struct Tree{
	char nama[20];
	int jarak;
	node fs,nb,pr;
}tercepat;

typedef struct stasiun{
	char namaStasiun[20];
	address1 next;
	address2 arc;
}graph;

typedef struct jalur{
	int jarakJalur;
	char waktuKeberangkatan[10]; // Merupakan tambahan.
	address1 tujuan;
	address2 nextJalur;
}jalan;

typedef struct {
	char username[50];
	char password[50];	
	int eMoney;
}akun;

extern address1 first;

// Penanggung Jawab

address1 alokasistasiun(); // Azka Darajat
address2 alokasijalur(); // Azka Darajat
address1 lastLL(address1 first); // Radja Restu Arsita
address2 lastjalur(address2 first); // Azka Darajat
address1 caristasiun(char nama[],address1 first); // Radja Restu Arsita
void buatLL(address1 *first,char nama[]); // Azka Darajat
void hapusLL(address1 *awal); // Radja Restu Arsita
void buatJalur(char awal[],char akhir[],int jarak, char waktu[], address1 first); // Azka Darajat
void printStasiun(address1 first); // Azka Darajat
void registrasi(); // Azka Darajat
void buatFile(char nama[]); // Azka Darajat
bool login(char b[],char c[]); // Azka Darajat
void topup(char b[],char c[],int duid); // Radja Restu Arsita
int cekemoney(char b[],char c[]); // Azka Darajat
void setColor(int color); // Azka Darajat
int harga(int lompatan,int jartot); // Azka Darajat
void bayar(int biaya,char b[],char c[]); // Radja Restu Arsita
void pemetaan(address1 *first); // Radja Restu Arsita
void insert(node *root,int kilometer,char stasiun[],node *parent); // Radja Restu Arsita
node graphToTree(address1 first,address1 awal); // Azka Darajat
address1 djikstra(node root,char tujuan[], int *jartot); // Radja Restu Arsita
int jaraktotal(node tujuan,node root); // Radja Restu Arsita
int inputBener(int min, int max);  // Azka Darajat
void reverseprint(address1 head); // Azka Darajat
int estimasiWaktuSampai(int jarak, char waktuKeberangkatan[]);
void menuLihatJadwal(address1 first);


#endif
