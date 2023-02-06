#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

int arr[200002]={0};
queue<int> q;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,K;
    cin>>N>>K;
    q.push(N);
    arr[N]=1;
    int temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp>0){
            if(temp/2==K){
                cout<<arr[temp]-1<<"\n";
                break;
            }
            if(temp*2==K){
                cout<<arr[temp]-1<<"\n";
                break;
            }
            if(temp+1==K||temp-1==K){
                cout<<arr[temp]<<"\n";
                break;
            }
            
        }
    }
}