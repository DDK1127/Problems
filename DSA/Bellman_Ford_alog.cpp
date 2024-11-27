#include <bits/stdc++.h>
using namespace std;

#define infinite INT_MAX

struct Edge{
	int u, v, w;
	// u is start vertex, v is end vector, w is weight of edge.
};

struct Graph{
	int V, E; // V is Vertx, E is Edge.
	struct Edge* edge; // array for edge.
};

struct Graph* create_graph(int V, int E){
	struct Graph* g = new Graph;
	g->V = V;
	g->E = E;
	g->edge = new Edge[E];

	return g;
};

void Print(int *arr, int size){
	for(int i = 0; i < size; i++)
		cout << "from s to " << i << " = " << arr[i] << endl;
}

bool BellmanFord(struct Graph* g, int s){
	int V = g->V;
	int E = g->E;
	int dist[V];
	int u, v, w;

	// initilization.
	for(int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	
	dist[s] = 0;

	for(int i = 1; i < V; i++){
		for(int j = 0; j < E; j++){
			u = g->edge[j].u;
			v = g->edge[j].v;
			w = g->edge[j].w;
			
			// relax.
			if(dist[u]+w < dist[v])
				dist[v] = dist[u]+w;
		}
		Print(dist, V);
		cout << endl;
	}
	
	// detect have negative cycle?
	for(int i = 0; i < E; i++){
		u = g->edge[i].u;
		v = g->edge[i].v;
		w = g->edge[i].w;

		if(dist[u]+w < dist[v]){
			cout << "Graph have negative cucle..." << endl;
			return false;
		}
	}
	cout << "\n\nresult => " << endl;
	Print(dist, V);
	return true;
}

int main() {

  	int V, E, u, v, w;
  	cout << "Plear input number of Vertex & Edge" << endl;
  	cin >> V >> E;

  	struct Graph* graph = create_graph(V, E);

	cout << "Please input E number of Edge info." << endl;
	cout << "like => input [u] : start vertex, [v] : end vertex, and [w] : edge weight" << endl;
	for(int i = 0; i < E; i++){
		cin >> u >> v >> w;
		graph->edge[i].u = u;
		graph->edge[i].v = v;
		graph->edge[i].w = w;
	}

	cout << "And we assume vertex 0 is source vertex." << endl;
  	BellmanFord(graph, 0);  //0 is the source vertex

  return 0;
}
