#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;

int arr[10001] = { 0 };
int coin[101];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	arr[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j < k+1; j++) {
			arr[j] += arr[j - coin[i]];
		}
	}
	cout << arr[k] << "\n";
}