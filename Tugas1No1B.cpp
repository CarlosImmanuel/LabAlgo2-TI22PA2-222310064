#include <iostream>
using namespace std;
int main(){
  int y;
  cout << "Masukkan banyak Array : ";
  cin >> y;
  int x[y];
  for(int i=0; i<y; i++){
    cout << "Masukkan angka ke- " << i << " : ";
    cin >> x[i];
    cout << endl;
  }
  for(int i=1; i<y; i++){
    int key = x[i];
    int j = i-1;
    while(j>=0 && x[j] < key){
      x[j+1] = x[j];
      j--;
    }
    x[j+1] = key;
    cout << "Proses sorting" << endl;
    for(int m=0; m<y; m++){
      cout << x[m] << " ";
    }
    cout << endl;
  }
  cout << "Hasil Akhir" << endl;
  for(int m=0; m<y; m++){
    cout << x[m] << " ";
  }
}