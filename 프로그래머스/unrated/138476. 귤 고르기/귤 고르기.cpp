#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
map<int,int> m;
vector<int> v;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int iter:tangerine){
        m[iter]++;
    }
    for(pair<int,int> iter:m){
        v.push_back(iter.second);
    }
    sort(v.begin(), v.end());
    for(int i=v.size()-1;i>=0;i--){
        k-=v[i];
        answer++;
        if(k<=0){
            break;
        }
    }
    return answer;
}