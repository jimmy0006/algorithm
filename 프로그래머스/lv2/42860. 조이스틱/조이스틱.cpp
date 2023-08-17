#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int namer(char a){
    return min(a-'A',26-a+'A');
}

int pathCal(pair<int,int> temp, int size){
    int right = temp.first-1;
    int left = size-temp.first-temp.second;
    return min(right*2+left,left*2+right);
}

int path(string name){
    int ans = name.size()-1;
    vector<pair<int,int>> v;
    int temp=0;
    for(int i=1;i<name.size();i++){
        if(name[i]=='A'){
            temp++;
        }else{
            v.push_back({i-temp,temp});
            temp=0;
        }
    }
    if(temp!=0){
        v.push_back({name.size()-temp,temp});
    }
    for(pair<int,int> iter:v){
        ans = min(pathCal(iter,name.size()),ans);
    }
    return ans;
}

int solution(string name) {
    int answer=0;
    for(char iter:name){
        answer+=namer(iter);
    }
    return answer+path(name);
}