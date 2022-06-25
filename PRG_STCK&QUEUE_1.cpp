// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> deploy;
    for(int i=0; i<progresses.size(); i++){
        int temp = 100 - progresses[i];
        deploy.push(temp % speeds[i] == 0 ? temp / speeds[i] : temp / speeds[i] + 1);
    }
    
    while(!deploy.empty()){
        int top = deploy.front();
        deploy.pop();
        int cnt = 1;
        while(!deploy.empty() && top >= deploy.front()){
            deploy.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}