#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for(vector<int> iter:skill){
        if(iter[0]==1){
            arr[iter[1]][iter[2]]-=iter[5];
            arr[iter[1]][iter[4]+1]+=iter[5];
            arr[iter[3]+1][iter[2]]+=iter[5];
            arr[iter[3]+1][iter[4]+1]-=iter[5];
        }else{
            arr[iter[1]][iter[2]]+=iter[5];
            arr[iter[1]][iter[4]+1]-=iter[5];
            arr[iter[3]+1][iter[2]]-=iter[5];
            arr[iter[3]+1][iter[4]+1]+=iter[5];
        }
    }
    
    for(int i=0;i<board.size();i++){
        for(int j=1;j<board[0].size();j++){
            arr[i][j]+=arr[i][j-1];
        }
    }
    for(int i=1;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            arr[i][j]+=arr[i-1][j];
        }
    }
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            board[i][j]+=arr[i][j];
        }
    }
    
    for(vector<int> iter:board){
        for(int iter2:iter){
            if(iter2>0){
                answer++;
            }
        }
    }
    return answer;
}