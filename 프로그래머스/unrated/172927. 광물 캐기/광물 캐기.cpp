#include <string>
#include <vector>

using namespace std;

int answer=50000;
void recu(vector<int> picks, vector<string> minerals, int mineralIdx, int tired){
    if(mineralIdx<minerals.size()){
        if(picks[0]){
            int tempTired=tired;
            vector<int> tempPicks=picks;
            tempPicks[0]--;
            for(int i=0;i<5;i++){
                if(mineralIdx+i<minerals.size()){
                    tempTired++;
                }
            }
            recu(tempPicks,minerals,mineralIdx+5,tempTired);
        }
        if(picks[1]){
            int tempTired=tired;
            vector<int> tempPicks=picks;
            tempPicks[1]--;
            for(int i=0;i<5;i++){
                if(mineralIdx+i<minerals.size()){
                    if(minerals[mineralIdx+i]=="diamond"){
                        tempTired+=5;
                    }else{
                        tempTired++;
                    }
                }
            }
            recu(tempPicks,minerals,mineralIdx+5,tempTired);
        }
        if(picks[2]){
            int tempTired=tired;
            vector<int> tempPicks=picks;
            tempPicks[2]--;
            for(int i=0;i<5;i++){
                if(mineralIdx+i<minerals.size()){
                    if(minerals[mineralIdx+i]=="diamond"){
                        tempTired+=25;
                    }else if(minerals[mineralIdx+i]=="iron"){
                        tempTired+=5;
                    }else{
                        tempTired++;
                    }
                }
            }
            recu(tempPicks,minerals,mineralIdx+5,tempTired);
        }
        if(picks[0]==0&&picks[1]==0&&picks[2]==0){
            if(answer>tired){
                answer=tired;
            }
        }
    }else{
        if(answer>tired){
            answer=tired;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    recu(picks,minerals,0,0);
    return answer;
}