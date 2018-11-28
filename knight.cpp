//
// Created by Scott Derbes on 11/27/2018.
//


//Struct for Graph

//Create Graph
#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

#define N 9

struct Vertex{
    int x,y,dis;
    Vertex* next;
    bool visited;
    Vertex() {};
    Vertex(int i, int i1) : x(x), y(y) {};
    Vertex(int i, int i1, int i2) : x(x), y(y), dis(dis) {};
};

struct AdjList{
    Vertex *src; //Start of list
};

struct Graph{
    int V; //Total number of Vertexes in Graph
    Vertex *arr; //
};

int minDistance(int dist[], bool sptSet[]){
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < N; v++){
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

Vertex *newVertex(int);
Graph *createGraph(int);
void addEdge(Graph*,int,int);
void printGraph(Graph*);

bool isInside(int x, int y, int n){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int printSolution(int dist[], int n){
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < N; i++)
        printf("%d tt %d\n", i, dist[i]);
}

int shortestPath(int graph[N][N], int src){
    int dist[N];

    bool sptSet[N];

    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < N-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < N; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, N);
}

int main() {
    int size = 8; //Size of Board
    int knightPos[] = {1,1};// Starting Position of Knight (src)
    int targetPos[] = {4,5}; //End position

    shortestPath();
    return 0;
}