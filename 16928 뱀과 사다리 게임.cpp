#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

int arr[110] = { 0 };
queue<int> q;
class Node {
public:
    int from;
    int to;
    Node(int a, int b) {
        from = a;
        to = b;
    };
    Node() {};
};
vector<Node> ladders;
int ladderFinder(int a) {
    for (auto iter = ladders.begin(); iter != ladders.end(); iter++) {
        Node temp = *iter;
        if (temp.from==a) {
            return temp.to;
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    int from, to;
    for (int i = 0; i < N+M; i++) {
        cin >> from >> to;
        arr[from] = -1;
        ladders.push_back(Node(from, to));
    }
    q.push(1);
    arr[1] = 0;
    int here;
    int temp;
    while (!q.empty()) {
        here = q.front();
        q.pop();
        if (here == 100) {
            cout << arr[100] << "\n";
            break;
        }
        for (int i = 1; i < 7; i++) {
            if (arr[here + i] == -1) {
                temp=ladderFinder(here + i);
                if (arr[temp] == 0 || arr[temp] > arr[here]) {
                    arr[temp] = arr[here] + 1;
                    q.push(temp);
                }
            }
            else if (arr[here+i]== 0 || arr[here + i] > arr[here]) {
                arr[here + i] = arr[here] + 1;
                q.push(here + i);
            }
        }
    }
}