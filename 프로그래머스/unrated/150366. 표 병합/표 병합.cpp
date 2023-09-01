#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

struct cell{
    bool refed = false;
    string data="";
    int refX=0;
    int refY=0;
    vector<vector<int>> links;
};

cell arr[53][53];

vector<string> parsedCommand(string command){
    vector<string> res;
    stringstream stream;
    stream.str(command);
    string iter;
    while(stream>>iter){
        res.push_back(iter);
    }
    return res;
}

vector<int> findRef(int x,int y){
    if(arr[x][y].refed == false){
        vector<int> res;
        res.push_back(x);
        res.push_back(y);
        return res;
    }else{
        vector<int> recu = findRef(arr[x][y].refX,arr[x][y].refY);
        arr[x][y].refX = recu[0];
        arr[x][y].refY = recu[1];
        return recu;
    }
}

void deleteData(int x, int y){
    for(vector<int> iter:arr[x][y].links){
        deleteData(iter[0],iter[1]);
    }
    arr[x][y].refed=false;
    arr[x][y].data="";
    vector<vector<int>> empty;
    arr[x][y].links = empty;
}

void unMerge(int x, int y){
    vector<int> target = findRef(x,y);
    string data = arr[target[0]][target[1]].data;
    deleteData(target[0],target[1]);
    arr[x][y].data = data;
}

void printStatus(){
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            cout<<arr[i][j].data<<" "<<arr[i][j].refed<<", ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void merge(int x1, int y1, int x2, int y2){
    vector<int> target1 = findRef(x1, y1);
    vector<int> target2 = findRef(x2,y2);
    if((target1[0]!=target2[0])||(target1[1]!=target2[1])){
        if(arr[target1[0]][target1[1]].data!=""){
            vector<int> temp;
            arr[x1][y1].links.push_back(target2);
            arr[target2[0]][target2[1]].refed = true;
            arr[target2[0]][target2[1]].refX = x1;
            arr[target2[0]][target2[1]].refY = y1;
        }else{
            vector<int> temp;
            arr[x2][y2].links.push_back(target1);
            arr[target1[0]][target1[1]].refed = true;
            arr[target1[0]][target1[1]].refX = x2;
            arr[target1[0]][target1[1]].refY = y2;
        }
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(string iter:commands){
        vector<string> command = parsedCommand(iter);
        if(command[0]=="UPDATE"&&command.size()==3){
            for(int i=1;i<51;i++){
                for(int j=1;j<51;j++){
                    if(arr[i][j].data==command[1]){
                        arr[i][j].data=command[2];
                    }
                }
            }
        }else if(command[0]=="UPDATE"){
            vector<int> target = findRef(stoi(command[1]),stoi(command[2]));
            arr[target[0]][target[1]].data=command[3];
        }else if(command[0]=="MERGE"){
            merge(stoi(command[1]),stoi(command[2]),stoi(command[3]),stoi(command[4]));
        }else if(command[0]=="UNMERGE"){
            unMerge(stoi(command[1]),stoi(command[2]));
        }else if(command[0]=="PRINT"){
            vector<int> target = findRef(stoi(command[1]),stoi(command[2]));
            if(arr[target[0]][target[1]].data==""){
                answer.push_back("EMPTY");
            }else{
                answer.push_back(arr[target[0]][target[1]].data);
            }
        }
        //printStatus();
    }
    return answer;
}