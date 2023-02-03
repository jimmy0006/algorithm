#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

int arr[1001][1001] = {0};
int normal[2][1001][1001] = { 0 };

class Node {
public:
    int first;
    int second;
    Node(int a, int b) {
        first = a;
        second = b;
    };
    Node() {};
};

queue<Node> q;
queue<Node> j;

void search(int a, int b, int c) {
    if (arr[a][b] == 1) {
        if (normal[1][a][b] == 0) {
            j.push(Node(a, b));
            normal[1][a][b] = c+1;
        }
    }
    else {
        if (normal[0][a][b] == 0) {
            q.push(Node(a, b));
            normal[0][a][b] = c + 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < M; j++) {
            arr[i][j] = stoi(line.substr(j, 1));
        }
    }
    normal[0][0][0] = 1;
    q.push(Node(0, 0));
    Node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp.first > 0) {
            search(temp.first - 1, temp.second, normal[0][temp.first][temp.second]);
        }
        if (temp.first < N - 1) {
            search(temp.first + 1, temp.second, normal[0][temp.first][temp.second]);
        }
        if (temp.second > 0) {
            search(temp.first, temp.second-1, normal[0][temp.first][temp.second]);
        }
        if (temp.second < M - 1) {
            search(temp.first, temp.second+1, normal[0][temp.first][temp.second]);
        }
    }
    while (!j.empty()) {
        temp = j.front();
        j.pop();
        if (temp.first > 0) {
            if (arr[temp.first-1][temp.second] == 0) {
                if (normal[1][temp.first - 1][temp.second] == 0 || normal[1][temp.first - 1][temp.second] > normal[1][temp.first][temp.second]) {
                    normal[1][temp.first - 1][temp.second] = normal[1][temp.first][temp.second] + 1;
                    j.push(Node(temp.first - 1, temp.second));
                }
            }
        }
        if (temp.first < N-1) {
            if (arr[temp.first + 1][temp.second] == 0) {
                if (normal[1][temp.first + 1][temp.second] == 0 || normal[1][temp.first + 1][temp.second] > normal[1][temp.first][temp.second]) {
                    normal[1][temp.first + 1][temp.second] = normal[1][temp.first][temp.second] + 1;
                    j.push(Node(temp.first + 1, temp.second));
                }
            }
        }
        if (temp.second > 0) {
            if (arr[temp.first][temp.second-1] == 0) {
                if (normal[1][temp.first][temp.second-1] == 0 || normal[1][temp.first][temp.second-1] > normal[1][temp.first][temp.second]) {
                    normal[1][temp.first][temp.second-1] = normal[1][temp.first][temp.second] + 1;
                    j.push(Node(temp.first, temp.second-1));
                }
            }
        }
        if (temp.second < M-1) {
            if (arr[temp.first][temp.second + 1] == 0) {
                if (normal[1][temp.first][temp.second + 1] == 0 || normal[1][temp.first][temp.second + 1] > normal[1][temp.first][temp.second]) {
                    normal[1][temp.first][temp.second + 1] = normal[1][temp.first][temp.second] + 1;
                    j.push(Node(temp.first, temp.second + 1));
                }
            }
        }
    }

    if (normal[0][N - 1][M - 1] == 0 && normal[1][N - 1][M - 1] == 0) {
        cout << -1 << "\n";
    }
    else {
        if (normal[0][N - 1][M - 1] == 0) {
            cout << normal[1][N - 1][M - 1] << "\n";
        }
        else if (normal[1][N - 1][M - 1] == 0) {
            cout << normal[0][N - 1][M - 1] << "\n";
        }
        else{
            cout << min(normal[0][N - 1][M - 1], normal[1][N - 1][M - 1]) << "\n";
        }
    }
}