// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> G(n+1);
    for(auto x : edge){
        G[x[0]].push_back(x[1]);
        G[x[1]].push_back(x[0]);
    }
    
    vector<int> v(n+1, n+4);
    vector<bool> visited(n+1, false);
    queue<int> q;
    int max_dist = 0;
    
    q.push(1);
    v[1] = 1;
    visited[1] = true;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        for(auto x: G[temp]){
            if(!visited[x]){
                v[x] = v[temp]+1;
                max_dist = max(max_dist, v[x]);
                
                visited[x] = true;
                q.push(x);
            }
        }
    }
    
    for(auto x : v){
        if(x == max_dist)
            answer++;
    }
    
    return answer;
}