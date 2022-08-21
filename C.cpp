#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int P, N;
  cin >> P >> N;

  vector<int> num(N);
  for(int i=0; i<N; i++){
    cin >> num[i];
  }
  sort(num.begin(), num.end());

  int ans = 0;
  for(int i=0; i<N && P<200; i++){
    ans++;
    P += num[i];
  }
  cout << ans;
}