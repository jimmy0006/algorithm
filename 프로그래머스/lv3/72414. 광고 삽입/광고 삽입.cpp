#include <string>
#include <vector>
#include <sstream>

using namespace std;

int arr[360100];

int timeToInt(string time){
    for(int i=0;i<time.size();i++){
        if(time[i]==':'){
            time[i]=' ';
        }
    }
    stringstream stream;
    stream.str(time);
    int res;
    int temp;
    stream>>res;
    res*=60;
    stream>>temp;
    res+=temp;
    stream>>temp;
    res*=60;
    res+=temp;
    return res;
}

pair<int,int> timeToInt2(string time){
    for(int i=0;i<time.size();i++){
        if(time[i]==':'||time[i]=='-'){
            time[i]=' ';
        }
    }
    stringstream stream;
    stream.str(time);
    int res1=0;
    int res2=0;
    int temp;
    stream>>temp;
    res1=temp;
    stream>>temp;
    res1=res1*60+temp;
    stream>>temp;
    res1=res1*60+temp;
    
    stream>>temp;
    res2=temp;
    stream>>temp;
    res2=res2*60+temp;
    stream>>temp;
    res2=res2*60+temp;
    return {res1,res2};
}

string placeHolder(int n){
    if(n>=10){
        return to_string(n);
    }else{
        return "0"+to_string(n);
    }
}

string intToString(int time){
    int hour = time/3600;
    string hour2;
    time%=3600;
    int minutes = time/60;
    int sec = time%60;
    return placeHolder(hour)+":"+placeHolder(minutes)+":"+placeHolder(sec);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(string iter:logs){
        pair<int,int> temp = timeToInt2(iter);
        arr[temp.first]+=1;
        arr[temp.second]-=1;
    }
    int maxTime = timeToInt(play_time);
    int adTime = timeToInt(adv_time);
    for(int i=1;i<=maxTime;i++){
        arr[i]+=arr[i-1];
    }
    long long watchCount=0;
    long long maxWatch=0;
    int maxWatchTime=0;
    for(int i=0;i<adTime;i++){
        watchCount+=arr[i];
    }
    maxWatch = watchCount;
    for(int i=adTime;i<=maxTime;i++){
        watchCount+=arr[i]-arr[i-adTime];
        if(watchCount>maxWatch){
            maxWatch = watchCount;
            maxWatchTime = i-adTime+1;
        }
    }
    return intToString(maxWatchTime);
}