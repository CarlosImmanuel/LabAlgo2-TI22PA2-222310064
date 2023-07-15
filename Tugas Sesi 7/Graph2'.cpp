#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Struktur data untuk merepresentasikan edge
struct Edge {
  int node;
  int weight;
};

// Fungsi untuk mencari rute terpendek menggunakan algoritma Dijkstra
void dijkstra(const vector<vector<Edge>> &graph, int startNode,
              vector<int> &distances) {
  int numNodes = graph.size();
  distances.assign(numNodes, INT_MAX);
  distances[startNode] = 0;

  // Priority queue dengan pasangan node dan jarak
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, startNode});

  while (!pq.empty()) {
    int currNode = pq.top().second;
    int currDist = pq.top().first;
    pq.pop();

    if (currDist > distances[currNode]) {
      continue;
    }

    for (const Edge &edge : graph[currNode]) {
      int nextNode = edge.node;
      int weight = edge.weight;

      if (currDist + weight < distances[nextNode]) {
        distances[nextNode] = currDist + weight;
        pq.push({distances[nextNode], nextNode});
      }
    }
  }
}

int main() {
  int numNodes = 6;
  int startNode = 5;

  // Membentuk graf berdasarkan informasi node dan edge yang diberikan
  vector<vector<Edge>> graph(numNodes + 1); // Index dimulai dari 1

  graph[6].push_back({5, 9});
  graph[5].push_back({6, 9});

  graph[5].push_back({4, 6});
  graph[4].push_back({5, 6});

  graph[6].push_back({3, 2});
  graph[3].push_back({6, 2});

  graph[3].push_back({4, 11});
  graph[4].push_back({3, 11});

  graph[6].push_back({1, 14});
  graph[1].push_back({6, 14});

  graph[2].push_back({4, 15});
  graph[4].push_back({2, 15});

  graph[1].push_back({3, 9});
  graph[3].push_back({1, 9});

  graph[2].push_back({3, 10});
  graph[3].push_back({2, 10});

  graph[1].push_back({2, 7});
  graph[2].push_back({1, 7});

  vector<int> distances(numNodes + 1);
  dijkstra(graph, startNode, distances);

  // Cetak rute terpendek dari startNode ke setiap node
  cout << "Rute Terpendek:\n";
  for (int i = 1; i <= numNodes; i++) {
    cout << "Dari node " << startNode << " ke node " << i << " adalah "
         << distances[i] << endl;
  }

  return 0;
}