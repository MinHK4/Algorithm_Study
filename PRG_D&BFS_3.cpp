// https://programmers.co.kr/learn/courses/30/lessons/43163

#include <bits/stdc++.h>

using namespace std;

vector<string> org;
vector<bool> visited;
string key;
int len;
int answer = INT_MAX;

void dfs(string cur, int cnt){
        
    // 같은 경우 찾으면 현재까지 깊이 중 최소값으로 업데이트
    if(cur == key){
        answer = min(answer, cnt);
        return;
    }
    
    // 각각 단어에 대해서 1개만 다른지 체크하고
    for(int i=0; i<len; i++){
        int temp = 0;
        for(int j=0; j<org[i].size(); j++){
            if(cur[j] != org[i][j])
                temp++;
        }
        
        // 하나만 다르고 아직 안 가본 단어에 대해서 dfs 탐색
        if(temp == 1 && !visited[i]){
            visited[i] = true;
            dfs(org[i], cnt+1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    len = words.size();
    org = words;
    key = target;
    visited.resize(len, false);
    
    dfs(begin, 0);
    if(answer == INT_MAX)
        answer = 0;
    
    return answer;
}