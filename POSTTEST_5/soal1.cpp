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

// Fungsi untuk menghitung total node dalam tree
int countNodes(Node* root) {
    // Base case: jika nodenya kosong, jumlahnya 0
    if (root == nullptr) {
        return 0;
    }
    // Rekursif: hitung node ini (1) + semua node di kiri + semua node di kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Inisialisasi root tree
    Node* root = nullptr;

    // Masukkan beberapa data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    // Panggil fungsi dan cetak hasilnya
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;
    return 0;
}