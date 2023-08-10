#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool avail(int x, int y, int r, int c, int k){
    int required = abs(x-r)+abs(y-c);
    if(required>k){
        return false;
    }else{
        return true;
    }
}

string moveD(int n, int m, int x, int y, int r, int c, int k){
    if(k==0){
        return "";
    }
    if(x<n){
        if(avail(x+1,y,r,c,k)){
            return "d"+moveD(n,m,x+1,y,r,c,k-1);
        }
    }
    if(y>1){
        if(avail(x,y-1,r,c,k)){
            return "l"+moveD(n,m,x,y-1,r,c,k-1);
        }
    }
    if(y<m){
        if(avail(x,y+1,r,c,k)){
            return "r"+moveD(n,m,x,y+1,r,c,k-1);
        }
    }
    return "u"+moveD(n,m,x-1,y,r,c,k-1);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int required = abs(x-r)+abs(y-c);
    if(required>k || (required-k)%2){
        return "impossible";
    }
    string answer = moveD(n,m,x,y,r,c,k);
    return answer;
}