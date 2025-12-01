#include <stdio.h>
#define hariMaks 7

int perMhs(int hadir[][hariMaks], int m, int h){
    int total = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < h; j++){
            if(hadir[i][j] == 1) total = total + 1;
        }
    }
    return total;
}

int perHari(int hadir[][hariMaks], int m, int h){
    int total = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < m; j++){
            if(hadir[i][j] == 1) total = total + 1;
        }
    }
    return total;
}

float rataRataKehadiran(int hadir[][hariMaks], int m, int h){

}

void output(int hadir[][hariMaks], int m, int h){
    printf("\n");
    printf("Rekap per mahasisa: \n");
    for(int i = 0; i < m; i++){
        printf("Mhs %d: %d hadir dari %d\n", i+1, perMhs(hadir, m, h), m);
    }
    for(int i = 0; i < h; i++){
        printf("Hari %d: %d Mahasiswa hadir\n", i+1, perHari(hadir, m, h), m);
    }
}

int main(){
    int m, h;

    printf("Masukkan jumlah mahasiswa : "); scanf("%d", &m);
    printf("Masukkan jumlah pertemuan dalam seminggu : "); scanf("%d", &h);

    int hadir[m][hariMaks];

    for(int i = 0; i < m; i++){
        int j = 0;
        while(j < h){
            printf("Mahasiswa ke-%d, Hari ke-%d (1=hadir, 0=tidak): ", i + 1, j + 1); scanf("%d", hadir[i][j]);
            if(hadir[i][j] >= 1 || hadir[i][j] <= 0){
                printf("Harap isi dengan 1 (hadir) atau 0 (tidak hadir)\n");
                continue;
            }
            j++;
        }
    }

    output(hadir, m, h);

    return 0;
}