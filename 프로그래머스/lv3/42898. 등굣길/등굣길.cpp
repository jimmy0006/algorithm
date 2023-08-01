#include <string>
#include <vector>

using namespace std;

int arr[101][101];
int solid=1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(vector<int> iter:puddles){
        arr[iter[0]][iter[1]]=-1;
    }
    arr[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==0){
                if(arr[i-1][j]==-1){
                    arr[i][j]=arr[i][j-1];
                }else if(arr[i][j-1]==-1){
                    arr[i][j]=arr[i-1][j];
                }else{
                    arr[i][j]=(arr[i-1][j]+arr[i][j-1])%solid;
                }
            }
        }
    }
    return arr[m][n];
}