#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  int deg;
  cin >> deg;

  int ans = 0;
  while(N--){
    int temp;
    cin >> temp;
    ans += min(abs(temp-deg), 360 - abs(temp-deg));
    deg = temp;
  }
  cout << ans;
}  