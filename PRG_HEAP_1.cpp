// https://programmers.co.kr/learn/courses/30/lessons/42626

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    for(auto x : scoville)
        pq.push(-x);
    
    while(-pq.top() < K){
        
        // 만들 수 없는 경우
        if(pq.size() == 1)
            return -1;
        
        int temp1 = -pq.top();
        pq.pop();
        int temp2 = -pq.top();
        pq.pop();
        pq.push(-(temp1 + temp2*2));
        answer++;
    }
    
    return answer;
}

/*
priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());
PQ 작은 수부터 나오게 설정 + vector 정보 바로 받아오기
*/