// https://programmers.co.kr/learn/courses/30/lessons/49191

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> G(n+1, vector<bool>(n+1,false));
    for(auto result : results)
        G[result[0]][result[1]] = true;
    
    // 플로이드-와샬 변형
    for(int mid=1; mid<=n; mid++){
        for(int src=1; src<=n; src++){
            for(int dst=1; dst<=n; dst++)
                if(G[src][mid] && G[mid][dst])
                    G[src][dst] = true;
        }
    }
    
    // 이기거나 지는지 확인가능한지 체크
    for(int i=1; i<=n; i++){
        bool flag = true;
        for(int j=1; j<=n; j++){
            if(i != j){
                flag = flag && (G[i][j] || G[j][i]);
            }
        }
        if(flag)
            answer++;
    }
    
    return answer;
}