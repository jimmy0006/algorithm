#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int earn=0;
int maxUsers=0;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    for(int i=0;i<(pow(4,emoticons.size()));i++){
        int iter = i;
        vector<int> discounts;
        for(int j=0;j<emoticons.size();j++){
            int discount = iter%4 + 1;
            iter/=4;
            discounts.push_back(discount*10);
        }
        int countUsers=0;
        int earnMoney=0;
        for(vector<int> iter2:users){
            int buyMoney=0;
            for(int j=0;j<emoticons.size();j++){
                if(discounts[j]>=iter2[0]){
                    buyMoney+=(emoticons[j]/100)*(100-discounts[j]);
                }
            }
            if(buyMoney>=iter2[1]){
                countUsers++;
            }else{
                earnMoney+=buyMoney;
            }
        }
        if(maxUsers<countUsers){
            maxUsers = countUsers;
            earn = earnMoney;
        }else if(maxUsers==countUsers && earn<=earnMoney){
            earn=earnMoney;
        }
    }
    answer.push_back(maxUsers);
    answer.push_back(earn);
    return answer;
}