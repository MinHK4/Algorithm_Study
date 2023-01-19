// https://programmers.co.kr/learn/courses/30/lessons/42627

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // 우선은 요청 시간 순서대로 정렬
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> RQT(jobs.begin(), jobs.end());
    
    int time = 0;
    
    // 현재 시간 전에 요청이 들어온 작업들 중에서 가장 실행 시간이 짧은 작업 우선으로 진행
    while(!RQT.empty()){
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> EXE;
        
        // 현재 시간 보다 이전에 요청인 것들 모으기
        // 이전 시간인 것이 없으면 가장 일찍 시간하는 걸로 써야 하므로 do while문 사용하기
        do {
            EXE.push({RQT.top()[1], RQT.top()[0]});
            RQT.pop();
        } while(!RQT.empty() && RQT.top()[0] <= time);
        
        // 그 중 가장 실행시간이 짧은 것 중에서
        // 바로 실행가능한 경우
        if(EXE.top()[1] < time){
            time += EXE.top()[0];
            answer += time - EXE.top()[1];
        }
        // 기다렸다가 실행해야 하는 경우
        else{
            time = EXE.top()[1] + EXE.top()[0];
            answer += EXE.top()[0];
        }
        EXE.pop();
        
        // EXE에 남아있는 다른 후보들 다시 RQT에 넣어주기
        while(!EXE.empty()){
            RQT.push({EXE.top()[1], EXE.top()[0]});
            EXE.pop();
        }
    }
    
    answer /= jobs.size();
    
    return answer;
}