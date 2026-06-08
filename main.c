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

void title(){
    printf(RED "-------------------------------------------------------------------\n" RESET);
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
    hadiah h;

    fileHadiah = fopen("thadiah.txt","r");

    while(fscanf(fileHadiah,"%d %d %s %d",
          &h.x,
          &h.y,
          h.nama,
          &h.skor)==4){

        printf("%d %d %s %d\n",
               h.x,
               h.y,
               h.nama,
               h.skor);
               
    }

    fclose(fileHadiah);
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

typedef struct{
    int x;
    int y;
} gerak;

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
    gerak g;

    fileGerak = fopen("tgerak.txt","r");

    while(fscanf(fileGerak,"%d %d",
                 &g.x,
                 &g.y)==2){

        printf("%d %d\n",
               g.x,
               g.y);
    }

    fclose(fileGerak);
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

