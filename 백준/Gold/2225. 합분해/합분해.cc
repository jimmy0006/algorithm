#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;

long dp[201][201] = { 0 };

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N+1; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < K; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < N+1; j++) {
			dp[i][j] = (dp[i - 1][j]+dp[i][j-1]) % 1000000000;
		}
	}
	cout << dp[K - 1][N] << "\n";
}