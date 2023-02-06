#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <set>

using namespace std;
int prime[4000004] = { 0 };
vector<int> primes;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    if (N == 1) {
        cout << 0 << "\n";
        return 0;
    }
    else if (N == 2) {
        cout << 1<< "\n";
        return 0;
    }
    for (int i = 2; i < N; i++) {
        if (prime[i]== 0){
            for (int j = 2; j <= (N+1) / i; j++) {
                prime[i * j] = 1;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (prime[i]==0) {
            primes.push_back(i);
        }
    }
    int pointer1 = 0;
    int pointer2 = 0;
    int sum = 2;
    int ans = 0;
    while (primes[pointer1] < N / 2) {
        if (sum < N) {
            sum += primes[++pointer2];
        }
        else if (sum > N) {
            sum -= primes[pointer1++];
        }
        else {
            ans++;
            sum += primes[++pointer2];
            sum -= primes[pointer1++];
        }
    }
    if (prime[N]==0) {
        ans++;
    }
    cout << ans << "\n";
}