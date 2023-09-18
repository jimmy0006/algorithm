#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int,int>> arr[201];
int toA[201];
bool Avisited[201];
int toB[201];
bool Bvisited[201];
int toS[201];
bool Svisited[201];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void ALoad(int a){
    pq.push({0,a});
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        if(Avisited[temp.second]){
            continue;
        }
        Avisited[temp.second] = true;
        toA[temp.second]=temp.first;
        for(pair<int,int> iter:arr[temp.second]){
            if(!Avisited[iter.first]){
                pq.push({temp.first+iter.second,iter.first});
            }
        }
    }
}

void BLoad(int b){
    pq.push({0,b});
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        if(Bvisited[temp.second]){
            continue;
        }
        Bvisited[temp.second] = true;
        toB[temp.second]=temp.first;
        for(pair<int,int> iter:arr[temp.second]){
            if(!Bvisited[iter.first]){
                pq.push({temp.first+iter.second,iter.first});
            }
        }
    }
}

void SLoad(int s){
    pq.push({0,s});
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        if(Svisited[temp.second]){
            continue;
        }
        Svisited[temp.second] = true;
        toS[temp.second]=temp.first;
        for(pair<int,int> iter:arr[temp.second]){
            if(!Svisited[iter.first]){
                pq.push({temp.first+iter.second,iter.first});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for(vector<int> iter:fares){
        arr[iter[0]].push_back({iter[1],iter[2]});
        arr[iter[1]].push_back({iter[0],iter[2]});
    }
    ALoad(a);
    BLoad(b);
    SLoad(s);
    // for(int i=1;i<=n;i++){
    //     cout<<toA[i]<<", ";
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<toB[i]<<", ";
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<toS[i]<<", ";
    // }
    // cout<<"\n";
    for(int i=1;i<=n;i++){
        if(Avisited[i]&&Bvisited[i]&&Svisited[i]){
            int temp = toA[i]+toB[i]+toS[i];
            if(answer==0 || answer>temp){
                answer = temp;
            }
        }
    }
    return answer;
}