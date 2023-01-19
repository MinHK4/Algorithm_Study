// https://www.acmicpc.net/problem/1182

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr, check;
int N, S;
int limit;
int ans;

void dfs(int idx, int size){
  
  // 부분수열이 현재 지정한 길이와 같으면 합 계산해서 확인
  if(size == limit){
    int sum = 0;
    for(int x : check)
      sum += arr[x];
    if(sum == S)
      ans++;
    return;
  }

  // 넣던지 말던지 조합 만들어서 재귀적으로 경우의 수 탐색
  // idx전까지 size 개수만큼 이용해 경우의 수를 조합해왔으므로
  // idx 이후의 것 중 하나 골라서 추후 조합 만들어보기
  for(int i=idx; i<N; i++){
    check.push_back(i);
    dfs(i+1, size+1);
    check.pop_back();
  }

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> N >> S;
  arr.resize(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];

  // 부분수열의 길이를 작은 순부터 해서 모든 조합 만들기
  for(int i=1; i<=N; i++){
    limit = i;
    dfs(0,0);
  }
  
  cout << ans;
}

/*
Baktracking
재귀적으로 탐색 돌리는데 어떻게 해야 모든 경우의 수 조합할 수 있는지
재귀함수 내에서 반복문 처리를 해주는 방식으로 조합 형성하기

N의 크기가 20이므로 최대 2^20개의 조합이라 시간 내에 해결 가능했음
*/