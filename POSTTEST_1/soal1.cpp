#include <iostream>
using namespace std;

// Fungsi untuk cek bilangan prima
bool isPrima(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Fungsi untuk membalik array menggunakan pointer
void balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    const int N = 7;
    int arr[N];

    int prima = 2, kelipatan3 = 3;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) { 
            // index genap -> bilangan prima
            while (!isPrima(prima)) prima++;
            arr[i] = prima;
            prima++;
        }
    }

    // Tampilkan sebelum dibalik
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Balik array pakai pointer
    balikArray(arr, N);

    // Tampilkan sesudah dibalik
    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
