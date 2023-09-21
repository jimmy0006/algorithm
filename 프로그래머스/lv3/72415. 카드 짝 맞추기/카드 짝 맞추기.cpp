#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;

//map<string,int> m1;

int aTob(int aX, int aY, int bX, int bY,vector<vector<int>> board){
    string pointToint = to_string(aX)+to_string(aY)+to_string(bX)+to_string(bY);
    // if(m1.find(pointToint)!=m1.end()){
    //     cout<<"aX: "<<aX<<", aY: "<<aY<<" to bX: "<<bX<<", bY: "<<bY<<", moves: "<<m1[pointToint]<<"\n\n";
    //     return m1[pointToint];
    // }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{aX,aY}});
    while(!pq.empty()){
        pair<int,pair<int,int>> temp = pq.top();
        pq.pop();
        if(temp.second.first==bX && temp.second.second==bY){
            //cout<<"aX: "<<aX<<", aY: "<<aY<<" to bX: "<<bX<<", bY: "<<bY<<", moves: "<<temp.first<<"\n\n";
            // m1[pointToint]=temp.first;
            return temp.first;
        }
        //cout<<"checking : "<<temp.second.first<<", "<<temp.second.second<<"\n";
        if(temp.second.first!=0){
            pq.push({temp.first+1,{temp.second.first-1,temp.second.second}});
            bool check=true;
            for(int i=temp.second.first-1;i>0;i--){
                if(board[i][temp.second.second]!=0){
                    pq.push({temp.first+1,{i,temp.second.second}});
                    check=false;
                    break;
                }
            }
            if(check){
                pq.push({temp.first+1,{0,temp.second.second}});
            }
        }
        if(temp.second.first!=3){
            pq.push({temp.first+1,{temp.second.first+1,temp.second.second}});
            bool check=true;
            for(int i=temp.second.first+1;i<3;i++){
                if(board[i][temp.second.second]!=0){
                    pq.push({temp.first+1,{i,temp.second.second}});
                    check=false;
                    break;
                }
            }
            if(check){
                pq.push({temp.first+1,{3,temp.second.second}});
            }
        }
        if(temp.second.second!=0){
            pq.push({temp.first+1,{temp.second.first,temp.second.second-1}});
            bool check=true;
            for(int i=temp.second.second-1;i>0;i--){
                if(board[temp.second.first][i]!=0){
                    pq.push({temp.first+1,{temp.second.first,i}});
                    check=false;
                    break;
                }
            }
            if(check){
                pq.push({temp.first+1,{temp.second.first,0}});
            }
        }
        if(temp.second.second!=3){
            pq.push({temp.first+1,{temp.second.first,temp.second.second+1}});
            bool check=true;
            for(int i=temp.second.second+1;i<3;i++){
                if(board[temp.second.first][i]!=0){
                    pq.push({temp.first+1,{temp.second.first,i}});
                    check=false;
                    break;
                }
            }
            if(check){
                pq.push({temp.first+1,{temp.second.first,3}});
            }
        }
    }
    return 1;
}

struct state{
    int moves;
    int aX;
    int aY;
    set<int> lefts;
    vector<vector<int>> board;
};

struct compare{
    bool operator()(state& a, state& b){
        return a.moves>b.moves;
    }
};

priority_queue<state,vector<state>,compare> pq;

map<int, vector<int>> m;

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    set<int> targets;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]>0){
                targets.insert(board[i][j]);
                m[board[i][j]].push_back(i);
                m[board[i][j]].push_back(j);
            }
        }
    }
    pq.push({0,r,c,targets,board});
    // int n=2;
    while(!pq.empty()){
        state temp = pq.top();
        pq.pop();
        //cout<<"moves : "<<temp.moves<<"\nx: "<<temp.aX<<", y: "<<temp.aY<<"\n";
        if(temp.lefts.size()==0){
            return temp.moves;
        }
        for(auto next=temp.lefts.begin();next!=temp.lefts.end();next++){
            set<int> temp2;
            vector<vector<int>> nextBoard = temp.board;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(temp.board[i][j]==*next){
                        nextBoard[i][j]=0;
                    }
                    //cout<<nextBoard[i][j]<<" ";
                }
                //cout<<"\n";
            }
            for(auto next2=temp.lefts.begin();next2!=temp.lefts.end();next2++){
                if(*next2!=*next){
                    temp2.insert(*next2);
                }
            }
            //cout<<"first1"<<"\n";
            int toFirst = aTob(temp.aX, temp.aY,m[*next][0],m[*next][1],temp.board)+1;
            //cout<<"first2"<<"\n";
            toFirst += aTob(m[*next][0],m[*next][1],m[*next][2],m[*next][3],temp.board)+1;
            pq.push({temp.moves+toFirst,m[*next][2],m[*next][3],temp2,nextBoard});
            //cout<<"second1"<<"\n";
            int toSecond = aTob(temp.aX, temp.aY,m[*next][2],m[*next][3],temp.board)+1;
            //cout<<"second2"<<"\n";
            toSecond += aTob(m[*next][2],m[*next][3],m[*next][0],m[*next][1],temp.board)+1;
            pq.push({temp.moves+toSecond,m[*next][0],m[*next][1],temp2,nextBoard});
        }
    }
    return answer;
}