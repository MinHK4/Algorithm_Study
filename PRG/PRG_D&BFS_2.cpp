// https://programmers.co.kr/learn/courses/30/lessons/43162

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;

void dfs(int cur){
    visited[cur] = true;
    for(auto v : G[cur]){
        if(!visited[v])
            dfs(v);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    G.resize(n);
    visited.resize(n, false);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && computers[i][j] == 1)
                G[i].push_back(j);
        }
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            answer++;
            dfs(i);
        }
    }
    
    return answer;
}