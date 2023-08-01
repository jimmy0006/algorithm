#include <string>
#include <vector>

using namespace std;

int arr[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    arr[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        arr[i][0]=arr[i-1][0]+triangle[i][0];
        for(int j=1;j<=i;j++){
            if(arr[i-1][j-1]>arr[i-1][j]){
                arr[i][j]=arr[i-1][j-1]+triangle[i][j];
            }else{
                arr[i][j]=arr[i-1][j]+triangle[i][j];
            }
        }
    }
    for(int i=0;i<triangle.size();i++){
        if(arr[triangle.size()-1][i]>answer){
            answer=arr[triangle.size()-1][i];
        }
    }
    return answer;
}