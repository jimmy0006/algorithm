#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end());
    int idx=score.size()-1;
    for(int i=0;i<score.size()/m;i++){
        int minValue=score[idx];
        for(int j=0;j<m;j++){
            if(score[idx]<minValue){
                minValue=score[idx];
            }
            idx--;
        }
        answer+=minValue*m;
    }
    return answer;
}