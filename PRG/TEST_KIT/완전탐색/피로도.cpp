// https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> DG;
vector<bool> visited;
int answer = 0;

void dfs(int left, int cnt){
    answer = max(answer, cnt);
    
    for(int i=0; i < DG.size(); i++){
       if(DG[i][0] <= left && !visited[i]){
           visited[i] = true;
           dfs(left - DG[i][1], cnt+1);
           visited[i] = false;
       }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DG = dungeons;
    visited.resize(dungeons.size(), false);
    
    dfs(k, 0);
    
    return answer;
}

