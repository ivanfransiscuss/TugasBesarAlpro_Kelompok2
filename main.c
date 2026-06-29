#include "header.h"

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
            system("exit"); // Pastikan ini sudah terganti ya!
            break;
            default:
            printf("Input tidak valid!!!\n");
            break;
        }
    } while(pilihMenu != 4);

    return 0;
}