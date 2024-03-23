#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 10

/* Define Infinite as a large enough
value.This value will be used for
vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[V][V], int n);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int dist[V][V],int n)
{

	int i, j, k;

	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, ..
	k} */
	for (k = 0; k < n; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < n; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < n; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist,n);
}

/* A utility function to print solution */
void printSolution(int dist[V][V], int n)
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

// Driver's code
int main()
{

    cout<<"Enter the nodes and edges number"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    int graph[V][V];
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]= INF;
        }
    }

    cout<<"Enter connected edge and their weight"<<endl;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
    }

    cout<<"The Entered Graph:\n";
    for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			if (graph[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	// Function call
	floydWarshall(graph,nodes);
	return 0;
}