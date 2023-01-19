#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int A, B, C, M;
  cin >> A >> B >> C >> M;

  int sum_B = 0;
  int sum_M = 0;
  for(int i=1; i<=24; i++){
    if(sum_M + A <= M){
      sum_B += B;
      sum_M += A;
    }
    else
      sum_M = sum_M >= C ? sum_M - C : 0;
  }
  cout << sum_B;
}