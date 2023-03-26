#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> v;

string solution(string s) {
    string answer = "";
    for(int i=0;i<s.size();i++){
        v.push_back(s.substr(i,1));
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        answer+=v[i];
    }
    return answer;
}