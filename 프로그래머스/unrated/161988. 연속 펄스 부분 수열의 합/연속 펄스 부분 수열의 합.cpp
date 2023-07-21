#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long prefixSum=0;
    long long maxValue=0;
    long long minValue=0;
    
    for(int i=0;i<sequence.size();i++){
        if(i%2){
            prefixSum+=sequence[i];
        }
        else{
            prefixSum-=sequence[i];
        }
        if(prefixSum>maxValue){
            maxValue=prefixSum;
        }
        if(prefixSum<minValue){
            minValue=prefixSum;
        }
        //cout<<prefixSum<<"\n";
    }
    answer=maxValue-minValue;
    return answer;
}