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

int Top_Down_solution(vector<vector<int>> triangle) {
    int answer = -1;
    
    org = triangle;
    dp.resize(triangle.size(), vector<int>(triangle.size(), 0));
    
    for(int i=0; i<dp[dp.size()-1].size(); i++)
        answer = max(answer, dfs(dp.size()-1, i));

    return answer;
}


///////////////////////////////////////////////


int Bottom_Up_solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // DP 배열 초기화
    vector<vector<int>> dp(triangle.size());
    for(int i = 0 ; i < triangle.size(); i++){
        dp[i].resize(triangle[i].size());
    }
    dp[0][0] = triangle[0][0];
    
    // DP[i][j] 는 꼭대기부터 (i,j)까지 온 루트의 합의 최댓값
    // DP[i][j] = tri[i][j] + max(DP[i-1][j], DP[i-1][j-1])
    // 인덱싱만 조심해주기
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            int temp = 0;
            if(0 <= j && j < dp[i-1].size())
                temp = max(temp,dp[i-1][j]);
            if(0 <= j-1 && j-1 < dp[i-1].size())
                temp = max(temp,dp[i-1][j-1]);
            dp[i][j] = triangle[i][j] + temp;
        }
    }
    
    // 맨 끝 열에서 가장 큰 값 찾아서 return
    int N = triangle.size() - 1;
    for(int j = 0; j < triangle[N].size(); j++)
        answer = max(answer, dp[N][j]);
    return answer;
}