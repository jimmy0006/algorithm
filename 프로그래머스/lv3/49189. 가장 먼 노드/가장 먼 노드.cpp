#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
int visited[20001];
vector<int> roads[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int distance=0;
    for(vector<int> iter:edge){
        roads[iter[0]].push_back(iter[1]);
        roads[iter[1]].push_back(iter[0]);
    }
    q.push({1,1});
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        if(visited[temp.first]){
            continue;
        }else{
            visited[temp.first]=temp.second;
            for(int iter:roads[temp.first]){
                q.push({iter,temp.second+1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==distance){
            answer++;
        }else if(visited[i]>distance){
            answer=1;
            distance=visited[i];
        }
    }
    return answer;
}