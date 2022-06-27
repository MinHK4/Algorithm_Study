// https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> check(n+1, 1);
    for(auto x: lost)
        check[x]--;
    for(auto x: reserve)
        check[x]++;
    
    for(int x=1; x<=n; x++){
        if(check[x] == 2){
            if(x-1>0 && !check[x-1]){
                check[x-1] = 1;
                check[x] = 1;
            }
            else if(x+1<=n && !check[x+1]){
                check[x+1] = 1;
                check[x] = 1;
            }
        }
    }

    for(auto x : check){
        if(x)
            answer++;
    }
    return answer-1;
}