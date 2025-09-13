#include <iostream>
using namespace std;

// Fungsi untuk menukar dua bilangan menggunakan reference
void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    // Input nilai
    cout << "Masukkan nilai pertama: ";
    cin >> x;
    cout << "Masukkan nilai kedua  : ";
    cin >> y;

    // Tampilkan sebelum pertukaran
    cout << "\nSebelum pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Panggil fungsi tukar
    tukar(x, y);

    // Tampilkan sesudah pertukaran
    cout << "\nSesudah pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
