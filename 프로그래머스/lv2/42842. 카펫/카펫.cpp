#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sumxy = brown/2+2;
    for(int i=3;i<=sumxy/2;i++){
        if(((i-2)*(sumxy-i-2))==yellow){
            answer.push_back(sumxy-i);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}