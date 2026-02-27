#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    long long nim;
    string prodi;
    int semester;
    int tahun_masuk;
    int nilaiAkhir, nilaiTugas, nilaiKuis, nilaiMid, nilaiUas;
};

void inputMahasiswa(mahasiswa &mhs){
    cout << "\nMasukkan Nama Mahasiswa: "; cin >> mhs.nama;
    cout << "Masukkan NIM Mahasiswa: "; cin >> mhs.nim;
    cout << "Masukkan Prodi Mahasiswa: "; cin >> mhs.prodi;
    cout << "Masukkan Semester Mahasiswa: "; cin >> mhs.semester;
    cout << "Masukkan Tahun Masuk Mahasiswa: "; cin >> mhs.tahun_masuk;
    cout << "Masukkan Nilai Tugas Mahasiswa: "; cin >> mhs.nilaiTugas;
    cout << "Masukkan Nilai Kuis Mahasiswa: "; cin >> mhs.nilaiKuis;
    cout << "Masukkan Nilai Mid Mahasiswa: "; cin >> mhs.nilaiMid;
    cout << "Masukkan Nilai UAS Mahasiswa: "; cin >> mhs.nilaiUas;
}

void outputMahasiswa(mahasiswa &mhs){
    cout << "\nNama Mahasiswa: " << mhs.nama << endl;
    cout << "NIM Mahasiswa: " << mhs.nim << endl;
    cout << "Prodi Mahasiswa: " << mhs.prodi << endl;
    cout << "Semester Mahasiswa: " << mhs.semester << endl;
    cout << "Tahun Masuk Mahasiswa: " << mhs.tahun_masuk << endl;
    cout << "Nilai Tugas Mahasiswa: " << mhs.nilaiTugas << endl;
    cout << "Nilai Kuis Mahasiswa: " << mhs.nilaiKuis << endl;
    cout << "Nilai Mid Mahasiswa: " << mhs.nilaiMid << endl;
    cout << "Nilai UAS Mahasiswa: " << mhs.nilaiUas << endl;
}

int hitungNilaiAkhir(mahasiswa &mhs){
    mhs.nilaiAkhir = (mhs.nilaiTugas * 0.3) + (mhs.nilaiKuis * 0.1) + (mhs.nilaiMid * 0.3) + (mhs.nilaiUas * 0.3);
    return mhs.nilaiAkhir;
}


int main(){
    mahasiswa mhs;

    cout << "Selamat Datang di Program Menghitung Nilai Akhir Mahasiswa" << endl;
    inputMahasiswa(mhs);
    outputMahasiswa(mhs);
    hitungNilaiAkhir(mhs);
    cout << "\nNilai Akhir Mahasiswa: " << mhs.nilaiAkhir << endl;
}