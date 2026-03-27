#include <iostream>
using namespace std;

struct mataKuliah {
    string namaMatkul;
    int nilaiUts, nilaiUas, nilaiTugas;
};

struct mahasiswa {
    long long nim;
    int semester;
    string nama, prodi;
    mataKuliah matKul[50];
};

void inputMatkul(mahasiswa &mhs, int jumlahMatkul){
    for (int i = 0; i < jumlahMatkul; i++){
        cout << "Masukan mata kuliah ke-" + i;
        cin >> mhs.matKul[i].namaMatkul;
        cout << "Masukan nilai tugas: ";
        cin >> mhs.matKul[i].nilaiTugas;
        cout << "Masukan nilai UTS: ";
        cin >> mhs.matKul[i].nilaiUts;
        cout << "Masukan nilai UAS: ";
        cin >> mhs.matKul[i].nilaiUas;
    }
}

int main(){
    mahasiswa mhs;
    int jumlahMatkul;
    cout << "Selamat Datang di Sakha Program Grade Nilai PNJ" << endl;
    cout << "Silahkan masukan nama mahasiswa: ";
    cin >> mhs.nama;
    cout << "Silahkan masukan NIM mahasiswa: ";
    cin >> mhs.nim;
    cout << "Silahkan masukan program studi: ";
    cin >> mhs.prodi;
    cout << "Silahkan mahasiswa semester berapa: ";
    cin >> mhs.semester;
    
    cout << "===========================================" << endl;
    cout << "Silahkan masukan jumlah mata kuliah yang diambil mahasiswa: ";
    cin >> jumlahMatkul;
    inputMatkul(mhs, jumlahMatkul);
}