//https://programmers.co.kr/learn/courses/30/lessons/43165

#include<bits/stdc++.h>

using namespace std;

vector<int> org;
int key;
int answer = 0;

void dfs(int idx, int sum){    
    // 정답 회귀
    if(sum == key){
        answer++;
        return;
    }
    
    // 인덱싱 처리
    if(idx >= org.size())
        return;
    
    
    for(int i=idx; i<org.size(); i++){
        if(sum+org[i]*2 <= key)
            dfs(i+1, sum+org[i]*2);
    }
}

int solution(vector<int> numbers, int target) {

    
    sort(numbers.begin(), numbers.end(), greater<>());
    int sum = 0;
    for(auto number : numbers)
        sum += number;
    
    org = numbers;
    key = sum - target;
    dfs(0, 0);
    
    return answer;
}

/*
괜히 시간초과 고려했는데 2^20이 최대 경우의 수이므로
그냥 바로 완탐 돌리는 DFS로 풀었어도 풀 수 있음
*/