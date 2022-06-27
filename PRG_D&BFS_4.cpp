// https://programmers.co.kr/learn/courses/30/lessons/43164

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> answer, org;
vector<string> temp;
vector<bool> used;
int len;

void dfs(int idx){
    
    bool flag = true;
    for(auto x: used){
        if(!x) flag = false;
    }
    
    // 다 채운 경우
    if(flag){
        answer.push_back(temp);
        return;
    }
    
    // 더 깊게 탐색하기
    for(int i=0; i<len; i++){
        if(!used[i] && org[i][0] == org[idx][1]){
            used[i] = true;
            temp.push_back(org[i][1]);
            dfs(i);
            temp.pop_back();
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    len = tickets.size();
    used.resize(len, false);
    org = tickets;
    temp.push_back("ICN");
    
    for(int i=0; i<len; i++){
        if(tickets[i][0] == "ICN"){
            used[i] = true;
            temp.push_back(tickets[i][1]);
            dfs(i);
            temp.pop_back();
            used[i] = false;
        }
    }
    
    sort(answer.begin(), answer.end());
    // for(auto x: answer){
    //     for(auto y: x)
    //         cout << y << ' ';
    //     cout << '\n';
    // }

    return answer[0];
}