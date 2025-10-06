#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};


void sortedInsert(Node*& head_ref, int data) {
    // 1. Buat node baru yang akan disisipkan.
    Node* newNode = new Node{data, nullptr, nullptr};

    // --- KASUS 1: List masih kosong ---
    // Jika head_ref adalah nullptr, berarti ini adalah node pertama.
    if (head_ref == nullptr) {
        // Karena ini satu-satunya node, 'next' dan 'prev'-nya menunjuk ke dirinya sendiri.
        newNode->next = newNode;
        newNode->prev = newNode;
        // Head dari list sekarang adalah node baru ini.
        head_ref = newNode;
        return; // Selesai.
    }

    // Ambil referensi ke head dan tail (node terakhir) untuk mempermudah.
    // Dalam circular list, tail adalah node sebelum head.
    Node* head = head_ref;
    Node* tail = head->prev;

    // --- KASUS 2: Node baru harus menjadi head baru (nilainya paling kecil)
    // Jika data baru lebih kecil dari data di head saat ini.
    if (data < head->data) {
        // Atur pointer untuk newNode:
        newNode->next = head; // newNode menunjuk ke head lama.
        newNode->prev = tail; // newNode menunjuk ke tail lama.
        
        // Perbarui pointer dari node yang sudah ada:
        tail->next = newNode; // Tail lama sekarang menunjuk ke newNode.
        head->prev = newNode; // Head lama sekarang menunjuk ke newNode.
        
        // Pindahkan head_ref untuk menunjuk ke newNode, karena ini adalah elemen terkecil.
        head_ref = newNode;
        return; // Selesai.
    }

    // --- KASUS 3: Menyisipkan di tengah atau di akhir list ---
    // Kita perlu mencari posisi yang tepat untuk menyisipkan node baru.
    // 'current' akan berjalan dari head sampai menemukan posisi yang tepat.
    Node* current = head;

    // Loop berhenti ketika:
    // 1. 'current->next' adalah head (sudah mencapai akhir list).
    // 2. Nilai 'current->next->data' lebih besar atau sama dengan data baru.
    while (current->next != head && current->next->data < data) {
        current = current->next;
    }

    // Setelah loop selesai, posisi yang tepat untuk newNode adalah di antara 'current' dan 'current->next'.
    // 

    // Atur pointer untuk newNode:
    newNode->next = current->next; // 'next' dari newNode menunjuk ke node setelah 'current'.
    newNode->prev = current;       // 'prev' dari newNode menunjuk ke 'current'.

    // Perbarui pointer dari node yang sudah ada di list untuk menyambung ke newNode:
    current->next->prev = newNode; // Node setelah 'current' sekarang menunjuk balik ke newNode.
    current->next = newNode;       // Node 'current' sekarang menunjuk ke newNode.
}


void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node* current = head_ref;
    // Menggunakan do-while loop adalah cara umum untuk traversals circular list,
    // karena ini memastikan loop berjalan setidaknya sekali (untuk mencetak head),
    // bahkan jika hanya ada satu elemen di list.
    do {
        cout << current->data << " <-> ";
        current = current->next;
    } while (current != head_ref); // Loop berhenti ketika sudah kembali ke head.
    cout << " (kembali ke " << head_ref->data << ")" << endl;
}

// Fungsi utama program
int main() {
    // Inisialisasi list kosong.
    Node* head = nullptr;

    // Menyisipkan beberapa angka secara tidak berurutan.
    // Fungsi sortedInsert akan memastikan list tetap terurut setiap saat.
    sortedInsert(head, 30);
    printList(head); // List: 30
    
    sortedInsert(head, 10);
    printList(head); // List: 10 30
    
    sortedInsert(head, 40);
    printList(head); // List: 10 30 40
    
    sortedInsert(head, 20);
    printList(head); // List: 10 20 30 40

    cout << "\nHasil akhir Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}