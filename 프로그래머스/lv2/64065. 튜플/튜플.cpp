#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

set<int> sets;
map<int,vector<int>> m;

vector<int> solution(string s) {
    int count=0;
    vector<int> answer;
    for(int i=0;i<s.size();i++){
        if(s[i]==','){
            s[i]=' ';
        }
    }
    for(int i=1;i<s.size();i++){
        if(s[i]=='{'){
            int tohere;
            for(int j=1;j+i<s.size();j++){
                if(s[i+j]=='}'){
                    tohere = j;
                    break;
                }
            }
            stringstream stream;
            stream.str(s.substr(i+1,tohere-1));
            vector<int> temp;
            int temp2;
            while(stream>>temp2){
                temp.push_back(temp2);
            }
            m[temp.size()]=temp;
            count++;
            i+=tohere;
        }
    }
    
    for(int i=1;i<=count;i++){
        for(int iter:m[i]){
            if(sets.find(iter)==sets.end()){
                sets.insert(iter);
                answer.push_back(iter);
                break;
            }
        }
    }
    
    return answer;
}