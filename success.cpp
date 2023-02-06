#include <iostream>
using namespace std;
 
int N, M; 
const int MAX = 101;
char input[MAX][MAX];
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
int wSum = 0;
int bSum = 0;
int s = 1;
 
void DFS(int y, int x) {
    visited[y][x] = true;
 
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (ny < 0 || nx < 0 || ny >= M || nx >= N)
            continue;
        if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
            visited[ny][nx] = true;
            s++;
            DFS(ny, nx);
        }
    }
}
 
void reset() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
            map[i][j] = 0;
        }
    }
}
 
 
int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1s", &input[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (input[i][j] == 'W') {
                map[i][j] = 1;
            }
        }
    }
    
    /*W의 DFS*/
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1&&visited[i][j]==0) {
                DFS(i, j);
                wSum += s * s;
                s = 1;
            }
        }
    }

    reset();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (input[i][j] == 'B') {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                DFS(i, j);
                bSum += s * s;
                s = 1;
            }
        }
    }
 
    cout << wSum << " " << bSum;
}
