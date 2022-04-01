// https://www.acmicpc.net/problem/1182

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr;
int N, S;
int ans = 0;

void rec_check(int cur, int sum){

  // base case: 범위 초과
  if(cur == N)
    return;

  // 안 넣는 경우
  rec_check(cur+1, sum);
  
  // 넣는 경우
  sum += arr[cur];
  if(sum == S)
    ans++;
  rec_check(cur+1, sum);

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> N >> S;
  arr.resize(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];

  rec_check(0, 0);

  cout << ans;
}

/*
백트래킹 기법 통해서 모든 부분수열 확인해주기
*/