#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Single Linked List
struct Node {
    string kodePenerbangan;
    string tujuan;
    string status;
    Node* next;
};

// Head list
Node* head = NULL;

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

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
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

    if (head == NULL || posisi == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < posisi - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Posisi sisip melebihi jumlah jadwal, disisipkan di akhir.\n";
            temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        } else {
            newNode->next = temp->next;
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

// Tampilkan semua jadwal
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
        cout << "| 5. Tampilkan Semua Jadwal                                  |\n";
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
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
