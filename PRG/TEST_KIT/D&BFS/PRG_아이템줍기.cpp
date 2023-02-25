// https://school.programmers.co.kr/learn/courses/30/lessons/87694

#include <bits/stdc++.h>

#define MAX_SIZE 120

using namespace std;

vector<vector<int>> dp(MAX_SIZE, vector<int>(MAX_SIZE, -1));
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValidPos(int r, int c){
    return 0 <= r && r < MAX_SIZE && 0 <= c && c < MAX_SIZE;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 직사각형의 좌표 모양 그려주기
    // 간혹 테두리가 인접해서 구분이 되지 않는 경우가 발생하기 때문에 좌표의 값을 기본적으로 2배처리 해줘서 구분하고
    // 결과값 반영시에만 다시 거리를 2로 나누는 방식
    for(auto rect: rectangle){
        for(int i=rect[0]*2; i<=rect[2]*2; i++){
            for(int j=rect[1]*2; j<=rect[3]*2; j++){
                if(dp[i][j] == 0) continue;
                if(i == rect[0]*2 || i == rect[2]*2 || j== rect[1]*2 || j == rect[3]*2) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    }    
    
    // 좌표 시스템에서 최단 거리를 찾을 때는 dp + BFS 방식 활용하기
    queue<pair<int, int>> q;
    q.push({characterX*2, characterY*2});
    dp[characterX*2][characterY*2] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValidPos(nx, ny) && dp[nx][ny] == 1){
                dp[nx][ny] = dp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dp[itemX*2][itemY*2] / 2;
}