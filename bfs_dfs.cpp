#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;

void bfs(int start) {
    vector<bool> vis(graph.size(), false);
    queue<int> q;

    q.push(start);
    vis[start] = true;

    cout << "BFS: ";
    while(!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for(int nei : graph[node]) {
            if(!vis[nei]) {
                vis[nei] = true;
                q.push(nei);
            }
        }
    }
}

void dfs(int node, vector<bool>& vis) {
    vis[node] = true;
    cout << node << " ";

    for(int nei : graph[node]) {
        if(!vis[nei]) dfs(nei, vis);
    }
}

int main() {
    int n = 5;
    graph.resize(n);

    graph[0] = {1,2};
    graph[1] = {0,3};
    graph[2] = {0,4};
    graph[3] = {1};
    graph[4] = {2};

    bfs(0);

    vector<bool> vis(n,false);
    cout << "\nDFS: ";
    dfs(0, vis);

    return 0;
}