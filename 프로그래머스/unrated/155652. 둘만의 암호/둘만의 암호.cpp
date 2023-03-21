#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i=0;i<s.length();i++){
        int temp=s[i];
        int count=index;
        while(count){
            temp++;
            if(temp==123){
                temp='a';
            }
            bool check=false;
            for(int j=0;j<skip.length();j++){
                if(temp==skip[j]){
                    check=true;
                    break;
                }
            }
            if(check){
                continue;
            }
            count--;
        }
        answer+=temp;
    }
    
    return answer;
}