#include <string>
#include <vector>

using namespace std;

long arr[100001];
long sums[100001][3];

int solution(int n) {
    int answer = 0;
    arr[0]=1;
    arr[1]=1;//1
    arr[2]=3;//3
    arr[3]=10;//10
    sums[0][0]=1;//[0]1,0,0
    sums[1][0]=1;//[1]1,1,0
    sums[1][1]=1;
    sums[2][0]=1;//[2]1,1,3
    sums[2][1]=1;
    sums[2][2]=3;
    sums[3][0]=11;//[3]11,1,3
    sums[3][1]=1;
    sums[3][2]=3;
    for(int i=4;i<=n;i++){//[4]11,24,3
        arr[i]+=arr[i-1];
        arr[i]+=arr[i-2]*2;
        arr[i]+=arr[i-3]*5;
        if(i%3==0){
            arr[i]+=sums[i-4][0]*4+sums[i-4][1]*2+sums[i-4][2]*2;
        }else if(i%3==1){
            arr[i]+=sums[i-4][0]*2+sums[i-4][1]*4+sums[i-4][2]*2;
        }else{
            arr[i]+=sums[i-4][0]*2+sums[i-4][1]*2+sums[i-4][2]*4;
        }
        arr[i]=arr[i]%1000000007;
        if(i%3==0){
            sums[i][0]=sums[i-1][0]+arr[i];
            sums[i][1]=sums[i-1][1];
            sums[i][2]=sums[i-1][2];
        }else if(i%3==1){
            sums[i][0]=sums[i-1][0];
            sums[i][1]=sums[i-1][1]+arr[i];
            sums[i][2]=sums[i-1][2];
        }else{
            sums[i][0]=sums[i-1][0];
            sums[i][1]=sums[i-1][1];
            sums[i][2]=sums[i-1][2]+arr[i];
        }
    }
    
    return arr[n];
}