#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

class Node {
public:
    int first;
    int second;
    Node(int a, int b) {
        first = a;
        second = b;
    }
    Node() {};
};

int arr[1001][1001] = {0};
queue<Node> q;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M, N;
    cin >> M >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            arr[i][j] = temp;
            if (temp == 1) {
                q.push(Node(i, j));
            }
        }
    }
    Node here;
    while (!q.empty()) {
        here = q.front();
        q.pop();
        if (arr[here.first][here.second] == -1) {
            continue;
        }
        if (0 < here.first) {
            if (arr[here.first - 1][here.second] ==0||arr[here.first - 1][here.second] > arr[here.first][here.second]+1) {
                arr[here.first - 1][here.second] = arr[here.first][here.second] + 1;
                q.push(Node(here.first - 1, here.second));
            }
        }
        if (N-1 > here.first) {
            if (arr[here.first + 1][here.second] == 0 || arr[here.first + 1][here.second] > arr[here.first][here.second] + 1) {
                arr[here.first + 1][here.second] = arr[here.first][here.second] + 1;
                q.push(Node(here.first + 1, here.second));
            }
        }
        if (0 < here.second) {
            if (arr[here.first][here.second -1] == 0 || arr[here.first][here.second -1] > arr[here.first][here.second] + 1) {
                arr[here.first][here.second -1] = arr[here.first][here.second] + 1;
                q.push(Node(here.first, here.second -1));
            }
        }
        if (M - 1 > here.second) {
            if (arr[here.first][here.second + 1] == 0 || arr[here.first][here.second +1] > arr[here.first][here.second] + 1) {
                arr[here.first][here.second +1] = arr[here.first][here.second] + 1;
                q.push(Node(here.first, here.second +1));
            }
        }
    }
    int times = 1;
    int check = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                check = true;
                break;
            }
            if (arr[i][j] > times) {
                times = arr[i][j];
            }
        }
    }
    if (check) {
        cout << -1 << "\n";
    }
    else {
         cout << times-1 << "\n";
    }
}