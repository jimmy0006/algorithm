#include <string>
#include <vector>

using namespace std;
int nums[100001]={0,};

int solution(int number, int limit, int power) {
    for(int i=1;i<=number;i++){
        for(int j=1;j*i<=number;j++){
            nums[i*j]++;
        }
    }
    int answer = 0;
    for(int i=0;i<=number;i++){
        if(nums[i]>limit){
            answer+=power;
        }else{
            answer+=nums[i];
        }
    }
    return answer;
}