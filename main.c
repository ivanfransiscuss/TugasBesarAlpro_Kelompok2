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
#define RESET "\033[m" // Mengembalikan warna ke default

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

    printf ("%s###          ###  ###########  ###########        ###########\n", YELLOW33); 
    printf ("###          ###  ###########  ###########        ###########\n");
    printf ("###          ###      ###      ###                ###     ###\n");
    printf ("###          ###      ###      ###########  ####  ###     ###\n");
    printf ("###          ###      ###      ###########  ####  ###     ###\n");
    printf ("###          ###      ###      ###                ###     ###\n");
    printf ("###########  ###      ###      ###########        ###########\n");
    printf ("###########  ###      ###      ###########        ###########\n%s", RESET);
   
}

void menu(){
    printf("\nMenu:\n");
    printf("1. Tambah Hadiah\n"); 
    printf("2. Tambah Gerak O\n"); 
    printf("3. Simulasi Lite-O\n"); 
    printf("4. Keluar\n"); 
    printf("Masukkan Menu: ");
}

void urutkanHadiah(hadiah arr[], int n){ // Mengurutkan hadiah berdasarkan posisi (y, lalu x)
    hadiah temp; // Variabel sementara untuk pertukaran
    for(int i=0; i<n-1; i++){ // Loop untuk setiap elemen dalam array
        for(int j=0; j<n-i-1; j++){ // Loop untuk membandingkan elemen yang berdekatan
            if(arr[j].y > arr[j+1].y || (arr[j+1].y == arr[j].y && arr[j].x > arr[j+1].x)){ // Kondisi untuk mengurutkan berdasarkan y, lalu x jika y sama
                hadiah temp = arr[j]; // Menyimpan elemen saat ini dalam variabel sementara
                arr[j] = arr[j+1]; // Menukar elemen saat ini dengan elemen berikutnya
                arr[j+1] = temp;  // Menempatkan elemen sementara ke posisi berikutnya
            }

        }
    }
}

void tambahHadiah(){
    FILE *fileHadiah;    
    hadiah h;    // variabel sementara buat nyimpen data hadiah

    fileHadiah = fopen("thadiah.txt","a");    // buka file dalam mode apppend 

    printf("\nx : ");
    scanf("%d",&h.x);    // mmenyimpan input koordinat x ke variabel h.x

    printf("y : ");
    scanf("%d",&h.y);     // menyimpan input koordinat y ke variabel h.y

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
    hadiah h[50]; // Array untuk menampung maksimal 50 data hadiah dari file
    int jumlahHadiah = 0; // Menghitung jumlah hadiah yang dibaca dari file
    char mauIsi; // variabel untuk menyimpan pilihan pengguna (Y/T)

    fileHadiah = fopen("thadiah.txt","r");    // buka file dalam mode baca agar data hadiah dapat ditampiljan

    printf("\nIsi hadiah saat ini:\n");

    // Membaca semua data dari file
    while(fscanf(fileHadiah,"%d %d %s %d",
          &h[jumlahHadiah].x,
          &h[jumlahHadiah].y,
          h[jumlahHadiah].nama,
          &h[jumlahHadiah].skor)==4){    // membaca setiap baris data hadiah dari file selama format yang dibaca lengkap
            jumlahHadiah++;    // menambah jumlah hadiah setiap kali satu data berhasil dibaca   
    }
    fclose(fileHadiah);
    urutkanHadiah(h, jumlahHadiah); // Mengurutkan hadiah berdasarkan posisi (y, lalu x) sebelum ditampilkan
    
    // Header tabel
    printf("-----------------------------------\n");
    printf("|x      |y      |nama     |skor   |\n");
    printf("-----------------------------------\n");

    if(jumlahHadiah == 0){        // mengecek apakah file belum memiliki data hadiah
        printf("|       |       |         |       |\n");
        printf("-----------------------------------\n");
    }

    // Menampilkan setiap data hadiah dalam tabel
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
            tambahHadiah();    // memanggil fungsi tambahHadiah() jika pengguna memilih Ya
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
    // membuka file 
    fileGerak = fopen("tgerak.txt","a");

    //memasukan koordinat tujuan o
    printf("\nx : ");
    scanf("%d",&g.x);

    printf("y : ");
    scanf("%d",&g.y);

    //menyimpan koordinat ke file
    fprintf(fileGerak,"%d %d\n",
            g.x,
            g.y);

    fclose(fileGerak); //menutup file
}

