#include <stdio.h>

void menuAllItem(char nama[][30], int harga[], int stok[], int jmlhItem){
    printf("\n");
    printf("Index\tNama\t\tHarga\t\tStok\n");
    for(int i = 0; i < jmlhItem; i++){
        printf("%d\t", i);
        printf("%s\t\t", nama[i]);
        printf("%d\t\t", harga[i]);
        printf("%d", stok[i]);
        printf("\n");
    }
}

void menuAddStock(int stok[], int jmlhItem){
    int index;
    int addItem;
    printf("\n");
    printf("Index item yang ingin ditambah stok: "); scanf("%d", &index);
    printf("Jumlah: "); scanf("%d", &addItem);

    stok[index] = stok[index] + addItem;
}

void menuSellItem(char nama[][30], int harga[], int stok[], int jmlhItem, int *ttlPemasukan){
    printf("\n");
    int index;
    int jmlh;
    printf("Index item yang ingin dijual: "); scanf("%d", &index);
    printf("Jumlah: "); scanf("%d", &jmlh);

    if(stok[index] >= jmlh){
        stok[index] = stok[index] - jmlh;
        *ttlPemasukan = *ttlPemasukan + harga[index] * jmlh;
    }
        else printf("Stok tidak mencukupi\n");
}

void menuTtlIncome(int *ttlPemasukan){
    printf("\n");
    printf("Total pemasukkan : %d\n", *ttlPemasukan);
}

void menu(char nama[][30], int harga[], int stok[], int jmlhItem, int *ttlPemasukan){
    int isValid = 1;
    while(isValid){
        printf("\n");
        int pilih;
        printf("MENU KANTIN\n");
        printf("1. Tampilkan semua item\n");
        printf("2. Tambah stok item\n");
        printf("3. Jual item\n");
        printf("4. Tampilkan total pemasukan\n");
        printf("5. Keluar\n");
        
        printf("Pilih menu: "); scanf("%d", &pilih);
        switch(pilih){
            case 1: menuAllItem(nama, harga, stok, jmlhItem);
                    break;
            case 2: menuAddStock(stok, jmlhItem);
                    break;
            case 3: menuSellItem(nama, harga, stok, jmlhItem, ttlPemasukan);
                    break;
            case 4: menuTtlIncome(ttlPemasukan);
                    break;
            case 5: isValid = 0;
                    break;
            default: printf("Tidak ada di pilihan\n");  
        }
    }

}

int main(){
    int jmlhItem;     // banyak item yang terdaftar
    int ttlPemasukan = 0;

    printf("Masukkan total Item: "); scanf("%d", &jmlhItem);
    printf("\n");

    char nama[jmlhItem][30];   // nama item
    int harga[jmlhItem];       // harga satuan
    int stok[jmlhItem];        // stok tersisa

    for(int i = 0; i < jmlhItem; i++){
        printf("Barang %d\n", i+1);
        printf("Nama barang: "); scanf("%30s", nama[i]);
        printf("Harga barang: "); scanf("%d", &harga[i]);
        printf("Stok barang: "); scanf("%d", &stok[i]);
        printf("\n");
    }

    menu(nama, harga, stok, jmlhItem, &ttlPemasukan);

    return 0;
}