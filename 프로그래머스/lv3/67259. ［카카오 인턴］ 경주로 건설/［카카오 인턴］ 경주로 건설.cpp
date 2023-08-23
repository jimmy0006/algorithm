#include <string>
#include <vector>
#include <queue>
using namespace std;

struct position{
    int money;
    char direction;
    int x;
    int y;
};

struct compare{
    bool operator()(position& a,position& b){
        return a.money>b.money;
    }
};

priority_queue<position,vector<position>,compare> pq;

int arr[25][25];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    pq.push({0,'E',0,0});
    pq.push({0,'S',0,0});
    while(!pq.empty()){
        position temp = pq.top();
        pq.pop();
        if(temp.x==(size-1) && temp.y==(size-1)){
            return temp.money;
        }
        if(arr[temp.x][temp.y]==0){
            arr[temp.x][temp.y]=temp.money;
        }else if(arr[temp.x][temp.y]<(temp.money-500)){
            continue;
        }
        if(temp.direction=='E'){
            if(temp.y<(size-1) && board[temp.x][temp.y+1]==0){
                pq.push({temp.money+100,'E',temp.x,temp.y+1});
                pq.push({temp.money+600,'S',temp.x,temp.y+1});
                pq.push({temp.money+600,'N',temp.x,temp.y+1});
            }
        }else if(temp.direction=='W'){
            if(temp.y>0 && board[temp.x][temp.y-1]==0){
                pq.push({temp.money+100,'W',temp.x,temp.y-1});
                pq.push({temp.money+600,'S',temp.x,temp.y-1});
                pq.push({temp.money+600,'N',temp.x,temp.y-1});
            }
        }else if(temp.direction=='S'){
            if(temp.x<(size-1)&&board[temp.x+1][temp.y]==0){
                pq.push({temp.money+600,'E',temp.x+1,temp.y});
                pq.push({temp.money+600,'W',temp.x+1,temp.y});
                pq.push({temp.money+100,'S',temp.x+1,temp.y});
            }
        }else if(temp.direction=='N'){
            if(temp.x>0&&board[temp.x-1][temp.y]==0){
                pq.push({temp.money+600,'E',temp.x-1,temp.y});
                pq.push({temp.money+600,'W',temp.x-1,temp.y});
                pq.push({temp.money+100,'N',temp.x-1,temp.y});
            }
        }
    }
    return answer;
}