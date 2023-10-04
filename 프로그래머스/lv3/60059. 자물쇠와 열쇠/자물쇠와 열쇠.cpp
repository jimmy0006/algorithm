#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool func(vector<vector<int>> key, vector<vector<int>> lock){
    int M = key.size();//3
    int N = lock.size();//3
    for(int i=0;i<(M+N-1);i++){//0 1 2 3 4
        for(int j=0;j<(M+N-1);j++){//0 1 2 3 4
            bool check=true;
            for(int k=0;k<N;k++){//0 1 2
                for(int l=0;l<N;l++){//0 1 2
                    
                    //cout<<"i: "<<i<<", j: "<<j<<", k: "<<k<<", l: "<<l;
                    if(i>=k && (i-M+1)<=k && j>=l && (j-M+1)<=l){
                        if(lock[k][l]==1 && key[M-1-i+k][M-1-j+l]==1){
                            check=false;
                            //cout<<"  conflict!\n";
                            break;
                        }else if(lock[k][l]==0 && key[M-1-i+k][M-1-j+l]==0){
                            check=false;
                            //cout<<"  conflict!\n";
                            break;
                        }
                        //cout<<"pass"<<"\n";
                    }else{
                        if(lock[k][l]==0){
                            check=false;
                            //cout<<"  conflict!\n";
                            break;
                        }
                        //cout<<"pass"<<"\n";
                    }
                }
                if(check==false){
                    break;
                }
            }
            if(check){
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    vector<vector<int>> key2;
    vector<vector<int>> key3;
    vector<vector<int>> key4;
    for(int i=0;i<M;i++){
        vector<int> tempKey2;
        vector<int> tempKey3;
        vector<int> tempKey4;
        for(int j=0;j<M;j++){
            tempKey2.push_back(key[M-1-j][i]);
            tempKey3.push_back(key[M-1-i][M-1-j]);
            tempKey4.push_back(key[j][M-1-i]);
        }
        key2.push_back(tempKey2);
        key3.push_back(tempKey3);
        key4.push_back(tempKey4);
    }
    return func(key,lock)||func(key2,lock)||func(key3,lock)||func(key4,lock);
}