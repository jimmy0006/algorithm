#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int i=0;i<r2;i++){
        long maxV =(long) floor(sqrt((long)r2*r2-(long)i*i));
        long minV;
        if(i>=r1){
            minV=1;
        }else{
            minV=(long)ceil(sqrt((long)r1*r1-(long)i*i));
        }
        answer+=(long)maxV-minV+1;
    }
    answer*=4;
    return answer;
}