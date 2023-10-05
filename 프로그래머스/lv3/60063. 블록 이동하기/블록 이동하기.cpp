#include <string>
#include <vector>
#include <queue>

using namespace std;

struct state{
    int x;
    int y;
    int dir;//0 for 가로, 1 for 세로
    int count;
};

int visited[101][101][2];

queue<state> q;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int boardSize = board.size();
    q.push({0,0,0,0});
    while(!q.empty()){
        state temp = q.front();
        q.pop();
        if(temp.dir==1 && temp.x == boardSize-2 && temp.y == boardSize-1){
            return temp.count;
        }else if(temp.dir==0 && temp.x == boardSize-1 && temp.y == boardSize-2){
            return temp.count;
        }
        if(visited[temp.x][temp.y][temp.dir]!=0){
            continue;
        }else{
            visited[temp.x][temp.y][temp.dir]=temp.count;
        }
        //왼쪽 이동
        if(temp.y>0){
            if(temp.dir==0 && board[temp.x][temp.y-1]==0){
                //가로
                q.push({temp.x,temp.y-1,0,temp.count+1});
            }else if(temp.dir==1 && board[temp.x][temp.y-1]==0 && board[temp.x+1][temp.y-1]==0){
                //세로 상태
                q.push({temp.x,temp.y-1,1,temp.count+1});
            }
        }
        //오른쪽 이동
        if(temp.y<boardSize-2 && temp.dir==0 && board[temp.x][temp.y+2]==0){
            //가로
            q.push({temp.x,temp.y+1,0,temp.count+1});
        }else if(temp.y<boardSize-1 && temp.dir==1 && board[temp.x][temp.y+1]==0 && board[temp.x+1][temp.y+1]==0){
            //세로
            q.push({temp.x,temp.y+1,1,temp.count+1});
        }
        //위로 이동
        if(temp.x>0){
            if(temp.dir==0 && board[temp.x-1][temp.y]==0 && board[temp.x-1][temp.y+1]==0){
                q.push({temp.x-1,temp.y,0,temp.count+1});
            }else if(temp.dir==1 && board[temp.x-1][temp.y]==0){
                q.push({temp.x-1,temp.y,1,temp.count+1});
            }
        }
        //아래로 이동
        if(temp.x<boardSize-1 && temp.dir==0 && board[temp.x+1][temp.y]==0 && board[temp.x+1][temp.y+1]==0){
            //가로
            q.push({temp.x+1,temp.y,0,temp.count+1});
        }else if(temp.x<boardSize-2 && temp.dir==1 && board[temp.x+2][temp.y]==0){
            //세로
            q.push({temp.x+1,temp.y,1,temp.count+1});
        }
        //가로
        if(temp.dir==0){
            if(temp.x>0 && board[temp.x-1][temp.y]==0 && board[temp.x-1][temp.y+1]==0){
                //왼쪽 위로 회전
                q.push({temp.x-1,temp.y,1,temp.count+1});
                //오른쪽 위로 회전
                q.push({temp.x-1,temp.y+1,1,temp.count+1});
            }
            
            if(temp.x<boardSize-1 && board[temp.x+1][temp.y]==0 && board[temp.x+1][temp.y+1]==0){
                //왼쪽 아래로 회전
                q.push({temp.x,temp.y,1,temp.count+1});
                //오른쪽 아래로 회전
                q.push({temp.x,temp.y+1,1,temp.count+1});
            }
        }
        //세로
        if(temp.dir==1){
            
            if(temp.y>0 && board[temp.x][temp.y-1]==0 && board[temp.x+1][temp.y-1]==0){
                //왼쪽 위로 회전
                q.push({temp.x,temp.y-1,0,temp.count+1});
                //왼쪽 아래로 회전
                q.push({temp.x+1,temp.y-1,0,temp.count+1});
            }
            
            if(temp.y<boardSize-1 && board[temp.x][temp.y+1]==0 && board[temp.x+1][temp.y+1]==0){
                //오른쪽 위로 회전
                q.push({temp.x,temp.y,0,temp.count+1});
                //오른쪽 아래로 회전
                q.push({temp.x+1,temp.y,0,temp.count+1});
            }
        }
    }
    return answer;
}