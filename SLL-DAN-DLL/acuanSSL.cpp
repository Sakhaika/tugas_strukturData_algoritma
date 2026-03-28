#include <iostream>
using namespace std;

// ===================== NODE LINKED LIST =====================
struct mataKuliah {
    string namaMatkul;
    int nilaiUts, nilaiUas, nilaiTugas;
    mataKuliah* next; // pointer ke node berikutnya
};

struct mahasiswa {
    long long nim;
    int semester;
    string nama, prodi;
    mataKuliah* head; // kepala linked list matkul
};

// ===================== FUNGSI MUTU HURUF =====================
string mutuHuruf(int nilaiTugas, int nilaiUts, int nilaiUas) {
    float nilaiHuruf = (nilaiTugas + nilaiUts + nilaiUas) / 3.0f;
    if      (nilaiHuruf >= 81)   return "A  | Sangat Istimewa";
    else if (nilaiHuruf >= 76)   return "A- | Istimewa";
    else if (nilaiHuruf >= 72)   return "B+ | Lebih dari Baik";
    else if (nilaiHuruf >= 68)   return "B  | Baik";
    else if (nilaiHuruf >= 64)   return "B- | Cukup Baik";
    else if (nilaiHuruf >= 60)   return "C+ | Lebih dari Cukup";
    else if (nilaiHuruf >= 56)   return "C  | Cukup";
    else if (nilaiHuruf >= 41)   return "D  | Kurang";
    else if (nilaiHuruf >= 1)    return "E  | Gagal";
    else                          return "Nilai tidak valid";
}

// ===================== BUAT NODE BARU =====================
mataKuliah* buatNode(string nama, int tugas, int uts, int uas) {
    mataKuliah* baru = new mataKuliah();
    baru->namaMatkul  = nama;
    baru->nilaiTugas  = tugas;
    baru->nilaiUts    = uts;
    baru->nilaiUas    = uas;
    baru->next        = nullptr;
    return baru;
}

// ===================== INPUT DATA SATU MATKUL =====================
mataKuliah* inputSatuMatkul(int nomor) {
    string nama;
    int tugas, uts, uas;
    cout << "  Nama Mata Kuliah : "; cin >> nama;
    cout << "  Nilai Tugas      : "; cin >> tugas;
    cout << "  Nilai UTS        : "; cin >> uts;
    cout << "  Nilai UAS        : "; cin >> uas;
    return buatNode(nama, tugas, uts, uas);
}

// ===================== HITUNG PANJANG LIST =====================
int panjangList(mataKuliah* head) {
    int count = 0;
    mataKuliah* curr = head;
    while (curr != nullptr) { count++; curr = curr->next; }
    return count;
}

// ============================================================
//                  OPERASI TAMBAH
// ============================================================

// TAMBAH DEPAN
void tambahDepan(mahasiswa &mhs) {
    cout << "\n[+] Tambah Mata Kuliah di DEPAN\n";
    mataKuliah* baru = inputSatuMatkul(1);
    baru->next = mhs.head;
    mhs.head   = baru;
    cout << ">> Matkul berhasil ditambahkan di depan!\n";
}

// TAMBAH BELAKANG
void tambahBelakang(mahasiswa &mhs) {
    cout << "\n[+] Tambah Mata Kuliah di BELAKANG\n";
    mataKuliah* baru = inputSatuMatkul(panjangList(mhs.head) + 1);

    if (mhs.head == nullptr) {
        mhs.head = baru;
    } else {
        mataKuliah* curr = mhs.head;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = baru;
    }
    cout << ">> Matkul berhasil ditambahkan di belakang!\n";
}

// TAMBAH TENGAH (setelah posisi ke-N)
void tambahTengah(mahasiswa &mhs) {
    int total = panjangList(mhs.head);
    if (total < 2) {
        cout << ">> List terlalu pendek untuk tambah tengah. Gunakan tambah depan/belakang.\n";
        return;
    }

    int posisi;
    cout << "\n[+] Tambah Mata Kuliah di TENGAH\n";
    cout << "    Sisipkan setelah posisi ke- (1 s/d " << total - 1 << "): ";
    cin >> posisi;

    if (posisi < 1 || posisi >= total) {
        cout << ">> Posisi tidak valid!\n";
        return;
    }

    mataKuliah* baru = inputSatuMatkul(posisi + 1);
    mataKuliah* curr = mhs.head;

    for (int i = 1; i < posisi; i++) curr = curr->next;

    baru->next = curr->next;
    curr->next = baru;
    cout << ">> Matkul berhasil disisipkan di posisi ke-" << posisi + 1 << "!\n";
}

// ============================================================
//                  OPERASI HAPUS
// ============================================================

