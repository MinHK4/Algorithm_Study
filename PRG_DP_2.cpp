// https://programmers.co.kr/learn/courses/30/lessons/43105

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp, org;

int dfs(int row, int col){
    
    // index가 안 맞는 경우
    if(row < 0 || col < 0 || col >= org[row].size())
        return 0;
    // memoization 기법(이미 확인한 경우)
    if(dp[row][col])
        return dp[row][col];
    
    dp[row][col] = org[row][col] + max(dfs(row-1, col), dfs(row-1, col-1));
    return dp[row][col];
}

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    
    org = triangle;
    dp.resize(triangle.size(), vector<int>(triangle.size(), 0));
    
    for(int i=0; i<dp[dp.size()-1].size(); i++)
        answer = max(answer, dfs(dp.size()-1, i));

    return answer;
}

/*
DFS + Top-down 방식으로 풀었는데
그냥 Bottom-Up 방식으로 푸는게 훨씬 더 간단하고 빨리 풀 수 있는거 같음

dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i+ 1][j]);
dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i+ 1][j + 1]);
*/