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

// Fungsi untuk traversal post-order (Left, Right, Root)
void postOrderTraversal(Node* root) {
    // Base case: berhenti jika nodenya kosong
    if (root == nullptr) {
        return;
    }

    // 1. Kunjungi subtree kiri dulu
    postOrderTraversal(root->left);

    // 2. Lanjut ke subtree kanan
    postOrderTraversal(root->right);

    // 3. Terakhir, cetak data root
    cout << root->data << " ";
}

int main() {
    // Inisialisasi root tree
    Node* root = nullptr;
    
    // Masukkan beberapa data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Post-order traversal dari tree adalah: ";
    // Panggil fungsi traversal untuk mencetak hasilnya
    postOrderTraversal(root);
    cout << endl;
    
    return 0;
}