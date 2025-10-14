#include <iostream>
using namespace std;

// Struktur untuk sebuah node dalam tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor untuk inisialisasi node baru
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk memasukkan node baru ke dalam tree
Node* insert(Node* root, int val) {
    // Jika tree kosong, buat node baru sebagai root
    if (root == nullptr) {
        return new Node(val);
    }
    
    // Jika nilai lebih kecil, masukkan ke subtree kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    // Jika nilai lebih besar, masukkan ke subtree kanan
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi untuk mencari nilai terbesar di BST
int findMaxValue(Node* root) {
    // Cek jika tree-nya kosong
    if (root == nullptr) {
        return -1; // Nilai penanda jika tree kosong
    }

    // Pointer untuk menelusuri tree
    Node* current = root;

    // Nilai terbesar selalu ada di paling kanan
    while (current->right != nullptr) {
        current = current->right;
    }

    // Kembalikan data dari node paling kanan
    return current->data;
}

int main() {
    // Inisialisasi root tree
    Node* root = nullptr;
    
    // Masukkan beberapa data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    // Panggil fungsi dan cetak hasilnya
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; 
    return 0;
}