void tampilGerak(){
    FILE *fileGerak;
    gerak g[75]; // Array untuk menampung maksimal 75 data gerakan O dari file
    int jumlahGerak = 0; // Menghitung jumlah gerakan yang dibaca dari file
    char mauTambah;

    fileGerak = fopen("tgerak.txt","r");

    printf("\nGerakan O saat ini:\n");

    // Membaca semua data dari file
    while(fscanf(fileGerak,"%d %d",
                 &g[jumlahGerak].x,
                 &g[jumlahGerak].y)==2){ // membaca setiap baris data gerak dari file selama format yang dibaca lengkap
                    jumlahGerak++; // menambah jumlah gerak setiap kali satu data berhasil dibaca
    }
    fclose(fileGerak);

    // Header tabel
    printf("---------------------\n");
    printf("|posisi ke- |x  |y  |\n");
    printf("---------------------\n");

    if(jumlahGerak == 0){
        printf("|           |   |   |\n");
        printf("---------------------\n");
    }

    // Menampilkan setiap data gerakan O dalam tabel
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


void bacaGerakO(gerak g[], int *jumlahGerak){
    FILE *fileGerak;

    //mengosongkan jumlah data sebelum mulai membaca file
    *jumlahGerak = 0;

    //membuka file koordinat gerak o
    fileGerak = fopen("tgerak.txt","r");

    //menghentikan fungsi jika file belum ada
    if(fileGerak == NULL){
        return;
    }
    //membaca setiap koordinat x dan y dari file
    // lalu menyimpannya ke dalam array g
     while(fscanf(fileGerak,"%d %d",
                 &g[*jumlahGerak].x,
                 &g[*jumlahGerak].y)==2){
        (*jumlahGerak)++;
    }

    fclose(fileGerak); //menutup file
}

void wait(float x) {
    time_t start;    // menyimpan waktu saat fungsi mulai dijalankan
    time_t current;    // menyimpan waktu saat ini untuk dibandingkan dgn waktu awal

    time(&start);    // mengambil waktu awal saat fungsi dipanggil

    do{
        time(&current);    // memperbarui waktu saat ini secara terus menerus
    } while(difftime(current, start) < x);    // mengulang hingga selisih waktu mencapai nilai x detik
}

void simulasi(){
    int panjang;
    int lebar;
    int skorTotal = 0; // UNTUK YANG BAGIAN UPDATE SKOR, GUNAKAN VARIABEL INI UNTUK MENAMPUNG TOTAL SKOR
    int jumlahWarna = 12;
    // Array yang berisi kode warna untuk mewarnai hadiah yang tampil di papan
    const char *warnaHadiah[] = {RED31, GREEN32, YELLOW33, BLUE34, PURPLE35, BLUE36, WHITE37, PINK91, GREEN92, CREAM93, BLUE94, PURPLE95, BLUE96};
    gerak daftarGerak[100]; // Menyimpan seluruh data gerakan O dari file tgerak
    int jumlahGerak;
    bacaGerakO(daftarGerak, &jumlahGerak); // Memanggil fungsi pembacaan data gerak

    hadiah hList[100]; // Menyiapkan tampungan maks untk 100 hadiah
    int jumlahHadiah = 0;
    int statusHadiah[100] = {0}; // Menambahkan array status (0=utuh, 1=dimakan)

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
    urutkanHadiah(hList, jumlahHadiah); // Mengurutkan hadiah berdasarkan posisi untuk memudahkan pengecekan saat simulasi

    printf("\nInput ukuran papan tampilan:\n");
    printf("-----------------------------\n");
    printf("Panjang : ");
    scanf("%d", &panjang);
    printf("Lebar : ");
    scanf("%d", &lebar);

    printf("\n");
    for(int langkah = 0; langkah < jumlahGerak; langkah++){

        if (langkah > 0){
            system("cls");    // membersihkan layar sebelum menampilkan animasi berikutnya
        }
        
    int posisiX = daftarGerak[langkah].x;
    int posisiY = daftarGerak[langkah].y;

    for(int k = 0; k < jumlahHadiah; k++){
        if(posisiX == hList[k].x && posisiY == hList[k].y && statusHadiah[k] == 0){
            skorTotal += hList[k].skor;
            statusHadiah[k] = 1; // Menandai hadiah sudah dimakan
        }
    }
    
    for(int i=1; i<=panjang+3; i++){
        printf("|");
        for(int j=1; j<=lebar; j++){
            if(i==1||i==panjang+3){
                printf("-");
            } else{
                if((j - 1) == posisiX && (i - 2) == posisiY){
                    printf("O");
                } else {
                    int adaHadiah = 0;
                    for(int k=0; k<jumlahHadiah; k++){
                        if((i - 2) == hList[k].y && statusHadiah[k] == 0){ // Mengecek posisi dan memastikan hadiahnya belum dimakan   
                            char teks[30];
                            sprintf(teks, "%s%d", hList[k].nama, hList[k].skor);
                            int len = strlen(teks);
                            if((j-1) >= hList[k].x && (j-1) < hList[k].x + len){
                                // Memilih warna berdasarkan indeks
                                int warnaIndex = k % jumlahWarna;
                                // Mencetak hadiah dengan warna yang kepilih
                                printf("%s%c%s", warnaHadiah[warnaIndex], teks[j-1 - hList[k].x], RESET);
                                adaHadiah = 1;
                                break;
                            }
                        }
                    }
                    //Jika tidak ada hadiah, menampilkan spasi
                    if(adaHadiah == 0){
                    printf(" ");
                    }
                }
            }
        }
        printf("|\n");
    }
printf("\nSkor O: %d\n", skorTotal);
wait(0.1);     // memberi jeda 0,1 detik sblm O berpindah ke koordinat brktnya
}
}


int main(){
    int pilihMenu;
    title();
    do{
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

