#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk menyimpan data pembelian tiket
struct Node {
    string nama;
    int jumlahTiket;
    Node* next;
};

// Pointer depan dan belakang Queue
Node* front = NULL;
Node* rear = NULL;

// Fungsi untuk mengecek apakah Queue kosong
bool isEmpty() {
    return (front == NULL && rear == NULL);
}

// Fungsi untuk menambahkan pembeli ke dalam antrian (Enqueue)
void enqueue(string nama, int jumlahTiket) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->jumlahTiket = jumlahTiket;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Pembeli " << nama << " dengan " << jumlahTiket 
         << " tiket berhasil masuk antrian.\n";
}

// Fungsi untuk memproses pembelian tiket (Dequeue)
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong, tidak ada pembeli.\n";
        return;
    }

    Node* temp = front;
    cout << "Pembeli " << front->nama << " membeli " 
         << front->jumlahTiket << " tiket. (Keluar dari antrian)\n";

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    delete temp;
}

// Fungsi untuk melihat siapa pembeli berikutnya
void peek() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
    } else {
        cout << "Pembeli berikutnya: " << front->nama 
             << " dengan " << front->jumlahTiket << " tiket.\n";
    }
}

// Fungsi untuk menampilkan seluruh antrian pembeli
void display() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    Node* temp = front;
    cout << "\n=== Daftar Antrian Pembelian Tiket ===\n";
    while (temp != NULL) {
        cout << "- " << temp->nama << " ("
             << temp->jumlahTiket << " tiket)\n";
        temp = temp->next;
    }
}

// Main program
int main() {
    int pilihan, jumlah;
    string nama;

    do {
        cout << "\n=== SISTEM ANTRIAN PEMBELIAN TIKET ===\n";
        cout << "1. Tambah Antrian Pembeli (Enqueue)\n";
        cout << "2. Proses Pembeli (Dequeue)\n";
        cout << "3. Lihat Pembeli Berikutnya (Peek)\n";
        cout << "4. Tampilkan Semua Antrian (Display)\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pembeli: ";
                cin >> nama;
                cout << "Jumlah tiket: ";
                cin >> jumlah;
                enqueue(nama, jumlah);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
