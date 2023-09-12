#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long sum1 = 0;
long long sum2 = 0;
long long sumsum;

int idxConv(vector<int> queue1, vector<int> queue2, int idx){
    if(queue1.size()>idx){
        return queue1[idx];
    }else{
        return queue2[idx-queue1.size()];
    }
}

int solve(vector<int> queue1, vector<int> queue2, long long sum1, long long sumsum){
    long long temp = sum1;
    int q1Idx=0;
    int size = queue1.size();
    int q2Idx=size;
    int count=0;
    while(temp!=(sumsum/2)){
        if(q1Idx==q2Idx||q1Idx==(size*2)||q2Idx==(size*3)){
            return -1;
        }
        if(temp>(sumsum/2)){
            if(size>q1Idx){
                temp-=queue1[q1Idx];
            }else{
                temp-=queue2[q1Idx-size];
            }
            q1Idx++;
        }else{
            if((size*2)>q2Idx){
                temp+=queue2[q2Idx-size];
            }else{
                temp+=queue1[q2Idx-size*2];
            }
            q2Idx++;
        }
        count++;
    }
    return count;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    for(int iter:queue1){
        sum1+=iter;
    }
    for(int iter:queue2){
        sum2+=iter;
    }
    sumsum = sum1+sum2;
    int temp = solve(queue1,queue2,sum1,sumsum);
    if(temp==-1){
        return answer;
    }else{
        return temp;
    }
    return answer;
}