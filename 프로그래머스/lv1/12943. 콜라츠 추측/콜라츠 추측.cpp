#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long unsigned temp=num;
    if(num==1){
        return 0;
    }
    while(temp!=1){
        if(!(temp%2)){
            temp/=2;
        }else{
            temp*=3;
            temp++;
        }
        answer++;
        if(answer>=500){
            answer=-1;
            break;
        }
    }
    return answer;
}