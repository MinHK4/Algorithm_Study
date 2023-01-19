// https://programmers.co.kr/learn/courses/30/lessons/42860

#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.size();
    vector<int> v(n);
    int spot = n - 1;
    for(int i=0; i<n; i++){
        // 알파벳 맞추는데 필요한 조작 수 더해주기
        int temp = name[i] - 'A';
        v[i] = temp < 26 - temp ? temp: 26 - temp;
        answer += v[i];
        
        // 위치 맞추는데 필요한 최소 조작 수 구하기
        // 각 위치에서 각 위치까지의 순이동: i 
        // + 뒤에서부터 A만나기 전까지 : n-idx) 
        // + 그리고 반환이 필요한 경우 더 둘 중 짧은 것 : min(i, n-idx)
        int idx = i + 1;
        while(idx<n && name[idx]=='A')
            idx++;
        spot = min(spot, i+(n-idx)+min(i, n-idx));
    }
    answer += spot;
    
    return answer;
}