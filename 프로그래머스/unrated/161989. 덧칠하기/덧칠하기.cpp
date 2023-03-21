#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int colored= 0;
    int answer = 0;
    for(int i=0;i<section.size();i++){
        if(section[i]>colored){
            colored=section[i]+m-1;
            answer++;
        }
    }
    return answer;
}