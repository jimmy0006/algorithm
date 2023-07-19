#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    for(vector<int> iter:targets){
        pq.push({iter[0],iter[1]});
    }
    int end=pq.top().second;
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        if(temp.first<end){
            if(temp.second<end){
                end=temp.second;
            }
        }else{
            answer++;
            end=temp.second;
        }
    }
    return answer;
}