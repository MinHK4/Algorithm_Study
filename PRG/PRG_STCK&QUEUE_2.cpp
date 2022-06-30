// https://programmers.co.kr/learn/courses/30/lessons/42587

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    deque <pair <int, int>> d;
    priority_queue <int> pq;
    for(int i=0; i<priorities.size(); i++){
        d.push_back({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(1){
        if(d[0].first == pq.top()){
            int idx = d[0].second;
            d.pop_front();
            pq.pop();
            answer++;
            if(idx == location)
                return answer;
        }
        else{
            d.push_back(d[0]);
            d.pop_front();
        }
    }    
}