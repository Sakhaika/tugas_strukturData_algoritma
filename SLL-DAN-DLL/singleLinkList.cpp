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
    mataKuliah matKul[20];
};

string mutuHuruf(int nilaiTugas, int nilaiUts, int nilaiUas , int jumlahMatkul){
    float nilaiHuruf = (nilaiTugas + nilaiUts + nilaiUas) / 3;
    if (nilaiHuruf >= 81 && nilaiHuruf <= 100){
        return "A, Sangat Istimewah";
    } else if (nilaiHuruf <= 80.9 && nilaiHuruf >= 76){
        return "A-, Istimewah ";
    } else if (nilaiHuruf <= 75.9 && nilaiHuruf >= 72){
        return "B+, Lebih dari Baik";
    } else if (nilaiHuruf <= 71.9 && nilaiHuruf >= 68){
        return "B, Baik";
    } else if (nilaiHuruf <= 67.9 && nilaiHuruf >= 64){
        return "B-, Cukup Baik";
    } else if (nilaiHuruf <= 63.9 && nilaiHuruf >= 60){
        return "C+, Lebih dari Cukup";
    } else if (nilaiHuruf <= 59.9 && nilaiHuruf >= 56){
        return "C, Cukup";
    } else if (nilaiHuruf <= 55.9 && nilaiHuruf >= 41){
        return "D, Kurang";
    } else if (nilaiHuruf <= 40.9 && nilaiHuruf >= 1){
        return "E, Gagal";
    } else {
        return "Nilai tidak valid";
    }
}

void inputMatkul(mahasiswa &mhs, int jumlahMatkul){
    for (int i = 0; i < jumlahMatkul; i++){
        cout << "Masukan mata kuliah ke-" << i + 1 << endl;
        cout << "Nama Mata kuliah: ";
        cin >> mhs.matKul[i].namaMatkul;
        cout << "Masukan nilai tugas: ";
        cin >> mhs.matKul[i].nilaiTugas;
        cout << "Masukan nilai UTS: ";
        cin >> mhs.matKul[i].nilaiUts;
        cout << "Masukan nilai UAS: ";
        cin >> mhs.matKul[i].nilaiUas;
        cout << endl;
    }
}

void outputMatkul(mahasiswa &mhs, int jumlahMatkul){
    for (int i = 0; i < jumlahMatkul; i++){
        cout << "Data mata kuliah ke-" << i + 1 << endl;
        cout << "Nama mata kuliah: " << mhs.matKul[i].namaMatkul << endl;
        cout << "Nilai tugas: " << mhs.matKul[i].nilaiTugas << endl ;
        cout << "Nilai UTS: " << mhs.matKul[i].nilaiUts << endl;
        cout << "Nilai UAS: " << mhs.matKul[i].nilaiUas << endl;
        cout << "Mutu huruf mata kuliah: " << mutuHuruf(mhs.matKul[i].nilaiTugas, mhs.matKul[i].nilaiUts, mhs.matKul[i].nilaiUas, jumlahMatkul) << endl;
        cout << endl;
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
    cout << "========== Inputan kamu ==========" << endl;
    outputMatkul(mhs, jumlahMatkul);
}