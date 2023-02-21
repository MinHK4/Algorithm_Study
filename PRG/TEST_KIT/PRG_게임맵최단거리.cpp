#include<vector>
#include<queue>
using namespace std;

struct Pos {
    int y;
    int x;
    int dist; // 거리
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    const int n = maps.size();
    const int m = maps[0].size();
    int deltaY[4] = { -1, 0, 1, 0 };
    int deltaX[4] = { 0, 1, 0, -1 };

    vector<vector<bool>> checked(n, vector<bool>(m));
    queue<Pos> q;

    q.push({0, 0, 1}); // 출발지의 거리는 1
    checked[0][0] = true;

    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();
        
        int nowY = pos.y;
        int nowX = pos.x;
        int now_dist = pos.dist;
        
        if (nowY == n - 1 && nowX == m - 1) // 목적지 원소(Pos) Pop될시 거리를 answer 에 옮겨주기
            answer = now_dist;

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                continue;
            if (maps[nextY][nextX] == 0)
                continue;
            if (checked[nextY][nextX])
                continue;

            q.push({nextY, nextX, now_dist + 1}); // 거리 저장
            checked[nextY][nextX] = true;
        }
    }
        
    return answer;
}



// #include<bits/stdc++.h>

// using namespace std;
// using pii = pair <int, int>;

// vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// int answer = INT_MAX;
// int width, height;

// bool checkValidPos(int row, int col){
//     return 0 <= row && row < width &&  0 <= col && col < height;
// }

// int solution(vector<vector<int>> maps){
//     width = maps.size();
//     height = maps[0].size();
    
//     queue<pii> q;
//     q.push({0, 0});
    
//     while(!q.empty()){
//         pii cur = q.front();
//         q.pop();
        
//         for(auto dir : dirs){
//             int new_r = cur.first + dir[0], new_c = cur.second + dir[1];
            
//             if(!checkValidPos(new_r, new_c)) continue;
//             if(maps[new_r][new_c] != 1 || new_r + new_c == 0) continue;
                
//             maps[new_r][new_c] = maps[cur.first][cur.second] + 1;
//             q.push({new_r, new_c});
//         }
        
//         if(maps[width-1][height-1] != 1) return maps[width-1][height-1];
//     }
    
//     return -1;
// }

