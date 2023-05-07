#include <iostream>
using namespace std;

class Mahasiswa{
    public :
    virtual void Data (){
        cout << "Data tidak ditemukan" << endl;
    }
};

class Carlos : public Mahasiswa{
    public :
    string Status = "Mahasiswa Aktif";
    string Nama = "Carlos Immanuel Tampubolon";
    int Umur = 18;
    string Fakultas = "Pariwisata dan Informatika";
    string Jurusan = "Teknologi Informasi";
    void Data (){
        cout << "Status = " << Status << endl;
        cout << "Nama = " << Nama << endl;
        cout << "Umur = " << Umur << endl;
        cout << "Jurusan = " << Jurusan << endl;
        cout << "Fakultas = " << Fakultas << endl;
    }
};

class Julius : public Mahasiswa{
    public :
    string Status = "Mahasiswa Aktif";
    string Nama = "Julius Taslim";
    int Umur = 17;
    string Fakultas = "Pariwisata dan Informatika";
    string Jurusan = "Teknologi Informasi";
    void Data (){
        cout << "Status = " << Status << endl;
        cout << "Nama = " << Nama << endl;
        cout << "Umur = " << Umur << endl;
        cout << "Jurusan = " << Jurusan << endl;
        cout << "Fakultas = " << Fakultas << endl;
    }
};

int main(){
    Mahasiswa *m1 = new Carlos();
    Mahasiswa *m2 = new Julius();
    m1 -> Data();
    cout << "\n======================================\n" << endl;
    m2 -> Data();
    return 0;
}