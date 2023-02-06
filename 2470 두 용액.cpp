#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

vector<int> glass;
int minDiff;
int minWater1;
int minWater2;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		glass.push_back(a);
	}
	sort(glass.begin(), glass.end());
	minWater1 = 0;
	minWater2 = N - 1;
	minDiff = abs(glass[minWater2] + glass[minWater1]);
	int index1 = 0;
	int index2 = N - 1;
	int temp;
	while (index1 < index2) {
		temp = glass[index2] + glass[index1];
		if (abs(temp) < minDiff) {
			minDiff = abs(temp);
			minWater1 = index1;
			minWater2 = index2;
		}
		if (temp > 0) {
			index2--;
		}
		else {
			index1++;
		}
	}
	cout << glass[minWater1] << " " << glass[minWater2] << "\n";
}