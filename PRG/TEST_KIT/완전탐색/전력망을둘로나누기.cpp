// https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp 

#include <bits/stdc++.h>

using namespace std;

int getDiff(int n, vector<vector<int>> infos){
    vector<vector<int>> G(n+1);
    vector<bool> visited(n+1, false);
    
    for(auto info: infos){
        G[info[0]].push_back(info[1]);
        G[info[1]].push_back(info[0]);
    }
    
    // BFS 활용해서 현재 정점을 기준으로 같은 전력망인 네트워크 묶음 구하기
    // 문제 조건 상 n-1개의 연결 트리이기 때문에 반드시 둘로 나누어짐
    queue<int> q;
    vector<int> arr;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int cnt = 0;
            q.push(i);
            
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                cnt++;
                
                for(auto next : G[cur]){
                    if(visited[next]) continue;
                    q.push(next);
                }
            }
            arr.push_back(cnt);
        }
    }

    return abs(arr[0] - arr[1]);
}


int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 각각 전선 하나씩 끊은 경우에 대해서 다 돌려보기
    for(int i=0; i<wires.size(); i++){
        vector<vector<int>> temp;
        for(int j=0; j<wires.size(); j++){
            if(i == j) continue;
            temp.push_back(wires[j]);
        }
        
        answer = min(answer, getDiff(n, temp));
    }
    
    return answer;
}