#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct result{
    int score;
    vector<int> targets;
};

struct compare{
    bool operator()(result& a, result& b){
        if(a.score==b.score){
            for(int i=0;i<11;i++){
                if(a.targets[10-i]!=b.targets[10-i]){
                    return a.targets[10-i]<b.targets[10-i];
                }
            }
            return true;
        }else{
            return a.score<b.score;
        }
    }
};

priority_queue<result,vector<result>,compare> pq;

vector<int> solution(int n, vector<int> info) {
    for(int i=0;i<2048;i++){
        int reqArrow=0;
        vector<int> targets;
        int score=0;
        for(int j=10;j>=0;j--){
            if(i&(1<<j)){
                reqArrow+=info[10-j]+1;
                targets.push_back(info[10-j]+1);
                if(info[10-j]!=0){
                    score+=j;
                }
                score+=j;
            }else{
                targets.push_back(0);
            }
        }
        if(reqArrow>n){
            continue;
        }else{
            if(reqArrow<n){
                targets[10]+=n-reqArrow;
            }
            pq.push({score,targets});
        }
    }
    int apScore=0;
    for(int i=0;i<11;i++){
        if(info[i]!=0){
            apScore+=10-i;
        }
    }
    result temp = pq.top();
    if(temp.score<=apScore){
        vector<int> answer;
        answer.push_back(-1);
        return answer;
    }else{
        return temp.targets;
    }
}