#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
	int T;
	cin >> T;
	string temp;
	while (T--) {
		cin >> temp;
		map<string, int> m;
		bool check = true;
		int i = 0;
		while(i<temp.length()) {
			string target = temp.substr(i, 1);
			if (m[target] == 2) {
				if (i<temp.length()-1&&temp.substr(i + 1, 1) == target) {
					i+=2;
					m[target] = 0;
					continue;
				}
				else {
					check = false;
					break;
				}
			}
			else {
				m[target] += 1;
				i++;
			}
		}
		if (check) {
			cout << "OK" << "\n";
		}
		else {
			cout << "FAKE" << "\n";
		}
	}

}