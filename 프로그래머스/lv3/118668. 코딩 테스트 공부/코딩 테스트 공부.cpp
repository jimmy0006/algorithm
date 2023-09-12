#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int visited[200][200];

int alpMax=0;
int copMax=0;
int maxTime=1000;

struct point{
    int alp;
    int cop;
    int time;
};

struct compare{
    bool operator()(point& a, point& b){
        return a.time>b.time;
    }
};

priority_queue<point,vector<point>,compare> q;

void search(int alp, int cop, int time){
    if(alp>alpMax){
        alp=alpMax;
    }
    if(cop>copMax){
        cop=copMax;
    }
    if(visited[alp][cop]==0){
        q.push({alp,cop,time});
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    for(vector<int> iter:problems){
        if(alpMax<iter[0]){
            alpMax=iter[0];
        }
        if(copMax<iter[1]){
            copMax=iter[1];
        }
    }
    q.push({alp,cop,0});
    while(!q.empty()){
        point temp = q.top();
        q.pop();
        if(temp.alp>=alpMax && temp.cop>=copMax){
            return temp.time;
        }
        if(visited[temp.alp][temp.cop]==1){
            continue;
        }
        visited[temp.alp][temp.cop]=1;
        search(temp.alp+1,temp.cop,temp.time+1);
        search(temp.alp,temp.cop+1,temp.time+1);
        for(vector<int> iter:problems){
            if(temp.alp>=iter[0] && temp.cop>=iter[1]){
                search(temp.alp+iter[2],temp.cop+iter[3],temp.time+iter[4]);
            }
        }
        
    }
    return 1;
}