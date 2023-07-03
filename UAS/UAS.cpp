#include <iostream>
using namespace std;

class MataKuliah {
protected:
    float presensi;
    float activity;
    float exercise;
    float ujianAkhir;

public:
    MataKuliah() {
        presensi = 0;
        activity = 0;
        exercise = 0;
        ujianAkhir = 0;
    }

    virtual float hitungNilaiAkhir() { return 0; }
    virtual void cekKelulusan() { return ; }
    virtual void input() { return ; }

    void setPresensi(float p) {
        this->presensi = p;
    }

    void setActivity(float a) {
        this->activity = a;
    }

    void setExercise(float e) {
        this->exercise = e;
    }

    void setujianAkhir(float ua) {
        this->ujianAkhir = ua;
    }

    float getPresensi() {
        return presensi;
    }

    float getActivity() {
        return activity;
    }

    float getExercise() {
        return exercise;
    }

    float getUjianAkhir() {
        return ujianAkhir;
    }
};

class Pemrograman : public MataKuliah {
public:
    Pemrograman() : MataKuliah() {}

    float hitungNilaiAkhir() {
        return (presensi * 0.1) + (activity * 0.2) + (exercise * 0.3) + (ujianAkhir * 0.4) ;
    }

    void cekKelulusan() {
        float nilaiAkhir = hitungNilaiAkhir();
        if (nilaiAkhir > 75) {
            cout << "Selamat, Anda lulus mata kuliah Pemrograman dengan nilai akhir " << nilaiAkhir << endl;
        }
        else {
            cout << "Anda tidak lulus mata kuliah Pemrograman. Nilai akhir Anda adalah " << nilaiAkhir << endl;
        }
    }

    void input() {
        cout << "Masukkan nilai Presensi: ";
        cin >> presensi;
        cout << "Masukkan nilai Activity: ";
        cin >> activity;
        cout << "Masukkan nilai Exercise: ";
        cin >> exercise;
        cout << "Masukkan nilai Ujian Akhir: ";
        cin >> ujianAkhir;
    }
};

int main() {
    char ulang;
    do {
        Pemrograman pemrograman;
        pemrograman.input();
        pemrograman.cekKelulusan();
        cout << "Apakah anda ingin mengulang program? (Y/N) ";
        cin >> ulang;
    } 
    while (ulang == 'Y' || ulang == 'y');

    return 0;
}