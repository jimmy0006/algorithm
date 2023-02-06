#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

int arr[100001][2];
int ans[100001][2];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    int n;
    int temp;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i][1];
        }
        ans[0][0] = arr[0][0];
        ans[0][1] = arr[0][1];
        ans[1][0] = arr[1][0] + arr[0][1];
        ans[1][1] = arr[1][1] + arr[0][0];
        for (int i = 2; i < n; i++) {
            ans[i][0] = max(ans[i - 2][1], ans[i - 1][1]) + arr[i][0];
            ans[i][1] = max(ans[i - 2][0], ans[i - 1][0]) + arr[i][1];
        }
        int result = 0;
        if (ans[n - 1][0] > result) {
            result = ans[n - 1][0];
        }
        if (ans[n - 1][1] > result) {
            result = ans[n - 1][1];
        }
        if (ans[n - 2][0] > result) {
            result = ans[n - 2][0];
        }
        if (ans[n - 2][1] > result) {
            result = ans[n - 2][1];
        }
        cout << result << "\n";
    }
}