// https://www.acmicpc.net/problem/2110

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector <int> arr;
int N, K;

// 첫 지점에다가 하나를 설치하고 시작
// 현재 매개로 받은 거리보다 이전 지점과 현재 지점까지의 거리가 크거나 같아지면 공유기 추가
// 이런 방식으로 공유기 추가해서 주어진 개수 다 설치 가능한지만 확인
bool solve(int key){
  int cnt = 1;
  int cur = 0;
  for(int i=1; i<N; i++){
    if(arr[i]-arr[cur] >= key){
      cnt++;
      cur = i;
    }
  }
  if(cnt >= K)
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  cin >> N >> K;
  arr.resize(N);

  // 공유기 설치 지점들을 정렬해서 인접거리 최대 구하기 쉽게 설정
  for(int i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  // Parametric Search Template
  int s = 1;
  int e = arr[N-1] - arr[0];
  int ans;
  while(s<=e){
    int mid = (s+e) / 2;
    if(solve(mid)){
      ans = mid; 
      s = mid+1;
    }
    else
      e = mid -1;
  }

  cout << ans;
} 

/*
Parametric Search
이분탐색 영역에서 최대/최소 값의 정밀성을 잡아주고
solve() 함수에서는 현재 key값을 바탕으로 가능/불가능 여부만 판단해주기
*/ 