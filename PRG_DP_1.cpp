// https://programmers.co.kr/learn/courses/30/lessons/42895

#include<bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    
    vector<set<int>> DP(9);
    
    // i번 사용해서 만들 수 있는 수들 DP에 넣어주기
    for(int i=1; i<=8; i++){
        
        // NNN꼴의 숫자 넣어주기
        int temp = N;
        for(int j=1; j<i; j++)
            temp = temp * 10 + N;
        DP[i].insert(temp);
        
        // j+k가 i인 숫자활용 수들의 조합으로 새 숫자 만들기
        for(int j=1; j<=7; j++){
            for(int k=1; k<=7; k++){
                if(j+k == i){
                    
                    // 사칙연산으로 만들 수 있는 수 다 넣어주기
                    // 최소 횟수로 조합하는게 목적이기 때문에 만들어진 수가 0보다 커야 함
                    for(auto x : DP[j]){
                        for(auto y : DP[k]){
                            DP[i].insert(x+y);
                            DP[i].insert(x*y);
                            if(y-x> 0)
                                DP[i].insert(y-x);
                            if(x-y>0)
                                DP[i].insert(x-y);
                            if(y/x> 0)
                                DP[i].insert(y/x);
                            if(x/y> 0)
                                DP[i].insert(x/y);
                        }
                    }
                }
            }
        }
        // i번 N을 사용해서 만들 수 있는 수 안에 있는지 확인
        if(DP[i].find(number)!=DP[i].end())
            return i;
    }
    // 8번 이내로 조합할 수 없는 경우
    return -1;
}

/*
DP[i]는 N을 i번 써서 만들 수 있는 수들의 집합
따라서 평범한 DP와는 다르게 set를 이용해서 DP 관리
*/