#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
map<string, int> m;
set<int> s;

map<int,int> m2;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int iter:course){
        s.insert(iter);
    }
    for(string iter:orders){
        int size = iter.size();
        sort(iter.begin(), iter.end());
        for(int i=1;i<(1<<size);i++){
            int count=0;
            string temp="";
            for(int j=0;j<size;j++){
                if(i&(1<<j)){
                    count++;
                    temp+=iter[j];
                }
            }
            if(s.find(count)!=s.end()){
                m[temp]++;
                if(m2[temp.size()]<m[temp]){
                    m2[temp.size()]=m[temp];
                }
            }
        }
    }
    for(auto iter=m.begin();iter!=m.end();iter++){
        if(m2[iter->first.size()]==iter->second && iter->second>1){
            answer.push_back(iter->first);
        }
    }
    return answer;
}