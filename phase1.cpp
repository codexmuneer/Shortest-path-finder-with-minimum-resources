// Adjacency Matrix representation in C++

#include <iostream>
using namespace std;

class Graph {
   private:
  int** adjMatrix;
  int numVertices;
  int weights;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new int[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = 0;
    }
  }

  // Add edges
  void addEdge(int i, int j,int w) {
    adjMatrix[i][j] = w;
    adjMatrix[j][i] = w;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0;
  }

  // Print the martix
  void print() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main() {

    int vertices, edges;
    cout<<"#####***ADJACENCY MATRIX***######"<<endl;
    cout<<"Enter vertices and edges here: "<<endl;
    cin>> vertices >> edges;
    Graph g(vertices+1);

    cout<<"Enter vertices,edges and weights here: "<<endl;
    for(int i = 0; i < edges;i++){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight; 
        g.addEdge(v1, v2, weight);
    }



  g.print();
}