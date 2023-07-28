#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> loads[100001];
int visited[100001];
queue<pair<int,int>> q;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(int i=0;i<=n;i++){
        visited[i]=-1;
    }
    for(vector<int> iter:roads){
        loads[iter[0]].push_back(iter[1]);
        loads[iter[1]].push_back(iter[0]);
    }
    q.push({destination,0});
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        if(visited[temp.first]==-1){
            visited[temp.first]=temp.second;
            for(int iter:loads[temp.first]){
                q.push({iter,temp.second+1});
            }
        }
    }
    for(int iter:sources){
        answer.push_back(visited[iter]);
    }
    return answer;
}