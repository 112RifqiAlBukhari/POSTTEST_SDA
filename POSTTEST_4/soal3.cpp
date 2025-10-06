#include <iostream>
#include <string>

using namespace std;

struct Node {
    string document; // Data yang disimpan, yaitu nama dokumen.
    Node* next;      // Pointer ke node selanjutnya dalam antrian.
};

void enqueue(Node*& front, Node*& rear, string document) {
    // 1. Buat node baru untuk dokumen. Pointer 'next' diinisialisasi ke nullptr.
    Node* newNode = new Node{document, nullptr};

    // 2. Cek apakah antrian saat ini kosong.
    if (front == nullptr) {
        // Jika kosong, node baru ini menjadi satu-satunya elemen.
        // Maka, 'front' dan 'rear' keduanya menunjuk ke node baru ini.
        front = rear = newNode;
    } else {
        // Jika tidak kosong:
        // a. Sambungkan node terakhir yang ada saat ini (yang ditunjuk oleh 'rear')
        //    ke node yang baru dibuat.
        rear->next = newNode;
        
        // b. Pindahkan pointer 'rear' untuk menunjuk ke node baru,
        //    karena sekarang node baru ini adalah elemen paling belakang.
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    // Cek jika antrian kosong, tidak ada yang bisa diambil.
    if (front == nullptr) {
        return "Antrian kosong"; // Memberi pesan yang lebih jelas.
    }

    // 1. Simpan alamat node terdepan ke pointer sementara (temp).
    Node* temp = front;
    
    // 2. Ambil data (nama dokumen) dari node terdepan.
    string doc = temp->document;
    
    // 3. Pindahkan pointer 'front' ke elemen berikutnya dalam antrian.
    front = front->next;
    
    // KASUS KHUSUS: Jika setelah penghapusan 'front' menjadi nullptr,
    // artinya antrian kini menjadi kosong.
    // Maka, 'rear' juga harus diatur ke nullptr untuk menandakan antrian benar-benar kosong.
    if (front == nullptr) {
        rear = nullptr;
    }
    
    // 4. Hapus node terdepan yang lama dari memori untuk mencegah kebocoran memori.
    delete temp;
    
    // 5. Kembalikan nama dokumen yang telah diproses.
    return doc;
}


void processAllDocuments(Node*& front, Node*& rear) {
    // Loop berjalan selama antrian masih memiliki isi (front tidak nullptr).
    while (front != nullptr) {
        // Ambil dokumen dari depan, proses (cetak ke layar), dan hapus dari antrian.
        cout << "Memproses: " << dequeue(front, rear) << endl;
    }
    cout << "Semua dokumen telah diproses." << endl;
}

// Fungsi utama program
int main() {
    // Inisialisasi antrian kosong.
    // 'front' dan 'rear' harus nullptr untuk menandakan tidak ada elemen sama sekali.
    Node* front = nullptr;
    Node* rear = nullptr;

    // Menambahkan beberapa dokumen ke dalam antrian printer.
    // Dokumen masuk sesuai urutan: Document1 -> laporan -> Presentasi
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "laporan.docx");
    enqueue(front, rear, "Presentasi.pptx");

    // Memulai simulasi pemrosesan.
    // Dokumen akan diproses sesuai urutan kedatangan (FIFO).
    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}