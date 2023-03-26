#include <string>
#include <vector>

using namespace std;
int aA[]={1,2,3,4,5};
int bA[]={2,1,2,3,2,4,2,5};
int cA[]={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a=0;
    int b=0;
    int c=0;
    for(int i=0;i<answers.size();i++){
        if(answers[i]==aA[i%5]){
            a++;
        }
        if(answers[i]==bA[i%8]){
            b++;
        }
        if(answers[i]==cA[i%10]){
            c++;
        }
    }
    int max=0;
    if(a>max){
        max=a;
    }
    if(b>max){
        max=b;
    }
    if(c>max){
        max=c;
    }
    if(a==max){
        answer.push_back(1);
    }
    if(b==max){
        answer.push_back(2);
    }
    if(c==max){
        answer.push_back(3);
    }
    return answer;
}