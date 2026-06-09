#include <stdio.h>
#include <stdlib.h>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[m"

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

void title(){
    printf(RED "\n-------------------------------------------------------------------\n" RESET);
    printf(RED "|                                                                 |\n" RESET);
    printf(RED "|" RESET); printf(YELLOW "  ###          ###  ###########  ###########        ###########  " RESET); printf(RED "|\n" RESET); 
    printf(RED "|" RESET); printf(YELLOW "  ###          ###  ###########  ###########        ###########  " RESET); printf(RED "|\n" RESET);
    printf(RED "|" RESET); printf(YELLOW "  ###          ###      ###      ###                ###     ###  " RESET); printf(RED "|\n" RESET);
    printf(RED "|" RESET); printf(YELLOW "  ###          ###      ###      ###########  ####  ###     ###  " RESET); printf(RED "|\n" RESET);
    printf(RED "|" RESET); printf(YELLOW "  ###          ###      ###      ###########  ####  ###     ###  " RESET); printf(RED "|\n" RESET);
    printf(RED "|" RESET); printf(YELLOW "  ###          ###      ###      ###                ###     ###  " RESET); printf(RED "|\n" RESET);
    printf(RED "|" RESET); printf(YELLOW "  ###########  ###      ###      ###########        ###########  " RESET); printf(RED "|\n" RESET);
    printf(RED "|" RESET); printf(YELLOW "  ###########  ###      ###      ###########        ###########  " RESET); printf(RED "|\n" RESET);
    printf(RED "|                                                                 |\n" RESET);
    printf(RED "-------------------------------------------------------------------\n" RESET);
}

void menu(){
    printf("Menu:\n");
    printf(RED "----------------------\n" RESET);
    printf(RED "|" RESET); printf(" 1. Tambah Hadiah   "); printf(RED "|\n" RESET);
    printf(RED "----------------------\n" RESET);
    printf(RED "----------------------\n" RESET);
    printf(RED "|" RESET); printf(" 2. Tambah Gerak O  "); printf(RED "|\n" RESET);
    printf(RED "----------------------\n" RESET);
    printf(RED "----------------------\n" RESET);
    printf(RED "|" RESET); printf(" 3. Simulasi Lite-O "); printf(RED "|\n" RESET);
    printf(RED "----------------------\n" RESET);
    printf(RED "----------------------\n" RESET);
    printf(RED "|" RESET); printf(" 4. Keluar          "); printf(RED "|\n" RESET);
    printf(RED "----------------------\n" RESET); 
    printf("Masukkan Menu: ");
}

void urutkanHadiah(hadiah arr[], int n){
    hadiah temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j].y > arr[j+1].y || (arr[j+1].y == arr[j].y && arr[j].x > arr[j+1].x)){
                hadiah temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }
}

void tambahHadiah(){
    FILE *fileHadiah;
    hadiah h;

    fileHadiah = fopen("thadiah.txt","a");

    printf("\nx : ");
    scanf("%d",&h.x);

    printf("y : ");
    scanf("%d",&h.y);

    printf("nama : ");
    scanf("%s",h.nama);

    printf("skor : ");
    scanf("%d",&h.skor);

    fprintf(fileHadiah,"%d %d %s %d\n",
            h.x,
            h.y,
            h.nama,
            h.skor);

    fclose(fileHadiah);
}

void tampilHadiah(){
    FILE *fileHadiah;
    hadiah h[50];
    int jumlahHadiah = 0;
    char mauIsi;

    fileHadiah = fopen("thadiah.txt","r");

    printf("\nIsi hadiah saat ini:\n");

    while(fscanf(fileHadiah,"%d %d %s %d",
          &h[jumlahHadiah].x,
          &h[jumlahHadiah].y,
          h[jumlahHadiah].nama,
          &h[jumlahHadiah].skor)==4){
            jumlahHadiah++;      
    }
    fclose(fileHadiah);

    printf("-----------------------------------\n");
    printf("|x      |y      |nama     |skor   |\n");
    printf("-----------------------------------\n");

    if(jumlahHadiah == 0){
        printf("|       |       |         |       |\n");
        printf("-----------------------------------\n");
    }

    for(int i=0; i<jumlahHadiah; i++){
        printf("|%-4d   |%-4d   |%-5s    |%-4d   |\n",
               h[i].x,
               h[i].y,
               h[i].nama,
               h[i].skor);
        printf("-----------------------------------\n");
    }

    do {
        printf("\ningin mengisi? (Y/T): ");
        scanf(" %c", &mauIsi);

        switch(mauIsi){
            case 'y':
            case 'Y':
            tambahHadiah();
            break;
            case 't':
            case 'T':
            return;
            break;
            default:
            printf("Input tidak valid!!!\n");
            break;
        }
    } while(mauIsi != 't' && mauIsi != 'T');
}



void tambahGerak(){
    FILE *fileGerak;
    gerak g;

    fileGerak = fopen("tgerak.txt","a");

    printf("\nx : ");
    scanf("%d",&g.x);

    printf("y : ");
    scanf("%d",&g.y);

    fprintf(fileGerak,"%d %d\n",
            g.x,
            g.y);

    fclose(fileGerak);
}

void tampilGerak(){
    FILE *fileGerak;
    gerak g[75];
    int jumlahGerak = 0;
    char mauTambah;

    fileGerak = fopen("tgerak.txt","r");

    printf("\nGerakan O saat ini:\n");

    while(fscanf(fileGerak,"%d %d",
                 &g[jumlahGerak].x,
                 &g[jumlahGerak].y)==2){
                    jumlahGerak++;
    }
    fclose(fileGerak);

    printf("---------------------\n");
    printf("|posisi ke- |x  |y  |\n");
    printf("---------------------\n");

    if(jumlahGerak == 0){
        printf("|           |   |   |\n");
        printf("---------------------\n");
    }

    for(int i=0; i<jumlahGerak; i++){
        printf("|%-6d     |%-2d |%-2d |\n", 
               i+1,
               g[i].x,
               g[i].y);
        printf("---------------------\n");
    }

    do{
        printf("\ningin menambah? (Y/T): ");
        scanf(" %c", &mauTambah);

        switch(mauTambah){
            case 'y':
            case 'Y':
            tambahGerak();
            break;
            case 't':
            case 'T':
            return;
            break;
            default:
            printf("Input tidak valid!!!\n");
            break;
        }
    } while(mauTambah != 't' && mauTambah != 'T');
}

int main(){
    int pilihMenu;

    do{
        title();
        menu();
        scanf("%d", &pilihMenu);
        switch(pilihMenu){
            case 1:
            tampilHadiah();
            break;
            case 2:
            tampilGerak();
            break;
            case 3:
            // Simulasi Lite-O
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Input tidak valid!!!\n");
            break;
        }
    } while(pilihMenu != 4);

    return 0;
}

