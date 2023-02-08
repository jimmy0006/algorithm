#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;
int arr[2001][2001] = { 0 };

class Node {
public:
    int first;
    int second;
    Node() {};
    Node(int a, int b) {
        first = a;
        second = b;
    }
};

bool cmp(Node a, Node b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

vector<Node> v;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    int temp;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            arr[i][j] = temp;
            if(temp==1)count++;
        }
    }
    int dots = K*2-count;
    bool check = true;
    bool check2 = true;
    bool check3 = true;
    if (dots == K) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 1) {
                    v.push_back(Node(i, j));
                }
            }
        }
    }
    else if (dots) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (check3) {
                    if (check2) {
                        if (arr[i][j] == 1) {
                            if (j + 1 < M) {
                                for (int k = 0; k < K; k++) {
                                    if (arr[i][j + k] == 0) {
                                        check = false;
                                        break;
                                    }
                                }
                            }
                            else {
                                check = false;
                            }
                            if (check) {
                                for (int k = 0; k < K; k++) {
                                    arr[i][j + k] = 2;
                                }
                            }
                            else {
                                for (int k = 0; k < K; k++) {
                                    arr[i + k][j] = 2;
                                }
                            }
                            check2 = false;
                        }
                    }
                    else {
                        if (arr[i][j] == 1) {
                            if (i > 0 && arr[i - 1][j] == 2) {
                                for (int k = 1; k <= dots; k++) {
                                    v.push_back(Node(i - k, j));
                                }
                                check3 = false;
                            }
                            else if (i + 1 < N && arr[i + 1][j] == 2) {
                                for (int k = 1; k <= dots; k++) {
                                    v.push_back(Node(i + k, j));
                                }
                                check3 = false;
                            }
                            else if (j > 0 && arr[i][j - 1] == 2) {
                                for (int k = 1; k <= dots; k++) {
                                    v.push_back(Node(i , j - k));
                                }
                                check3 = false;
                            }
                            else if (j +1<M && arr[i][j + 1] == 2) {
                                for (int k = 1; k <= dots; k++) {
                                    v.push_back(Node(i, j + k));
                                }
                                check3 = false;
                            }
                        }
                    }
                }
                else {
                    break;
                }
            }
        }
    }
    cout << K * 2 - count << "\n";
    Node temp2;
    sort(v.begin(), v.end(), cmp);
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        temp2 = *iter;
        cout << temp2.first+1 << " " << temp2.second+1 << "\n";
    }
}