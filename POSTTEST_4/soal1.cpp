#include <iostream>
#include <string>

using namespace std;


struct Node {
    char data;     // Variabel untuk menyimpan karakter data.
    Node* next;    // Pointer yang menunjuk ke Node selanjutnya dalam stack.
};

void push(Node*& top, char data) {
    // Membuat Node baru dan mengalokasikan memori untuknya.
    // Node baru ini akan menyimpan 'data' dan menunjuk ke 'top' yang lama sebagai elemen berikutnya.
    Node* newNode = new Node{data, top};
    
    // Memperbarui 'top' sehingga sekarang menunjuk ke Node yang baru dibuat.
    top = newNode;
};

char pop(Node*& top) {
    // Memeriksa apakah stack kosong. Jika ya, tidak ada yang bisa di-pop.
    if (top == nullptr) return '\0';

    // Menyimpan alamat Node teratas saat ini ke dalam pointer sementara (temp).
    Node* temp = top;
    
    // Mengambil data (karakter) dari Node teratas.
    char poppedValue = temp->data;
    
    // Memindahkan pointer 'top' ke Node berikutnya dalam urutan.
    top = top->next;
    
    // Menghapus Node teratas yang lama dari memori.
    delete temp;
    
    // Mengembalikan karakter yang telah diambil.
    return poppedValue;
}

string reverseString(string s) {
    // Inisialisasi pointer 'stackTop' sebagai null, menandakan stack masih kosong.
    Node* stackTop = nullptr;
    
    // Menyiapkan string kosong untuk menampung hasil pembalikan.
    string reversed = "";

    // Langkah 1: Push setiap karakter dari string input ke dalam stack.
    // Loop akan membaca setiap karakter 'c' dalam string 's'.
    for (char c : s) {
        push(stackTop, c);
    }

    // Langkah 2: Pop setiap karakter dari stack dan tambahkan ke string hasil.
    // Loop berjalan selama stack belum kosong (stackTop bukan nullptr).
    while (stackTop != nullptr) {
        // Mengambil karakter dari puncak stack dan menambahkannya ke akhir string 'reversed'.
        reversed += pop(stackTop);
    }

    // Mengembalikan string yang sudah dibalik.
    return reversed;
}

// Fungsi utama program.
int main() {
    // String yang akan dijadikan contoh untuk dibalik.
    string text = "Struktur Data";
    
    // Menampilkan string asli ke konsol.
    cout << "Teks asli: " << text << endl;
    
    // Memanggil fungsi reverseString untuk membalikkan teks dan langsung menampilkannya.
    cout << "Teks terbalik: " << reverseString(text) << endl;
    
    return 0;
}