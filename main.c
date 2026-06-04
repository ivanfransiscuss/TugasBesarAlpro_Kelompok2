#include <stdio.h>

typedef struct{
    int x;
    int y;
    char nama[20];
    int skor;
} hadiah;

void tambahHadiah(){
    FILE *fileHadiah;
    hadiah h;

    fileHadiah = fopen("thadiah.txt","a");

    printf("x : ");
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

int main(){
    tambahHadiah();

    printf("\nIsi File:\n");
    tampilHadiah();

    return 0;
}

