#include <iostream>
using namespace std;
class buku {
    private:
    string buku1;
    string buku2;

    public: 
    void setBuku1(string n){
        buku1 = n;
    }
    void setBuku2(string s){
        buku2 = s;
    }
    string getBuku1(){
        return buku1;
    }
    string getBuku2(){
        return buku2;
    }
};

int main(){
    buku Buku;

    Buku.setBuku1("One Piece");
    Buku.setBuku2("Naruto");

    cout << "Buku yang ingin dipinjam : " << Buku.getBuku1() << endl;
    cout << "Buku yang akan dikembalikan : " << Buku.getBuku2() << endl;
    return 0;
}