#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;     // Data yang disimpan, dalam kasus ini adalah sebuah karakter kurung.
    Node* next;    // Pointer ke Node selanjutnya.
};

void push(Node*& top, char data) {
    // Membuat Node baru yang menyimpan 'data' dan menunjuk ke 'top' yang lama.
    Node* newNode = new Node{data, top};
    // Memperbarui 'top' untuk menunjuk ke Node baru, menjadikannya puncak stack yang baru.
    top = newNode;
}


char pop(Node*& top) {
    // Jika stack kosong, tidak ada yang bisa di-pop.
    if (top == nullptr) return '\0';

    Node* temp = top;                // Simpan Node teratas sementara.
    char poppedValue = temp->data;   // Ambil datanya.
    top = top->next;                 // Pindahkan 'top' ke elemen berikutnya.
    delete temp;                     // Hapus Node teratas yang lama dari memori.
    return poppedValue;              // Kembalikan datanya.
}


bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool areBracketsBalanced(string expr) {
    // Inisialisasi stack kosong.
    Node* stackTop = nullptr;

    // Iterasi melalui setiap karakter dalam string ekspresi.
    for (char c : expr) {
        // Jika karakter adalah kurung buka ('(', '{', '['), push ke stack.
        // Stack digunakan untuk "mengingat" kurung buka yang belum ditemukan pasangannya.
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Jika karakter adalah kurung tutup (')', '}', ']'), lakukan pengecekan.
        else if (c == ')' || c == '}' || c == ']') {
            // KASUS 1: Ada kurung tutup tapi stack kosong.
            // Ini berarti ada kurung tutup tanpa ada kurung buka sebelumnya. Contoh: "())".
            if (stackTop == nullptr) {
                return false; 
            }
            
            // Ambil (pop) kurung buka terakhir dari stack untuk dicocokkan.
            char open = pop(stackTop);
            
            // KASUS 2: Kurung buka dan kurung tutup tidak cocok.
            // Contoh: "{[(])}". Saat bertemu ']', yang di-pop adalah '('. Mereka tidak cocok.
            if (!isMatchingPair(open, c)) {
                return false;
            }
        }
    }

    // KASUS 3: Setelah semua karakter diproses, stack masih berisi elemen.
    // Ini berarti ada kurung buka yang tidak memiliki pasangan penutup. Contoh: "{[()}".
    // Jika stackTop adalah nullptr (kosong), berarti semua pasangan ditemukan.
    bool balanced = (stackTop == nullptr);
    return balanced;
}

// Fungsi utama program.
int main() {
    // Contoh string yang seimbang.
    string expr1 = "{[()]}";
    cout << expr1 << " -> " 
         << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    // Contoh string yang tidak seimbang.
    string expr2 = "{[(])}";
    cout << expr2 << " -> " 
         << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    // Contoh lain yang tidak seimbang (kelebihan kurung buka).
    string expr3 = "(()[";
    cout << expr3 << " -> " 
         << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}