#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer=0;
    if(board.size()==1 ||board[0].size()==1){
        for(vector<int> iter:board){
            for(int iter2:iter){
                if(iter2>0){
                    return 1;
                }
            }
        }
    }
    for(int i=board.size()-2;i>=0;i--){
        for(int j=board[0].size()-2;j>=0;j--){
            if(board[i][j]==1){
                if(board[i+1][j]>0 && board[i][j+1]>0 && board[i+1][j+1]>0){
                    board[i][j]=min(board[i+1][j],min( board[i][j+1],board[i+1][j+1]))+1;
                }
                if(board[i][j]>answer){
                        answer=board[i][j];
                    }
            }
        }
    }

    return answer*answer;
}