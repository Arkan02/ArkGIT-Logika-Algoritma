#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int nilai[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nilai[j] < nilai[j + 1]) {
                int temp = nilai[j];
                nilai[j] = nilai[j + 1];
                nilai[j + 1] = temp;
            }
        }
    }
}

int rataRata(int nilai[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++){
        total = total + nilai[i];
    }
    return total / n;
}

void output(int nilai[], int n){
    printf("\n");
    printf("Nilai :\n");
    for(int i = 0; i < n; i++){
        printf("%d ", nilai[i]);
    }
    
    bubbleSort(nilai, n);
    printf("\n\n");
    printf("Nilai minimum : %d\n\n", nilai[0]);
    printf("Nilai maksimum : %d\n\n", nilai[n-1]);
    printf("Average : %d\n", rataRata(nilai, n));
    
    printf("\n");
    printf("Setelah diurutkan :\n");
    
    for(int i = 0; i < n; i++){
        printf("%d ", nilai[i]);
    }

    printf("\n");
    printf("Rata-rata setelah mengabaikan 1 nilai terendah : %d\n", rataRata(nilai, n-1));
}

int main(){
    int n;
    int nilai[50];

    while(1){
        printf("Masukkan jumlah murid : "); scanf("%d", &n);

        if(n > 50 || n < 1){
            printf("Jumlah tidak boleh lebih dari 50 atau kurang dari 1\n\n");
            continue;
        }
        int i = 0;
        while(i < n){
            printf("Nilai mahasiswa-%d : ", i+1); scanf("%d", &nilai[i]);
            if(nilai[i] < 0 || nilai[i] > 100) {
                printf("Nilai tidak bisa lebih dari 100 atau kurang dari 0\n\n");
                continue;
            }
            i++;
        }
    
        output(nilai, n);

        break;
    }

    return 0;
}