/*
 * Knight Problem
 * Description: Find the shortest path from a knight to a target square on a chessboard
 * Authors: Scott Derbes and Bryan Fratianne
 */
#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

//Create Graph
class Graph{
private:
    bool** adjMatrix;
    int numVertices;
public:
    Graph(int numb){
        this->numVertices = numb;
        adjMatrix = new bool*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] = false;
            }
        }
    }

    void addEdge(int x, int y){//Add an edge between two vertices
        adjMatrix[x][y] = true;
    }

    bool isInside(int x, int y, int n){
        return x >= 1 && x <= n && y >= 1 && y <= n;
    }

    int minDistance(int dist[8][8], bool path[8][8]) {
        // Initialize min value
        int min = INT_MAX, min_index;

        for (int vertices = 0; vertices < numVertices; vertices++){
            for (int i = 0; i < numVertices; ++i) {
                if (path[vertices][vertices] == false && dist[vertices][vertices] <= min){
                    min = dist[vertices][vertices], min_index = vertices;
                }
            }
        }
        return min_index;
    }

    bool findEdges(int xCor, int yCor){
        /*
         * Staring from src coordinates, find all possible moves
         */
        int xAxis[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int yAxis[] = {-1, -2, -2, -1, 1, 2, 2, 1};

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                int checkX = xCor + xAxis[i];
                int checkY = yCor + yAxis[j];
                if(isInside(checkX, checkY, numVertices)){
                    addEdge(checkX, checkY);
                }
            }
        }
    }

    void toString(int dist[]){
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < numVertices; i++)
            printf("%d tt %d\n", i, dist[i]);
    }

    //Djikstras Implementation
    void shortestPath(int* knight){
        // The output array.  dist[i][j] will hold the shortest distance from src to i
        int dist[numVertices][numVertices];
        // pathArr[][] will be true if vertex i is included in shortest path tree
        // or shortest distance from src to i is finalized
        int pathArr[numVertices][numVertices];
        // Initialize all distances as INFINITE and pathArr[][] as false
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                dist[i][j] = INT_MAX;
                pathArr[i][j] = false;
            }
        }
        // Distance of source vertex from itself is always 0
        int x = knight[0];
        int y = knight[1];
        dist[x][y] = 0;

        // Find shortest path for all vertices
        for (int counter = 0; counter < numVertices - 1; ++counter) {
            for (int k = 0; k < numVertices - 1; ++k) {
                int u = minDistance(dist[][], pathArr[][]);
            }
        }
            // Pick the minimum distance vertex from the set of vertices not
            // yet processed. u is always equal to src in the first iteration.

            // Mark the picked vertex as processed


            // Update dist value of the adjacent vertices of the picked vertex.

                // Update dist[v] only if is not in sptSet, there is an edge from
                // u to v, and total weight of path from src to  v through u is
                // smaller than current value of dist[v]

        // print the constructed distance array

    }
    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};



int main(){
    int vertices = 8;
    int src[] = {1,1};
    int target[] = {6,3};

    Graph* matrix = new Graph(vertices);
    //matrix->findEdge(src[0], src[1]);
    matrix->shortestPath(src);

    //Djisktra parameters need to be adjusted to work with src location
    return 0;
}