#include <bits/stdc++.h>

using namespace std;

vector<int> filled;
int answer = 4000000;
int len, target;

void recurs_call(int idx, int water, int add){
    
    if(water == target){
        answer = min(answer, add);
        return;
    }

    for(int i=idx; i<len-1; i++){
        recurs_call(i+2, water+1, add+filled[i]);
    }
}

int solution(vector<int> bricks, int n, int k) {

    len = bricks.size();
    target = k;

    for(auto x : bricks){
        filled.push_back(n-x);
    }
    
    recurs_call(1, 1, 0);

    return answer;
}