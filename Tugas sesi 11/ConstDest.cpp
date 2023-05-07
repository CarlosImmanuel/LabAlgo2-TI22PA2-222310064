#include <iostream> //Header iostream, memasukkan pustaka iostream kedalam program
using namespace std; //Berfungsi pada cout agar tidak menambahkan std::

class contoh{ //Nama kelas diberi menjadi "contoh"
    private: //Spesifik akses, data dan function tersebut tidak bisa diakses dari luar class
    int nilai; //Membuat variabel baru dengan tipe data int untuk bilangan bulat
    public: // Spesifik akses, seluruh kode program di luar class bisa mengaksesnya
    contoh(int n){ //Constructor
        nilai = n; //Nilai n dimasukkin ke variabel nilai
    }
    int getNum(){ //Fungsi getter
        return nilai;
    }
};

int main(){ //Fungsi utama
    contoh obj(10); //Memanggil kelas contoh dengan objek obj dengan nilai 10
    cout << "Nilai yang diinput : " << obj.getNum() << endl; //Menampilkan kata yang didalam tanda kutip dan hasil getter dari class
    return 0; 
}