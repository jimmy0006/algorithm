#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int,int> mX;
map<int,int> mY;

string solution(string X, string Y) {
    string answer = "";
    for(int i=0;i<10;i++){
        mX[i]=0;
        mY[i]=0;
    }
    for(int i=0;i<X.length();i++){
        mX[stoi(X.substr(i,1))]+=1;
    }
    for(int i=0;i<Y.length();i++){
        mY[stoi(Y.substr(i,1))]+=1;
    }
    for(int i=9;i>=0;i--){
        if(mX[i]>mY[i]){
            for(int j=0;j<mY[i];j++){
                answer+=to_string(i);
            }
        }else{
            for(int j=0;j<mX[i];j++){
                answer+=to_string(i);
            }
        }
    }
    if(answer.substr(0,1)=="0"){
        answer="0";
    }
    if(answer.length()==0){
        answer="-1";
    }
    return answer;
}