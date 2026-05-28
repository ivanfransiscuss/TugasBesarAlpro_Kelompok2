#include <stdio.h>

int main() {
    int n;
    int sum = 0;
    int max;
    // test perubahan
    printf("Masukkan jumlah data: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid.\n");
        return 1;
    }
    int data[n];
    for (int i = 0; i < n; i++) {
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &data[i]);
        sum += data[i];

        if (i == 0 || data[i] > max) {
            max = data[i];
        }
    }
    printf("\nTotal = %d\n", sum);
    printf("Rata-rata = %.2f\n", (float)sum / n);
    printf("Nilai terbesar = %d\n", max);
    return 0;
}