#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

int solution(int n) {
    int answer = 0;
    while(n){
        v.push_back(n%3);
        n-=(n%3);
        n/=3;
    }
    for(int i=0;i<v.size();i++){
        answer*=3;
        answer+=v[i];
    }
    return answer;
}