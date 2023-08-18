#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

deque<int> d;
int arr[1000000];

int solution(vector<int> order) {
    for(int i=0;i<order.size();i++){
        arr[order[i]-1]=i+1;
    }
    int answer = 0;
    int idx=0;
    int target =1;
    while(true){
        if((!d.empty())&&d.front()==target){
            d.pop_front();
            answer++;
            target++;
            continue;
        }
        if(arr[idx]==target){
            answer++;
            idx++;
            target++;
            continue;
        }
        if(idx<order.size()){
            d.push_front(arr[idx]);
            idx++;
            continue;
        }
        break;
    }
    return answer;
}