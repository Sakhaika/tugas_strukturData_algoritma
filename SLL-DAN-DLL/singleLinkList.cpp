#include <iostream>
using namespace std;

struct mataKuliah {
    string namaMatkul;
    int nilaiUts, nilaiUas, nilaiTugas;
};

struct Node {
    mataKuliah matKul;
    Node* next;
};

struct mahasiswa {
    long long nim;
    int semester;
    string nama, prodi;
    Node* head;
    Node* tail;
    int jumlahMatkul;
};

// FIX 2: Rumus berbobot (Tugas 30%, UTS 35%, UAS 35%)
string mutuHuruf(int nilaiTugas, int nilaiUts, int nilaiUas){
    float nilaiHuruf = (nilaiTugas * 0.30f) + (nilaiUts * 0.35f) + (nilaiUas * 0.35f);

    if (nilaiHuruf >= 81)
        return "A, Sangat Istimewa";       
    else if (nilaiHuruf >= 76)
        return "A-, Istimewa";             
    else if (nilaiHuruf >= 72)
        return "B+, Lebih dari Baik";
    else if (nilaiHuruf >= 68)
        return "B, Baik";
    else if (nilaiHuruf >= 64)
        return "B-, Cukup Baik";
    else if (nilaiHuruf >= 60)
        return "C+, Lebih dari Cukup";
    else if (nilaiHuruf >= 56)
        return "C, Cukup";
    else if (nilaiHuruf >= 41)
        return "D, Kurang";
    else if (nilaiHuruf >= 1)
        return "E, Gagal";
    else
        return "Nilai tidak valid";
}

Node* buatNode(mataKuliah mk) {
    Node* baru = new Node;
    baru->matKul = mk;
    baru->next   = nullptr;
    return baru;
}

void inisialisasi(mahasiswa &mhs) {
    mhs.head         = nullptr;
    mhs.tail         = nullptr;
    mhs.jumlahMatkul = 0;
}

bool kosong(mahasiswa &mhs) {
    return mhs.head == nullptr;
}

// FIX 3: Parameter "ke" dihapus, nomor urut ditampilkan setelah insert (saat tampil)
mataKuliah inputSatuMatkul(){
    mataKuliah mk;
    cout << "Nama Mata Kuliah: ";
    cin.ignore();
    getline(cin, mk.namaMatkul);
    cout << "Nilai Tugas    : ";
    cin >> mk.nilaiTugas;
    cout << "Nilai UTS      : ";
    cin >> mk.nilaiUts;
    cout << "Nilai UAS      : ";
    cin >> mk.nilaiUas;
    return mk;
}

void tampilkanSatuMatkul(mataKuliah mk, int ke){
    cout << "\n  Mata Kuliah ke-" << ke << endl;
    cout << "  Nama Mata Kuliah : " << mk.namaMatkul << endl;
    cout << "  Nilai Tugas      : " << mk.nilaiTugas << endl;
    cout << "  Nilai UTS        : " << mk.nilaiUts << endl;
    cout << "  Nilai UAS        : " << mk.nilaiUas << endl;
    cout << "  Mutu Huruf       : " << mutuHuruf(mk.nilaiTugas, mk.nilaiUts, mk.nilaiUas) << endl;
}

void tampilkanSemuaMatkul(mahasiswa &mhs) {
    if (kosong(mhs)) {
        cout << "  Belum ada mata kuliah yang diinput.\n";
        return;
    }
    Node* curr = mhs.head;
    int ke = 1;
    cout << "\n========== Data Mata Kuliah ==========\n";
    while (curr != nullptr) {
        tampilkanSatuMatkul(curr->matKul, ke);
        curr = curr->next;
        ke++;
    }
}

void tambahDepan(mahasiswa &mhs) {
    cout << "\n[+] Tambah Mata Kuliah di DEPAN\n";
    mataKuliah mk   = inputSatuMatkul();
    Node*      baru = buatNode(mk);

    if (kosong(mhs)) {
        mhs.head = baru;
        mhs.tail = baru;
    } else {
        baru->next = mhs.head;
        mhs.head   = baru;
    }
    mhs.jumlahMatkul++;
    cout << "  [OK] Mata kuliah berhasil ditambahkan di depan.\n";
}

void tambahBelakang(mahasiswa &mhs) {
    mataKuliah mk   = inputSatuMatkul();
    Node*      baru = buatNode(mk);

    if (kosong(mhs)) {
        mhs.head = baru;
        mhs.tail = baru;
    } else {
        mhs.tail->next = baru;
        mhs.tail       = baru;
    }
    mhs.jumlahMatkul++;
    cout << "  [OK] Mata kuliah berhasil ditambahkan di belakang.\n";
}

void tambahTengah(mahasiswa &mhs) {
    if (mhs.jumlahMatkul < 2) {
        cout << ">> List terlalu pendek untuk tambah tengah. Gunakan tambah depan/belakang.\n";
        return;
    }

    int posisi;
    cout << "\n[+] Tambah Mata Kuliah di TENGAH\n";
    cout << "    Tambah setelah posisi ke- (1 s/d " << mhs.jumlahMatkul - 1 << "): ";
    cin >> posisi;

    if (posisi < 1 || posisi >= mhs.jumlahMatkul) {
        cout << ">> Posisi tidak valid!\n";
        return;
    }

    mataKuliah mk   = inputSatuMatkul();
    Node*      baru = buatNode(mk);

    Node* curr = mhs.head;
    for (int i = 1; i < posisi; i++) curr = curr->next;

    baru->next = curr->next;
    curr->next = baru;

    if (baru->next == nullptr) mhs.tail = baru;
    mhs.jumlahMatkul++;
    cout << "  [OK] Mata kuliah berhasil ditambahkan di posisi ke-" << posisi + 1 << ".\n";
}

