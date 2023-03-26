#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if(s.substr(0,1)=="-"){
        answer-=stoi(s.substr(1,s.size()-1));
    }else if(s.substr(0,1)=="+"){
        answer=stoi(s.substr(1,s.size()-1));
    }else{
        answer=stoi(s.substr(0,s.size()));
    }
    return answer;
}