#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    printf("\n");
    printf ("###          ###  ###########  ###########        ###########\n" ); 
    printf ("###          ###  ###########  ###########        ###########\n" );
    printf ("###          ###      ###      ###                ###     ###\n" );
    printf ("###          ###      ###      ###########  ####  ###     ###\n" );
    printf ("###          ###      ###      ###########  ####  ###     ###\n" );
    printf ("###          ###      ###      ###                ###     ###\n" );
    printf ("###########  ###      ###      ###########        ###########\n" );
    printf ("###########  ###      ###      ###########        ###########\n" );
    printf("\n");
   
}

void menu(){
    printf("Menu:\n");
    printf("1. Tambah Hadiah\n"); 
    printf("2. Tambah Gerak O\n"); 
    printf("3. Simulasi Lite-O\n"); 
    printf("4. Keluar\n"); 
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

void tampilHadiahDiPosisi(int x, int y){
    FILE *fileHadiah;
    hadiah h;

    fileHadiah = fopen("thadiah.txt","r");

    while(fscanf(fileHadiah,"%d %d %s %d",
                 &h.x,
                 &h.y,
                 h.nama,
                 &h.skor)==4){

        if(h.x == x && h.y == y){
            printf("H");
            fclose(fileHadiah);
            return;
        }
    }

    fclose(fileHadiah);

    printf(" ");
}

void bacaGerakO(gerak g[], int *jumlahGerak){
    FILE *fileGerak;

    *jumlahGerak = 0;

    fileGerak = fopen("tgerak.txt","r");

    if(fileGerak == NULL){
        return;
    }
     while(fscanf(fileGerak,"%d %d",
                 &g[*jumlahGerak].x,
                 &g[*jumlahGerak].y)==2){
        (*jumlahGerak)++;
    }

    fclose(fileGerak);
}

void simulasi(){
    int panjang;
    int lebar;
    int skorTotal = 0; // UNTUK YG DAPET BAGIAN UPDATE SKOR, TOLONG PAKE VARIABEL INI YA NNTI
    gerak awalO = {-1, -1}; // posisii awal
    gerak daftarGerak[100]; // Menyimpan seluruh data gerakan O dari file tgerak
    int jumlahGerak;
    bacaGerakO(daftarGerak, &jumlahGerak); // Memanggil fungsi pembacaan data gerak
    FILE *fg;

    hadiah hList[100]; // menyiapkan tampungan maks untk 100 hadiah
    int jumlahHadiah = 0;
    
    fg = fopen("tgerak.txt", "r");
    if(fg != NULL){
        fscanf(fg, "%d %d", &awalO.x, &awalO.y);
        fclose(fg);
    }

    FILE *fh = fopen("thadiah.txt", "r");
    if(fh != NULL){
        while(fscanf(fh, "%d %d %s %d",
                     &hList[jumlahHadiah].x,
                     &hList[jumlahHadiah].y,
                     hList[jumlahHadiah].nama,
                     &hList[jumlahHadiah].skor) == 4){
                        jumlahHadiah++;
        }
        fclose(fh);
    }

    printf("\nInput ukuran papan tampilan:\n");
    printf("-----------------------------\n");
    printf("Panjang : ");
    scanf("%d", &panjang);
    printf("Lebar : ");
    scanf("%d", &lebar);

    printf("\n");

    for(int i=1; i<=panjang; i++){
        printf("|");
        for(int j=1; j<=lebar; j++){
            if(i==1||i==panjang){
                printf("-");
            } else{
                if((j - 1) == awalO.x && (i - 2) == awalO.y){
                    printf("O");
                } else {
                    int adaHadiah = 0;
                    for(int k=0; k<jumlahHadiah; k++){
                        if((i - 2) == hList[k].y){
                            char teks[30];
                            sprintf(teks, "%s%d", hList[k].nama, hList[k].skor);
                            int len = strlen(teks);
                            if((j-1) >= hList[k].x && (j-1) < hList[k].x + len){
                                printf("%c", teks[j-1 - hList[k].x]);
                                adaHadiah = 1;
                                break;
                            }
                        }
                    }
                    //kalau ga ada hadiah, tampilkan spasi
                    if(adaHadiah == 0){
                    printf(" ");
                    }
                }
            }
        }
        printf("|\n");
    } 
    printf("\n");
    printf("\nSkor O: %d\n", skorTotal);
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
            simulasi();
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

