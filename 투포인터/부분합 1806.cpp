#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int arr[100001];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, S;
	cin >> N >> S;
	int pointer1 = 0;
	int pointer2 = 0;
	int sum;
	int leastLength=1000000;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sum = arr[0];
	while (pointer2 < N) {
		if (sum >= S) {
			if (leastLength > pointer2 - pointer1 + 1) {
				leastLength = pointer2 - pointer1 + 1;
			}
			sum -= arr[pointer1++];
		}
		else {
			sum += arr[++pointer2];
		}
	}
	if (leastLength == 1000000) {
		cout << 0 << "\n";
	}
	else {
		cout << leastLength << "\n";
	}
}