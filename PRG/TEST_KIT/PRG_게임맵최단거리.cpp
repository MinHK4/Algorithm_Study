// https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include<bits/stdc++.h>

using namespace std;
using pii = pair <int, int>;

int solution(vector<vector<int>> maps){
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pii> q;
    q.push({0, 0});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 벗어나는 인덱스 버리기
            if(maps[nx][ny] != 1) continue; // 벽이거나 이미 들른 위치는 버리기
                
            maps[nx][ny] = maps[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    if(maps[n-1][m-1] != 1) return maps[n-1][m-1];
    return -1;
}