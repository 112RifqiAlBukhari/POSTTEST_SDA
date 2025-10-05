#include <iostream>
using namespace std;

// Maksimal ukuran Queue
#define MAX 5

// Deklarasi Queue
struct Queue {
    int data[MAX];
    int front;
    int rear;
};

// Inisialisasi Queue
void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

// Mengecek apakah Queue kosong
bool isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

// Mengecek apakah Queue penuh
bool isFull(Queue q) {
    return (q.rear == MAX - 1);
}

// Menambahkan elemen ke dalam Queue (Enqueue)
void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa menambahkan data." << endl;
    } else {
        if (isEmpty(q)) {
            q.front = 0;
            q.rear = 0;
        } else {
            q.rear++;
        }
        q.data[q.rear] = value;
        cout << "Data " << value << " berhasil ditambahkan ke Queue." << endl;
    }
}

// Menghapus elemen dari Queue (Dequeue)
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak ada data yang bisa dihapus." << endl;
    } else {
        cout << "Data " << q.data[q.front] << " dihapus dari Queue." << endl;
        if (q.front == q.rear) {
            // Jika hanya ada satu elemen
            q.front = q.rear = -1;
        } else {
            q.front++;
        }
    }
}

// Melihat isi Queue
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Isi Queue: ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.data[i] << " ";
        }
        cout << endl;
    }
}

// Program Utama
int main() {
    Queue q;
    initQueue(q);

    int pilihan, nilai;

    do {
        cout << "\n=== PROGRAM QUEUE MENGGUNAKAN ARRAY ===" << endl;
        cout << "1. Enqueue (Tambah Data)" << endl;
        cout << "2. Dequeue (Hapus Data)" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> nilai;
                enqueue(q, nilai);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
