#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int p = 1;
int numW = 0; 
int numB = 0;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
char soldier[101][101];
int map[101][101] = {0, };
int power[2];
bool visited[101][101] = {0, };

void dfs(int y, int x);
void reset();

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1s", &soldier[i][j]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (soldier[i][j] == 'W') map[i][j] = 1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] && !visited[i][j])
            {
                visited[i][j] = true;
                dfs(i, j);
                numW += p * p;
                p = 1;
            }
        }
    }

    reset();

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (soldier[i][j] == 'B') map[i][j] = 1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] && !visited[i][j])
            {
                visited[i][j] = true;
                dfs(i, j);
                numB += p * p;
                p = 1;
            }
        }
    }

    cout << numW << ' ' << numB;

    return 0;
}

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;

        if (map[ny][nx] && !visited[ny][nx])
        {
            p++;
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

void reset()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
            map[i][j] = 0;
        }
    }
}