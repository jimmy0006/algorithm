#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isCor(string p){
    int stack=0;
    for(char temp:p){
        if(temp=='('){
            stack++;
        }else{
            stack--;
        }
        if(stack<0){
            return false;
        }
    }
    if(stack!=0){
        return false;
    }else{
        return true;
    }
}

string recu(string p){
    if(p.length()==0){
        return "";
    }else{
        int stacker;
        if(p[0]=='('){
            stacker=1;
        }else{
            stacker=-1;
        }
        for(int i=1;i<p.length();i++){
            if(p[i]=='('){
                stacker++;
            }else{
                stacker--;
            }
            
            if(stacker==0){
                if(isCor(p.substr(0,i+1))){
                    return p.substr(0,i+1)+recu(p.substr(i+1,p.length()-i-1));
                }else{
                    string res="(";
                    res+=recu(p.substr(i+1,p.length()-i-1));
                    res+=")";
                    for(int j=1;j<i;j++){
                        if(p[j]=='('){
                            res+=')';
                        }else{
                            res+='(';
                        }
                    }
                    return res;
                }
            }
        }
    }
}

string solution(string p) {
    return recu(p);
}