#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

bool isPrime(long p){
    if(p<=1){
        return false;
    }
    for(int j=2;j<=sqrt(p);j++){
        if(p%j==0){
            return false;
        }
    }
    return true;
}

string intToString(int n, int k){
    string res="";
    while(n){
        res=to_string(n%k)+res;
        n/=k;
    }
    return res;
}

long stringToInt(string num){
    long res=0;
    for(char iter:num){
        res*=10;
        res+=iter-'0';
    }
    return res;
}

int solution(int n, int k) {
    int answer = 0;
    string num = intToString(n,k);
    for(int i=0;i<num.length();i++){
        if(num[i]=='0'){
            num[i]=' ';
        }
    }
    stringstream stream;
    stream.str(num);
    string temp;
    while(stream>>temp){
        if(isPrime(stringToInt(temp))){
            answer++;
        }
    }
    return answer;
}