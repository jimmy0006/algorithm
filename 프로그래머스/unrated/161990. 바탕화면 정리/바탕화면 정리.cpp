#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int lux=wallpaper.size();
    int luy=wallpaper[0].length();
    int rdx=0;
    int rdy=0;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].length();j++){
            if(wallpaper[i].substr(j,1)=="#"){
                if(i<lux){
                    lux=i;
                }
                if(j<luy){
                    luy=j;
                }
                if(i+1>rdx){
                    rdx=i+1;
                }
                if(j+1>rdy){
                    rdy=j+1;
                }
            }
        }
    }
    vector<int> answer{lux, luy,rdx,rdy};
    return answer;
}