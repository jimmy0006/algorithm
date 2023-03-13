#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;

int arr[1001];
int dp[1001];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	int maxCount;
	for (int i = 0; i < N; i++) {
		maxCount = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && maxCount < dp[j]) {
				maxCount = dp[j];
			}
		}
		dp[i] = maxCount + 1;
	}

	maxCount = 0;
	for (int i = 0; i < N; i++) {
		if (dp[i] > maxCount) {
			maxCount = dp[i];
		}
	}
	cout << maxCount << "\n";
}