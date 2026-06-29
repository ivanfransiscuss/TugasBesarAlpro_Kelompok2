#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ANSI escape code untuk mewarnai output 
#define RED31 "\033[31m"
#define GREEN32 "\033[32m" 
#define YELLOW33 "\033[33m"
#define BLUE34 "\033[34m"
#define PURPLE35 "\033[35m"
#define BLUE36 "\033[36m"
#define WHITE37 "\033[37m"
#define PINK91 "\033[91m"
#define GREEN92 "\033[92m"
#define CREAM93 "\033[93m"
#define BLUE94 "\033[94m"
#define PURPLE95 "\033[95m"
#define BLUE96 "\033[96m"
#define RESET "\033[m"

// Tipe Data Bentukan (Struct)
typedef struct{
    int x;
    int y;
    char nama[20];
    int skor;
} hadiah;

typedef struct{
    int x;
    int y;
} gerak;

// membuat fungsi-fungsi yang akan digunakan dalam program
void title();
void menu();
void urutkanHadiah(hadiah arr[], int n);
void tambahHadiah();
void tampilHadiah();
void tambahGerak();
void tampilGerak();
void bacaGerakO(gerak g[], int *jumlahGerak);
void wait(float x);
void simulasi();

#endif