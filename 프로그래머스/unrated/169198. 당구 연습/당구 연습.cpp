#include <string>
#include <vector>
#include <cmath>

using namespace std;

int distance(int x, int y, int targetx,int targety){
    return (x-targetx)*(x-targetx)+(y-targety)*(y-targety);
}

int lowestDistance(int m, int n, int startX, int startY,int x, int y){
    int maxDistance = 1000000;
    if(startY==y){
        if(startX<x){
            int dis1 = distance(x, -y, startX, startY);
            if(dis1<maxDistance){
                maxDistance = dis1;
            }
            int dis2 = distance(-x,y,startX,startY);
            if(dis2<maxDistance){
                maxDistance = dis2;
            }
            int dis4 = distance(x,2*n-y,startX,startY);
            if(dis4<maxDistance){
                maxDistance = dis4;
            }
        }else{
            int dis1 = distance(x, -y, startX, startY);
            if(dis1<maxDistance){
                maxDistance = dis1;
            }
            int dis3 = distance(2*m-x, y,startX,startY);
            if(dis3<maxDistance){
                maxDistance = dis3;
            }
            int dis4 = distance(x,2*n-y,startX,startY);
            if(dis4<maxDistance){
                maxDistance = dis4;
            }
        }
    }else if(startX==x){
        if(startY<y){
            int dis1 = distance(x, -y, startX, startY);
            if(dis1<maxDistance){
                maxDistance = dis1;
            }
            int dis2 = distance(-x,y,startX,startY);
            if(dis2<maxDistance){
                maxDistance = dis2;
            }
            int dis3 = distance(2*m-x, y,startX,startY);
            if(dis3<maxDistance){
                maxDistance = dis3;
            }
        }else{
            int dis2 = distance(-x,y,startX,startY);
            if(dis2<maxDistance){
                maxDistance = dis2;
            }
            int dis3 = distance(2*m-x, y,startX,startY);
            if(dis3<maxDistance){
                maxDistance = dis3;
            }
            int dis4 = distance(x,2*n-y,startX,startY);
            if(dis4<maxDistance){
                maxDistance = dis4;
            }
        }
    }else{
        int dis1 = distance(x, -y, startX, startY);
        int dis2 = distance(-x,y,startX,startY);
        int dis3 = distance(2*m-x, y,startX,startY);
        int dis4 = distance(x,2*n-y,startX,startY);
        if(dis1<maxDistance){
        maxDistance = dis1;
        }
        if(dis2<maxDistance){
            maxDistance = dis2;
        }
        if(dis3<maxDistance){
            maxDistance = dis3;
        }
        if(dis4<maxDistance){
            maxDistance = dis4;
        }
    }
    return maxDistance;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(vector<int> iter:balls){
        answer.push_back(lowestDistance(m,n,startX,startY,iter[0],iter[1]));
    }
    return answer;
}