#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak matriks cost
void printCostMatrix(const vector<vector<int>> &costMatrix, int numCities) {
  cout << "Cost List :\n";
  for (int i = 0; i < numCities; i++) {
    for (int j = 0; j < numCities; j++) {
      cout << " " << costMatrix[i][j];
    }
    cout << endl;
  }
}

// Fungsi untuk mencetak jalur terpendek dan minimum cost
void printShortestPath(int startCity, const vector<int> &path, int minCost) {
  cout << "Jalur Terpendek :\n";
  for (int i = 0; i < path.size(); i++) {
    cout << path[i];
    if (i != path.size() - 1) {
      cout << "-->";
    }
  }
  cout << endl;

  cout << "\nMinimum Cost : " << minCost << endl;
}

// Fungsi untuk mencari jalur terpendek dan minimum cost menggunakan algoritma
// Brute Force
void findShortestPath(const vector<vector<int>> &costMatrix, int startCity,
                      int numCities) {
  vector<int> cities;
  vector<int> path;
  int minCost = INT_MAX;

  // Inisialisasi vektor cities dengan nilai kota yang akan dikunjungi
  for (int i = 1; i <= numCities; i++) {
    if (i != startCity) {
      cities.push_back(i);
    }
  }

  // Mencari semua kemungkinan permutasi jalur
  do {
    int currentPathCost = 0;
    int currentCity = startCity;

    // Menghitung cost jalur saat ini
    for (int i = 0; i < cities.size(); i++) {
      currentPathCost += costMatrix[currentCity - 1][cities[i] - 1];
      currentCity = cities[i];
    }

    // Menambahkan cost dari kota terakhir kembali ke kota awal
    currentPathCost += costMatrix[currentCity - 1][startCity - 1];

    // Memeriksa jika cost jalur saat ini lebih kecil dari minimum cost
    // sebelumnya
    if (currentPathCost < minCost) {
      minCost = currentPathCost;
      path = cities;
    }
  } while (next_permutation(cities.begin(), cities.end()));

  // Menambahkan kota awal dan akhir ke jalur terpendek
  path.insert(path.begin(), startCity);
  path.push_back(startCity);

  // Mencetak matriks cost, jalur terpendek, dan minimum cost
  printCostMatrix(costMatrix, numCities);
  printShortestPath(startCity, path, minCost);
}

int main() {
  int numCities;
  cout << "Masukkan Jumlah Kota: ";
  cin >> numCities;

  vector<vector<int>> costMatrix(numCities, vector<int>(numCities));

  cout << "Nilai Cost Matrix\n";
  for (int i = 0; i < numCities; i++) {
    cout << "Cost Element Baris ke-: " << (i + 1) << endl;
    for (int j = 0; j < numCities; j++) {
      cin >> costMatrix[i][j];
    }
  }

  int startCity;
  cout << "\nKota Awal: ";
  cin >> startCity;

  findShortestPath(costMatrix, startCity, numCities);

  return 0;
}