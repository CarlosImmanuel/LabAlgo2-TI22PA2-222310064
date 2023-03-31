#include <iostream>
#include <algorithm>
using namespace std;

const int M = 100;
int number[M];

int binarySearch (int x, int l, int r){
    if (r >= 1) {
        int mid = 1 + (r - 1)/2;
        if (number[mid] == x)
            return mid;
        if (number[mid] > x)
            return binarySearch (x,l,mid - 1);
        return binarySearch (x,mid + 1, r);
    }
    return -1;
}

int main(){
    int n;

    cout << "Masukkan banyak data yang akan diinput didalam array : ";
    cin >> n;


    for (int i=0 ; i<n ; i++){
        cout << "Masukkan nomor data : " << i+1 << " : ";
        cin >> number[i];
    }
    sort (number, number + n);

    int z;
    cout << "Masukkan data yang ingin dicari : ";
    cin >> z;

    int result = binarySearch (z, 0 ,n -1);
    if (result == -1 )
    cout << "Data tidak ditemukan" << endl;
    else
    cout << "Data ditemukan pada index nomor ke-"<< result << endl;

    return 0;
}