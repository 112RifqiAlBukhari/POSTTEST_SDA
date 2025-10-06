#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};


void exchangeHeadAndTail(Node*& head_ref) {
    // --- KASUS DASAR: Tidak ada yang perlu ditukar ---
    // Jika list kosong atau hanya punya satu elemen, tidak ada yang bisa ditukar.
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    // --- KASUS KHUSUS: List hanya punya dua elemen ---
    // Jika list hanya punya dua elemen, menukar head dan tail cukup dengan
    // memindahkan pointer head_ref ke elemen berikutnya (yaitu tail).
    // Pointer next/prev mereka sudah saling menunjuk dengan benar.
    if (head_ref->next == head_ref->prev) {
        head_ref = head_ref->next;
        return;
    }
    
    // --- KASUS UMUM: List punya lebih dari dua elemen ---

    // 1. Simpan pointer ke node-node penting untuk menghindari kebingungan.
    //    Visualisasi Awal:  ... <=> tailPrev <=> tail <=> head <=> headNext <=> ...
    Node* head = head_ref;            // Pointer ke head lama (misal, node 1)
    Node* tail = head_ref->prev;      // Pointer ke tail lama (misal, node 5)
    Node* headNext = head->next;      // Pointer ke elemen setelah head (misal, node 2)
    Node* tailPrev = tail->prev;      // Pointer ke elemen sebelum tail (misal, node 4)
    

    // 2. Hubungkan head baru (tail lama) ke list.
    //    Sekarang, tail (node 5) akan menjadi head baru.
    tail->next = headNext;       // 'next' dari head baru (5) menunjuk ke elemen kedua (2).
    headNext->prev = tail;       // 'prev' dari elemen kedua (2) menunjuk balik ke head baru (5).
                                 // Hasil sementara: ... 4 <=> 5 <=> 2 <=> 3 ...
    
    // 3. Hubungkan tail baru (head lama) ke list.
    //    Sekarang, head (node 1) akan menjadi tail baru.
    head->prev = tailPrev;       // 'prev' dari tail baru (1) menunjuk ke elemen sebelum-terakhir (4).
    tailPrev->next = head;       // 'next' dari elemen sebelum-terakhir (4) menunjuk ke tail baru (1).
                                 // Hasil sementara: ... 5 <=> 2 <=> 3 <=> 4 <=> 1 ...

    // 4. Perbarui pointer circular utama.
    //    Head baru dan tail baru harus saling menunjuk untuk menjaga sifat circular.
    tail->prev = head;           // 'prev' dari head baru (5) menunjuk ke tail baru (1).
    head->next = tail;           // 'next' dari tail baru (1) menunjuk ke head baru (5).
    
    // 5. Perbarui head_ref untuk menunjuk ke head yang baru.
    head_ref = tail;
}


void insertEnd(Node*& head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}


void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node* current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

// Fungsi utama program
int main() {
    Node* head = nullptr;

    // Buat list dengan urutan: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head); // Output: 1 2 3 4 5

    // Panggil fungsi untuk menukar head (1) dan tail (5).
    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head); // Output yang diharapkan: 5 2 3 4 1

    // Tes dengan 2 elemen
    Node* head2 = nullptr;
    insertEnd(head2, 10);
    insertEnd(head2, 20);
    cout << "\nTest dengan 2 elemen (sebelum): ";
    printList(head2); // Output: 10 20
    exchangeHeadAndTail(head2);
    cout << "Test dengan 2 elemen (setelah): ";
    printList(head2); // Output: 20 10

    return 0;
}