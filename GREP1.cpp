#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(int n, string text, int second) {
    string answer = "";

    // 텍스트 전처리
    int len = text.size();
    for(int i=0; i<len; i++){
        if(text[i] == ' ')
            text[i] = '_';
    }

    // 전처리한 텍스트 넣을 deque 완성
    deque<char> input;
    for(int i=0; i<len; i++)
        input.push_back(text[i]);

    // 표시 문자에 대한 deque 완성
    deque<char> display;
    for(int i=0; i<n; i++)
        display.push_back('_'); 
    
    // 1초마다 표시 문자는 입력문자 앞에꺼 빼고 뒤에다가 채워주고
    // 1초마다 입력 문자는 표시 문자 앞에꺼 뒤로 보내서 채워주기
    for(int i=0; i<second; i++){
        display.push_back(input.front());
        input.push_back(display.front());
        display.pop_front();
        input.pop_front();
    }

    for(auto x : display)
        answer += x;
    return answer;
}