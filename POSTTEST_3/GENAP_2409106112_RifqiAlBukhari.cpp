#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Double Linked List
struct Node {
    string kodePenerbangan;
    string tujuan;
    string status;
    Node* next;
    Node* prev;
};

// Head dan Tail list
Node* head = NULL;
Node* tail = NULL;

// Variabel global untuk generate kode unik
int counterKode = 0;
string baseKode = "JT-112"; // Sesuai NIM

// Fungsi membuat kode penerbangan unik
string generateKode() {
    if (counterKode == 0) {
        counterKode++;
        return baseKode;
    } else {
        return baseKode + "-" + to_string(counterKode++);
    }
}

// Fungsi pilih status dari daftar
string pilihStatus() {
    int pilihan;
    cout << "Pilih status penerbangan:\n";
    cout << "1. Delay\n";
    cout << "2. Segera Berangkat\n";
    cout << "3. Berangkat\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: return "Delay";
        case 2: return "Segera Berangkat";
        case 3: return "Berangkat";
        default: 
            cout << "Pilihan tidak valid, otomatis 'Delay'.\n";
            return "Delay";
    }
}

// Tambah Jadwal di akhir
void tambahJadwal(string tujuan) {
    Node* newNode = new Node;
    newNode->kodePenerbangan = generateKode();
    newNode->tujuan = tujuan;
    newNode->status = pilihStatus();
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "Jadwal berhasil ditambahkan!\n";
}

// Sisipkan jadwal di posisi tertentu (posisi = digit terakhir nim + 1 = 3)
void sisipJadwal(string tujuan) {
    int posisi = 3; 
    Node* newNode = new Node;
    newNode->kodePenerbangan = generateKode();
    newNode->tujuan = tujuan;
    newNode->status = pilihStatus();
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL || posisi == 1) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        if (tail == NULL) tail = newNode;
    } else {
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < posisi - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL) {
            // Sisip di akhir
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    cout << "Jadwal berhasil disisipkan!\n";
}

// Hapus jadwal paling awal
void hapusAwal() {
    if (head == NULL) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    else tail = NULL;
    cout << "Jadwal " << temp->kodePenerbangan << " berhasil dihapus.\n";
    delete temp;
}

// Update status penerbangan
void updateStatus(string kode) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->kodePenerbangan == kode) {
            cout << "Update status penerbangan:\n";
            temp->status = pilihStatus();
            cout << "Status penerbangan " << kode << " berhasil diperbarui!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan.\n";
}

// Tampilkan semua jadwal dari depan
void tampilkanJadwal() {
    if (head == NULL) {
        cout << "Belum ada jadwal penerbangan.\n";
        return;
    }
    Node* temp = head;
    cout << "+---------------------------------------------------------+\n";
    cout << "|                   DAFTAR JADWAL PENERBANGAN            |\n";
    cout << "+---------------------------------------------------------+\n";
    while (temp != NULL) {
        cout << "Kode   : " << temp->kodePenerbangan << endl;
        cout << "Tujuan : " << temp->tujuan << endl;
        cout << "Status : " << temp->status << endl;
        cout << "-----------------------------------------------------------\n";
        temp = temp->next;
    }
}

// Tampilkan semua jadwal dari belakang
void tampilkanJadwalBelakang() {
    if (tail == NULL) {
        cout << "Belum ada jadwal penerbangan.\n";
        return;
    }
    Node* temp = tail;
    cout << "+---------------------------------------------------------+\n";
    cout << "|         DAFTAR JADWAL PENERBANGAN (DARI BELAKANG)       |\n";
    cout << "+---------------------------------------------------------+\n";
    while (temp != NULL) {
        cout << "Kode   : " << temp->kodePenerbangan << endl;
        cout << "Tujuan : " << temp->tujuan << endl;
        cout << "Status : " << temp->status << endl;
        cout << "-----------------------------------------------------------\n";
        temp = temp->prev;
    }
}

// Tampilkan detail data berdasarkan kode atau tujuan
void tampilkanDetail() {
    if (head == NULL) {
        cout << "Belum ada jadwal penerbangan.\n";
        return;
    }
    string input;
    cout << "Masukkan kode penerbangan atau tujuan: ";
    getline(cin >> ws, input);
    Node* temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->kodePenerbangan == input || temp->tujuan == input) {
            cout << "Detail Jadwal:\n";
            cout << "Kode   : " << temp->kodePenerbangan << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) cout << "Data tidak ditemukan.\n";
}

// Menu utama
int main() {
    int pilihan;
    string tujuan, kode;

    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|           FLIGHT SCHEDULE SYSTEM                           |\n";
        cout << "|     Rifqi Al Bukhari - 240911611112                        |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Update Status Penerbangan                               |\n";
        cout << "| 5. Tampilkan Semua Jadwal (Depan)                          |\n";
        cout << "| 6. Tampilkan Semua Jadwal (Belakang)                       |\n";
        cout << "| 7. Tampilkan Detail Jadwal                                 |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan tujuan: ";
                getline(cin >> ws, tujuan);
                tambahJadwal(tujuan);
                break;
            case 2:
                cout << "Masukkan tujuan: ";
                getline(cin >> ws, tujuan);
                sisipJadwal(tujuan);
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                cout << "Masukkan kode penerbangan yang ingin diupdate: ";
                getline(cin >> ws, kode);
                updateStatus(kode);
                break;
            case 5:
                tampilkanJadwal();
                break;
            case 6:
                tampilkanJadwalBelakang();
                break;
            case 7:
                tampilkanDetail();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}