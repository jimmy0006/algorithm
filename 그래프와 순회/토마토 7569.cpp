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
    int third;
    Node(int a, int b, int c) {
        first = a;
        second = b;
        third = c;
    }
    Node() {};
};

int arr[101][101][101] = {0};
queue<Node> q;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M, N,H;
    cin >> M >> N>>H;
    int temp;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> temp;
                arr[k][i][j] = temp;
                if (temp == 1) {
                    q.push(Node(k, i, j));
                }
            }
        }
    }
    Node here;
    while (!q.empty()) {
        here = q.front();
        q.pop();
        if (arr[here.first][here.second][here.third] == -1) {
            continue;
        }
        if (0 < here.first) {
            if (arr[here.first - 1][here.second][here.third] ==0||arr[here.first - 1][here.second][here.third] > arr[here.first][here.second][here.third] +1) {
                arr[here.first - 1][here.second][here.third] = arr[here.first][here.second][here.third] + 1;
                q.push(Node(here.first - 1, here.second,here.third));
            }
        }
        if (H-1 > here.first) {
            if (arr[here.first + 1][here.second][here.third] == 0 || arr[here.first + 1][here.second][here.third] > arr[here.first][here.second][here.third] + 1) {
                arr[here.first + 1][here.second][here.third] = arr[here.first][here.second][here.third] + 1;
                q.push(Node(here.first + 1, here.second,here.third));
            }
        }
        if (0 < here.second) {
            if (arr[here.first][here.second -1][here.third] == 0 || arr[here.first][here.second -1][here.third] > arr[here.first][here.second][here.third] + 1) {
                arr[here.first][here.second -1][here.third] = arr[here.first][here.second][here.third] + 1;
                q.push(Node(here.first, here.second -1,here.third));
            }
        }
        if (N - 1 > here.second) {
            if (arr[here.first][here.second + 1][here.third] == 0 || arr[here.first][here.second +1][here.third] > arr[here.first][here.second][here.third] + 1) {
                arr[here.first][here.second +1][here.third] = arr[here.first][here.second][here.third] + 1;
                q.push(Node(here.first, here.second +1,here.third));
            }
        }
        if (0 < here.third) {
            if (arr[here.first][here.second][here.third-1] == 0 || arr[here.first][here.second][here.third-1] > arr[here.first][here.second][here.third] + 1) {
                arr[here.first][here.second][here.third-1] = arr[here.first][here.second][here.third] + 1;
                q.push(Node(here.first, here.second, here.third-1));
            }
        }
        if (M - 1 > here.third) {
            if (arr[here.first][here.second][here.third+1] == 0 || arr[here.first][here.second][here.third+1] > arr[here.first][here.second][here.third] + 1) {
                arr[here.first][here.second][here.third+1] = arr[here.first][here.second][here.third] + 1;
                q.push(Node(here.first, here.second, here.third+1));
            }
        }
    }
    int times = 1;
    int check = false;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[k][i][j] == 0) {
                    check = true;
                    break;
                }
                if (arr[k][i][j] > times) {
                    times = arr[k][i][j];
                }
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