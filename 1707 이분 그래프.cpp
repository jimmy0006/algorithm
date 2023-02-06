#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> vertex[20001];
int visited[20001] = { 0 };
set<int> group1;
set<int> group2;

bool search(int a, bool team) {
    if (team) {
        group1.insert(a);
    }
    else {
        group2.insert(a);
    }
    visited[a] = 1;
    for (auto iter = vertex[a].begin(); iter != vertex[a].end(); iter++) {
        if (!visited[*iter]) {
            if (search(*iter, !team)) {
                return true;
            }
        }
        else {
            if (team) {
                if (group1.find(*iter) != group1.end()) {
                    return true;
                }
            }
            else {
                if (group2.find(*iter) != group2.end()) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int K, V, E;
    cin >> K;
    int node1, node2;
    while (K--) {
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            cin >> node1 >> node2;
            vertex[node1].push_back(node2);
            vertex[node2].push_back(node1);
        }
        int temp;
        bool check=false;
        for (int i = 1; i < V + 1; i++) {
            if (!visited[i]) {
                if (search(i, true)) {
                    check = true;
                    break;
                }
            }
        }
        if (check) {
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
        }
        group1.clear();
        group2.clear();
        for (int i = 1; i < V+1; i++) {
            vertex[i].clear();
            visited[i] = 0;
        }
    }
}