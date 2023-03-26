#include <string>
#include <vector>

using namespace std;

vector<int> v;
int solution(vector<int> ingredient) {
    int answer = 0;
    for(int i=0;i<ingredient.size();i++){
        v.push_back(ingredient[i]);
        if(ingredient[i]==1&&v[v.size()-2]==3&&v[v.size()-3]==2&&v[v.size()-4]==1){
            answer++;
            for(int j=0;j<4;j++){
                v.erase(v.end()-1);
            }
        }
    }
    return answer;
}