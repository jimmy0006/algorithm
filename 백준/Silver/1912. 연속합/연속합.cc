#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;

int arr[100001];
int diff[100001] = { 0 };

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum += temp;
		arr[i] = sum;
	}
	int minValue = arr[0];
	for (int i = 0; i < n; i++) {
		if (minValue > arr[i]) {
			minValue = arr[i];
		}
		diff[i+1] -= minValue;
	}
	int maxValue = arr[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		if (maxValue < arr[i]) {
			maxValue = arr[i];
		}
		diff[i] += maxValue;
	}
	int ans = diff[0];
	for (int i = 0; i <n; i++) {
		if (diff[i] > ans) {
			ans = diff[i];
		}
	}
	cout << ans << "\n";
}