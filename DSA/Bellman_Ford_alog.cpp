#include<bits/stdc++.h>
using namespace std;

#define infinite INT_MAX

struct Edge{

void initialize(vector<Edge> &distance, int vertex, int start){
	distance.resize(vertex, infinite);
	distance[s] = 0;

}
void BellmanFord(vector<Edge> &graph, int vertex, int start){
	initialize(graph, vertex, start);

	for(int i = 1; i < vertex; i++){
		for(int ){ // Each (u, v) Edge  to do relax.

		}
	}
}

int main(){
	int vertex = 5;
	vector<Edge> graph ={
		{a, b, 3}, {a, c, 8}, {b, d, 2},
		{c, d, -5}, {d, e, 7} 
	};
	

	return;
}
