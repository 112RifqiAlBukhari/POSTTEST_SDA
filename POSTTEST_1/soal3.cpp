#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 4; // jumlah mahasiswa
    Mahasiswa mhs[N];

    // Input data mahasiswa
    cout << "Input data " << N << " mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        getline(cin >> ws, mhs[i].nama); // ws untuk mengabaikan spasi/enter
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    // Urutkan berdasarkan IPK (ascending) pakai bubble sort sederhana
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }

    // Tampilkan data setelah diurutkan
    cout << "\nData Mahasiswa setelah diurutkan (berdasarkan IPK ascending):\n";
    for (int i = 0; i < N; i++) {
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM  : " << mhs[i].nim << endl;
        cout << "IPK  : " << mhs[i].ipk << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
