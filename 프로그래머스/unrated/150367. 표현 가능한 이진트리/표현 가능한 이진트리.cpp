#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int checkZero(string s){
    if(s.size()>1){
        int temp1 = checkZero(s.substr(0,s.size()/2));
        int temp2 = checkZero(s.substr(s.size()/2+1,s.size()/2));
        if(temp1==-1||temp2==-1){
            return -1;
        }
        if(s.substr(s.size()/2,1)=="0"){
            if(temp1==0&&temp2==0){
                return 0;
            }else{
                return -1;
            }
        }
        return 1;
    }else{
        return stoi(s);
    }
}

int test(long long number){
    string s="";
    while(number>0){
        s=to_string((int)(number%2))+s;
        number/=2;
    }
    int length = s.size();
    int maxLength=1;
    while(length>maxLength){
        maxLength*=2;
        maxLength+=1;
    }
    for(int i=0;i<maxLength-length;i++){
        s="0"+s;
    }
    return checkZero(s);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(long long iter:numbers){
        int ansTemp = test(iter);
        if(ansTemp==-1){
            answer.push_back(0);
        }else{
            answer.push_back(1);
        }
    }
    return answer;
}