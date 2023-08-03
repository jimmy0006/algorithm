#include <string>
#include <vector>

using namespace std;
vector<int> answer;

void recu(int n, int s){
    if(n==1){
        answer.push_back(s);
    }else{
        answer.push_back(s/n);
        recu(n-1,s-s/n);
    }
}

vector<int> solution(int n, int s) {
    if(n>s){
        answer.push_back(-1);
    }else{
        recu(n,s);
    }

    return answer;
}