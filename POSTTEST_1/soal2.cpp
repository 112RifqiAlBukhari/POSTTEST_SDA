#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];

    // Input elemen matriks
    cout << "Masukkan elemen matriks 3x3:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> matriks[i][j];
        }
    }

    // Cetak matriks
    cout << "\nMatriks 3x3:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    // Hitung jumlah elemen baris genap (baris ke-0 dan ke-2)
    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    // Tampilkan hasil
    cout << "\nJumlah elemen pada baris genap = " << jumlah << endl;

    return 0;
}
