#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>,greater<int>> q;

int solution(int n, int k, vector<int> enemy) {
    int answer = k;
    int enemyCount=0;
    if(k>=enemy.size()){
        return enemy.size();
    }
    for(int i=0;i<k;i++){
        q.push(enemy[i]);
    }
    for(int i=k;i<enemy.size();i++){
        q.push(enemy[i]);
        enemyCount+=q.top();
        if(enemyCount<=n){
            answer++;
        }else{
            break;
        }
        q.pop();
    }
    return answer;
}