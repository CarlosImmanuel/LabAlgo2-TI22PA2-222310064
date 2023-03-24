#include <iostream>
using namespace std;
void selectionsort(int arr[], int n){
  int i, j, minIndex, temp;
  for(i=0; i<n-1; i++){
    minIndex =i;
    for(j=i+1; j<n; j++){
      if(arr[j]>arr[minIndex]){
        minIndex = j;
      }
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
    cout << "Iterasi ke-" << i+1 << " : ";
    for(int k=0; k<n; k++){
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}
int main(){
  int n, i;
  cout << "Masukkan jumlah elemen : ";
  cin >> n;
  int arr[n];
  cout << "Masukkan nilai elemen : ";
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  cout << "Data sebelum sorting : ";
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }  
  cout << endl;
  selectionsort(arr,n);
  cout << "Data setelah sorting : ";
  for(i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}