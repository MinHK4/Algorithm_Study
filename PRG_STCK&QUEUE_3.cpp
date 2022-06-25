// https://programmers.co.kr/learn/courses/30/lessons/42583

#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    
    deque<int> wait, doing ,done;
    int total = truck_weights.size();
    for(auto truck : truck_weights)
        wait.push_back(truck);
    for(int i=0; i<bridge_length; i++)
        doing.push_back(0);
    
    int sum = 0;
    while(done.size() != total){
        time++;
        
        // 건너는 트럭 빼주기
        sum -= doing[0];
        if(doing[0])
            done.push_back(doing[0]);
        doing.pop_front();
        
        // 기다리는 트럭 넣어주기
        if(wait.size()>0 && sum+wait[0] <= weight){
            sum += wait[0];
            doing.push_back(wait[0]);
            wait.pop_front();
        }
        // 다리 길이 맞춰주기
        else
            doing.push_back(0);
    }
    
    return time;
}