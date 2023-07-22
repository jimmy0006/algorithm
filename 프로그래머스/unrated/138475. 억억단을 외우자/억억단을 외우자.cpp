#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int arr[5000001];
int maxs[5000001];

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    for(int i=1;i<=sqrt(e);i++){
        for(int j=i;j*i<=e;j++){
            if(i==j){
                arr[i*j]+=1;
            }else{
                arr[i*j]+=2;
            }
        }
    }
    int maxIdx=e;
    int maxValue=arr[e];
    for(int i=e;i>0;i--){
        if(maxValue<=arr[i]){
            maxValue=arr[i];
            maxIdx=i;
        }
        maxs[i]=maxIdx;
    }
    for(int iter:starts){
        answer.push_back(maxs[iter]);
    }
    return answer;
}