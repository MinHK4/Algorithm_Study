#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<double> dp;
int N;

double DFS(int cur_candy){
  
  // Base Case : 사탕의 개수가 다 찼을 때
  if(cur_candy >= N)
    return 0.0;

  // Memoization : 이미 계산된 경우 값 바로 리턴 
  if(dp[cur_candy] != -1.0)
    return dp[cur_candy];

  // 처음이면서 아직 사탕의 개수가 남은 경우이므로
  // 주사위를 한번 더 던져서 각 경우의 수에서 얻은 기댓값 업데이트
  double ret = 0.0;
  for(int i=1; i<=6; i++)
    ret += (1.0 / 6.0) * (1 + DFS(cur_candy + i));
  dp[cur_candy] = ret;

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N;
  dp.resize(N+1, -1.0);
  
  cout.fixed;
  cout.precision(11);
  cout << DFS(0);
}