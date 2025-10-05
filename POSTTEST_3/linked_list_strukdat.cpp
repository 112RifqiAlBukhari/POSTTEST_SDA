#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Pointer depan dan belakang Queue
Node* front = NULL;
Node* rear = NULL;

// Fungsi untuk mengecek apakah Queue kosong
bool isEmpty() {
    return (front == NULL && rear == NULL);
}

// Fungsi untuk menambahkan elemen ke dalam Queue (Enqueue)
void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " berhasil ditambahkan ke dalam Queue.\n";
}

// Fungsi untuk menghapus elemen dari Queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong, tidak ada elemen yang bisa dihapus.\n";
        return;
    }

    Node* temp = front;
    cout << "Elemen " << front->data << " dihapus dari Queue.\n";

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    delete temp;
}

// Fungsi untuk melihat elemen terdepan Queue
void peek() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
    } else {
        cout << "Elemen terdepan Queue adalah: " << front->data << endl;
    }
}

// Fungsi untuk menampilkan seluruh elemen Queue
void display() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }

    Node* temp = front;
    cout << "Isi Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main program
int main() {
    int pilihan, nilai;

    do {
        cout << "\n=== IMPLEMENTASI QUEUE DENGAN LINKED LIST ===\n";
        cout << "1. Enqueue (Tambah data)\n";
        cout << "2. Dequeue (Hapus data)\n";
        cout << "3. Peek (Lihat data terdepan)\n";
        cout << "4. Display (Tampilkan isi queue)\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueue(nilai);
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
