#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> m1;
map<int,string> m2;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    for(int i=0;i<players.size();i++){
        m1[players[i]]=i+1;
        m2[i+1]=players[i];
    }
    for(string call :callings){
        int a = m1[call];
        string b = m2[a-1];
        m1[call]-=1;
        m1[b]+=1;
        m2[a]=b;
        m2[a-1]=call;
    }
    for(int i=1;i<=players.size();i++){
        answer.push_back(m2[i]);
    }
    return answer;
}