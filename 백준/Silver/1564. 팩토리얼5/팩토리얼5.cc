#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
long long unsigned N;
long long unsigned ans = 1;

long long unsigned notTen(long long unsigned i) {
	while (!(i % 10)) {
		i /= 10;
	}
	return i;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
	cin >> N;
	for (long long unsigned i = 1; i < N+1; i++) {
		ans *= i;
		ans = notTen(ans);
		ans %= 1000000000000;
	}
	ans %= 100000;
	cout.width(5);
	cout.fill('0');
	cout << ans;
}