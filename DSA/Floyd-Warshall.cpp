#include<bits/stdc++.h>
using namespace std;

#define INF 99999

void print_Solution(vector<vector<int> > &dist, int v){
    cout << setw(4);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF";
            else
                cout << dist[i][j];
            cout << setw(4);
        }
        cout << endl << endl;
    }
}

void floydwarshall(vector<vector<int> > &dist, int v){

    for(int k = 0; k < v; k++){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(dist[i][j] > (dist[i][k] + dist[k][j]) && ((dist[i][k] != INF && dist[k][j] != INF)))
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
        cout << "k = "  << k << endl;
        print_Solution(dist, v);
    }
}

int main(){
    int V, n;
    int u, v, w;
    cout << "how many Vertex ? and how many input Edge." << endl;
    cin >> V >> n;
    cout << "Please input 'u' to 'v' and Edge weight 'w' " << endl;

    vector<vector<int> > graph(V, vector<int>(V, INF));

    for(int i = 0; i < V; i++)
        graph[i][i] = 0;

    for(int i = 0; i < n; i++){
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floydwarshall(graph, V);
    return 0;
}