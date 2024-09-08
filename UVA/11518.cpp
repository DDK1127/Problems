// Dominos 2
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

int dfs(int u){
    int res = 1; // + u self
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
        if(!visited[adj[u][i]]) // check adj list have not visited ?
            res += dfs(adj[u][i]); // recursive check.
    }
    return res;
}

int main(){
    int times, n, m, l, a, b;
    cin >> times;
    
    while(times-- > 0){
        cin >> n >> m >> l;

        int ans = 0;
        adj.resize(n+1);
        visited.resize(n, false);

        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b); // adj list.
        }
        for(int i = 0; i < l; i++){
            cin >> a;
            if(!visited[a])
                ans += dfs(a);
        }
        cout << ans << endl;
        visited.clear();
        adj.clear();
    }
    return 0;
}