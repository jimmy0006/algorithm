#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int num;
    int minValue;
    int maxValue;
    stringstream stream;
    stream.str(s);
    stream>>num;
    minValue=num;
    maxValue=num;
    while(stream>>num){
        minValue = min(minValue, num);
        maxValue = max(maxValue,num);
    }
    answer+=to_string(minValue)+" ";
    answer+=to_string(maxValue);
    return answer;
}