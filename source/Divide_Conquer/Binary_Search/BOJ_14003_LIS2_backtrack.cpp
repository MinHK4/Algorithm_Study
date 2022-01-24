// https://www.acmicpc.net/problem/14003

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  vector<int> P(N);
  vector<int> L;
  L.push_back(arr[0]);
  P[0] = 0;
  for(int i=1; i<N; i++){
    if(L.back() < arr[i]){
      L.push_back(arr[i]);
      P[i] = L.end() - L.begin() - 1;
    }
    else{
      auto iter = lower_bound(L.begin(), L.end(), arr[i]);
      *iter = arr[i];
      P[i] = iter - L.begin();
    }
  }
  int len = L.size();
  cout << len-- << '\n';

  // backtrack
  stack<int> ans;
  for(int i=N-1; i>=0; i--){
    if(P[i] == len){
      ans.push(arr[i]);
      len--;
    }
  }
  while(!ans.empty()){
    cout << ans.top() << ' ';
    ans.pop();
  }
}

/*
디테일한 풀이 설명 : https://seungkwan.tistory.com/8
L[i] 길이가 i인 LIS를 만들 수 있는 마지막 원소 중 가장 작은 값
일차원적으로 접근하면 그냥 마지막 값보다 크면 뒤에 쌓고
작으면 하나 빼서 대체한다의 방식으로 접근할 수 있는데
여기서 발생할 수 있는 문제가 여러 개를 빼주는게 뒤에 오는 수들의 조합 상
더 긴 LIS를 만들 수 있는 경우이다

따라서 이를 위해서 i 길이의 LIS를 만들 수 있는 마지막 원소값을 저장하고 있어야 한다
그래야 뒤에서 새롭게 LIS를 구성해갈 때 그 순서에 맞춰서 뒤에것을 채워나갈 수 있다.
이 위치를 찾는 것은 이분탐색을 기반으로 하는 lower_bound를 활용하면 된다.

P[i]는 i번째 수가 L배열에서 몇번째 인덱스에 있어야 하는지 저장
이를 바탕으로 역순 트래킹해주기
*/ 