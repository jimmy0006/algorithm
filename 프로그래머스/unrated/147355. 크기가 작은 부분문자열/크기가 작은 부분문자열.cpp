#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int lenthp = p.length();
    int lentht = t.length();
    for(int i=0;i<=lentht-lenthp;i++){
        string tsub = t.substr(i,lenthp);
        bool check=true;
        for(int j=0;j<lenthp;j++){
            if(tsub[j]<p[j]){
                answer++;
                check=false;
                break;
            }else if(tsub[j]>p[j]){
                check=false;
                break;
            }
        }
        if(check){
            answer++;
        }
    }
    return answer;
}