void hapusDepan(mahasiswa &mhs) {
    if (kosong(mhs)) {
        cout << ">> Tidak ada mata kuliah untuk dihapus!\n";
        return;
    }
    Node* hapus = mhs.head;
    mhs.head = mhs.head->next;
    cout << ">> Matkul \"" << hapus->matKul.namaMatkul << "\" berhasil dihapus dari depan!\n";
    delete hapus;
    mhs.jumlahMatkul--;
    if (mhs.head == nullptr) mhs.tail = nullptr;
}

void hapusBelakang(mahasiswa &mhs) {
    if (kosong(mhs)) {
        cout << ">> Tidak ada mata kuliah untuk dihapus!\n";
        return;
    }

    if (mhs.head->next == nullptr) {
        cout << ">> Matkul \"" << mhs.head->matKul.namaMatkul << "\" berhasil dihapus dari belakang!\n";
        delete mhs.head;
        mhs.head = nullptr;
        mhs.tail = nullptr;
        mhs.jumlahMatkul--;
        return;
    }

    Node* curr = mhs.head;
    while (curr->next->next != nullptr) curr = curr->next;

    cout << ">> Matkul \"" << curr->next->matKul.namaMatkul << "\" berhasil dihapus dari belakang!\n";
    delete curr->next;
    curr->next = nullptr;
    mhs.tail = curr;
    mhs.jumlahMatkul--;
}

void hapusTengah(mahasiswa &mhs) {
    if (mhs.jumlahMatkul < 3) {
        cout << ">> List terlalu pendek untuk hapus tengah. Gunakan hapus depan/belakang.\n";
        return;
    }

    int posisi;
    cout << "\n[+] Hapus Mata Kuliah di TENGAH\n";
    cout << "    Hapus di posisi ke- (2 s/d " << mhs.jumlahMatkul - 1 << "): ";
    cin >> posisi;

    if (posisi < 2 || posisi > mhs.jumlahMatkul - 1) {
        cout << ">> Posisi tidak valid!\n";
        return;
    }

    Node* curr = mhs.head;
    for (int i = 1; i < posisi - 1; i++) curr = curr->next;

    Node* hapus = curr->next;
    curr->next = hapus->next;
    cout << ">> Matkul \"" << hapus->matKul.namaMatkul << "\" berhasil dihapus dari posisi ke-" << posisi << ".\n";
    delete hapus;
    mhs.jumlahMatkul--;
}


int main(){
    mahasiswa mhs;

    // FIX 1: inisialisasi wajib dipanggil sebelum apapun
    inisialisasi(mhs);

    cout << "Selamat Datang di Sakha Program Grade Nilai PNJ" << endl;
    cout << "Silahkan masukan nama mahasiswa    : ";
    getline(cin, mhs.nama);
    cout << "Silahkan masukan NIM mahasiswa     : ";
    cin >> mhs.nim;
    cout << "Silahkan masukan program studi     : ";
    cin.ignore();
    getline(cin, mhs.prodi);
    cout << "Silahkan masukkan semester         : ";
    cin >> mhs.semester;
    cin.ignore();
    cout << "===========================================" << endl;

    int jumlahAwal;
    cout << "Jumlah mata kuliah yang diambil    : ";
    cin >> jumlahAwal;

    for (int i = 0; i < jumlahAwal; i++){
        cout << "\n  Mata Kuliah ke-" << i + 1 << endl;
        tambahBelakang(mhs);
    }

    tampilkanSemuaMatkul(mhs);
    cout << "===========================================" << endl;

    int pilihan;
    do {
        cout << "\n=========== MENU OPERASI SLL ===========\n";
        cout << "[1] Tambah mata kuliah di depan\n";
        cout << "[2] Tambah mata kuliah di tengah\n";
        cout << "[3] Tambah mata kuliah di belakang\n";
        cout << "[4] Hapus mata kuliah di depan\n";
        cout << "[5] Hapus mata kuliah di tengah\n";
        cout << "[6] Hapus mata kuliah di belakang\n";
        cout << "[7] Tampilkan semua mata kuliah\n";
        cout << "[8] Keluar program\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahDepan(mhs);         break;
            case 2: tambahTengah(mhs);        break;
            case 3:
                cout << "\n[+] Tambah Mata Kuliah di BELAKANG\n";
                tambahBelakang(mhs);          break;
            case 4: hapusDepan(mhs);          break;
            case 5: hapusTengah(mhs);         break;
            case 6: hapusBelakang(mhs);       break;
            case 7: tampilkanSemuaMatkul(mhs); break;
            case 8: cout << "Terima kasih!\n"; break;
            default: cout << "  [!] Pilihan tidak valid.\n";
        }
    } while (pilihan != 8);

    return 0;
}