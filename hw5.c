/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 9

struct Node {
    int vertex;
    struct Node* next;
};

//create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

//add an edge
void addEdge(struct Node* adjList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;


    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// BFS
void bfs(struct Node* adjList[], int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = adjList[currentVertex];
        int adjVertices[MAX_VERTICES];
        int numAdjVertices = 0;

        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                adjVertices[numAdjVertices++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }

        for (int i = 0; i < numAdjVertices - 1; i++) {
            for (int j = i + 1; j < numAdjVertices; j++) {
                if (adjVertices[i] > adjVertices[j]) {
                    int temp = adjVertices[i];
                    adjVertices[i] = adjVertices[j];
                    adjVertices[j] = temp;
                }
            }
        }

        for (int i = 0; i < numAdjVertices; i++) {
            queue[rear++] = adjVertices[i];
        }
    }
}

int main() {
    struct Node* adjList[MAX_VERTICES] = {NULL};


    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 3, 6);
    addEdge(adjList, 4, 7);
    addEdge(adjList, 5, 8);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 7, 8);

    bfs(adjList, 0);
    printf("\n");

    return 0;
}

