#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int counter=1;
    string temp= s.substr(0,1);
    for(int i=1;i<s.size();i++){
        if(temp==s.substr(i,1)){
            counter++;
        }else{
            counter--;
        }
        if(counter==0){
            answer++;
            if(i<s.size()-1){
                temp=s.substr(i+1,1);
                cout<<temp<<"\n";
                counter=1;
                i++;
            }
        }
    }
    if(counter){
        answer++;
    }
    return answer;
}