#include <string>
#include <vector>
#include <map>

using namespace std;

struct person{
    string parent;
    int get;
};

map<string, person> m;

void sell(string name, int money){
    if(money<10){
        m[name].get+=money;
    }else{
        m[name].get+=money-money/10;
        if(m[name].parent!="-"){
            sell(m[name].parent,money/10);
        }
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i=0;i<enroll.size();i++){
        m[enroll[i]].parent = referral[i];
    }
    
    for(int i=0;i<seller.size();i++){
        sell(seller[i],amount[i]*100);
    }
    
    for(string iter:enroll){
        answer.push_back(m[iter].get);
    }
    return answer;
}