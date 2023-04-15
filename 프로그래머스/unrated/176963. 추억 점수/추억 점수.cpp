#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0;i<name.size();i++){
        m[name[i]]=yearning[i];
    }
    for(vector<string> iter:photo){
        int sum=0;
        for(string iter2:iter){
            sum+=m[iter2];
        }
        answer.push_back(sum);
    }
    return answer;
}