// HAPUS DEPAN
void hapusDepan(mahasiswa &mhs) {
    if (mhs.head == nullptr) {
        cout << ">> Tidak ada matkul untuk dihapus!\n";
        return;
    }
    mataKuliah* hapus = mhs.head;
    mhs.head = mhs.head->next;
    cout << ">> Matkul \"" << hapus->namaMatkul << "\" berhasil dihapus dari depan!\n";
    delete hapus;
}

// HAPUS BELAKANG
void hapusBelakang(mahasiswa &mhs) {
    if (mhs.head == nullptr) {
        cout << ">> Tidak ada matkul untuk dihapus!\n";
        return;
    }

    // Hanya ada satu node
    if (mhs.head->next == nullptr) {
        cout << ">> Matkul \"" << mhs.head->namaMatkul << "\" berhasil dihapus dari belakang!\n";
        delete mhs.head;
        mhs.head = nullptr;
        return;
    }

    mataKuliah* curr = mhs.head;
    while (curr->next->next != nullptr) curr = curr->next;

    cout << ">> Matkul \"" << curr->next->namaMatkul << "\" berhasil dihapus dari belakang!\n";
    delete curr->next;
    curr->next = nullptr;
}

// HAPUS TENGAH (posisi ke-N)
void hapusTengah(mahasiswa &mhs) {
    int total = panjangList(mhs.head);
    if (total < 3) {
        cout << ">> List terlalu pendek untuk hapus tengah!\n";
        return;
    }

    int posisi;
    cout << "\n[-] Hapus Mata Kuliah di TENGAH\n";
    cout << "    Hapus posisi ke- (2 s/d " << total - 1 << "): ";
    cin >> posisi;

    if (posisi < 2 || posisi >= total) {
        cout << ">> Posisi tidak valid!\n";
        return;
    }

    mataKuliah* curr = mhs.head;
    for (int i = 1; i < posisi - 1; i++) curr = curr->next;

    mataKuliah* hapus = curr->next;
    curr->next = hapus->next;
    cout << ">> Matkul \"" << hapus->namaMatkul << "\" berhasil dihapus dari posisi ke-" << posisi << "!\n";
    delete hapus;
}

// ============================================================
//                  TAMPILKAN SEMUA MATKUL
// ============================================================
void tampilkanMatkul(mahasiswa &mhs) {
    if (mhs.head == nullptr) {
        cout << ">> Belum ada mata kuliah.\n";
        return;
    }

    cout << "\n========== Data Mata Kuliah " << mhs.nama << " ==========\n";
    mataKuliah* curr = mhs.head;
    int i = 1;
    while (curr != nullptr) {
        cout << "Mata Kuliah ke-" << i << endl;
        cout << "  Nama     : " << curr->namaMatkul << endl;
        cout << "  Tugas    : " << curr->nilaiTugas << endl;
        cout << "  UTS      : " << curr->nilaiUts << endl;
        cout << "  UAS      : " << curr->nilaiUas << endl;
        cout << "  Mutu     : " << mutuHuruf(curr->nilaiTugas, curr->nilaiUts, curr->nilaiUas) << endl;
        cout << "--------------------------------------------\n";
        curr = curr->next;
        i++;
    }
}

// ============================================================
//                       MAIN MENU
// ============================================================
int main() {
    mahasiswa mhs;
    mhs.head = nullptr; // inisialisasi linked list kosong

    cout << "=========================================\n";
    cout << "  Selamat Datang di Program Grade PNJ   \n";
    cout << "=========================================\n";
    cout << "Nama mahasiswa  : "; cin >> mhs.nama;
    cout << "NIM mahasiswa   : "; cin >> mhs.nim;
    cout << "Program studi   : "; cin >> mhs.prodi;
    cout << "Semester        : "; cin >> mhs.semester;

    int pilihan;
    do {
        cout << "\n========== MENU LINKED LIST MATKUL ==========\n";
        cout << "  [1] Tambah Matkul di Depan\n";
        cout << "  [2] Tambah Matkul di Belakang\n";
        cout << "  [3] Tambah Matkul di Tengah\n";
        cout << "  [4] Hapus  Matkul di Depan\n";
        cout << "  [5] Hapus  Matkul di Belakang\n";
        cout << "  [6] Hapus  Matkul di Tengah\n";
        cout << "  [7] Tampilkan Semua Matkul\n";
        cout << "  [0] Keluar\n";
        cout << "=============================================\n";
        cout << "Pilihan: "; cin >> pilihan;

        switch (pilihan) {
            case 1: tambahDepan(mhs);    break;
            case 2: tambahBelakang(mhs); break;
            case 3: tambahTengah(mhs);   break;
            case 4: hapusDepan(mhs);     break;
            case 5: hapusBelakang(mhs);  break;
            case 6: hapusTengah(mhs);    break;
            case 7: tampilkanMatkul(mhs); break;
            case 0: cout << ">> Terima kasih!\n"; break;
            default: cout << ">> Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}