#include<bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm function
void dijkstra(list< pair<int, int> > adjacencyList[], int vertices, int startVertex, int distances[], int parent[])
{
    int i;
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int,int> > > priorityQueue;

    // Initially no routes to vertices are know, so all are infinity
    for (i = 1; i <= vertices; ++i) {
        distances[i] = INT_MAX;
        parent[i] = 0;
    }

    // Setting distance to source to zero
    distances[startVertex] = 0;
	priorityQueue.push(make_pair(startVertex, 0));

	while(!priorityQueue.empty()){     // Untill there are vertices to be processed
        pair<int, int> minVertex = priorityQueue.top();   // Greedily process the nearest vertex
        priorityQueue.pop();

		int u = minVertex.first;
		list< pair<int, int> >::iterator itr = adjacencyList[u].begin();

		// Checking all the vertices adjacent to vertex 'u'
        while (itr != adjacencyList[u].end()) {
        	int v = (*itr).first;
        	int w = (*itr).second;

        	// Checking if relaxation is possible for edge, u --> v of weight 'w'
            if (distances[u] != INT_MAX && distances[v] > distances[u] + w) {
                // We have discovered a new shortest route, make the neccesary adjustments in data
                distances[v] = distances[u] + w;
                parent[v] = u;
                priorityQueue.push(make_pair(v, distances[v]));
            }

            ++itr;
        }
    }
}

// Recursively looks at a vertex's parent to print the path
void printPath(int parent[], int vertex, int startVertex)
{
    if (vertex == startVertex) {	// reached the source vertex
        printf("%d ", startVertex);
        return;
    } else if (parent[vertex] == 0) {	// current vertex has no parent
    	printf("%d ", vertex);
    	return;
	} else {	// go for the current vertex's parent
        printPath(parent, parent[vertex], startVertex);
        printf("%d ", vertex);
    }
}

int main()
{
    int vertices, edges, i, v1, v2, w, startVertex;
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
	list< pair<int, int> > adjacencyList[vertices + 1];
	int distances[vertices + 1];	// stores shortest distance from start vertex
	int parent[vertices + 1];		// stores parent vertex in the shortest path
    for (i = 1; i <=  edges; ++i) {
        scanf("%d%d%d", &v1, &v2, &w);
        adjacencyList[v1].push_back(make_pair(v2, w));
    }
    printf("Enter a start vertex -\n");
    scanf("%d", &startVertex);
    dijkstra(adjacencyList, vertices, startVertex, distances, parent);
    printf("Shortest distances -\n");
    for (i = 1; i <= vertices; ++i) {
    	printf("Vertex %d, Distance = %d, Parent = %d, ", i, distances[i], parent[i]);
    	printf("Path = ");
    	printPath(parent, i, startVertex);
    	printf("\n");
	}
    return 0;
}
