#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, vector<int>& colors, vector<vector<int>>& graph, int color) {
    for (int neighbor : graph[node]) {
        if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

bool solveMColoring(int node, int m, vector<int>& colors, vector<vector<int>>& graph) {
    if (node == graph.size()) {
        return true;
    }

    for (int color = 1; color <= m; ++color) {
        if (isSafe(node, colors, graph, color)) {
            colors[node] = color;
            if (solveMColoring(node + 1, m, colors, graph)) {
                return true;
            }
            colors[node] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    int N, E, M;
    cin >> N >> E >> M;
    
    vector<vector<int>> graph(N);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<int> colors(N, 0);
    if (solveMColoring(0, M, colors, graph)) {
        cout << "Yes" << endl;
        for (int color : colors) {
            cout << color << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
