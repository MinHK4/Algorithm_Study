#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int TC;
  cin >> TC;
  while(TC--){
    int a, b, c, r;
    cin >> a >> b >> c >> r;

    if(a>b)
      swap(a,b);
    int ans = b - a;
    
    // c가 범위 안에 있을 때
    if(a <= c && c <= b){
      if(a <= c-r)
        ans -= r;
      else
        ans -= (c-a);

      if(c+r <= b)
        ans -= r;
      else
        ans -= (b-c);
    }

    if(c < a && a <= c+r){
      if(c+r <= b)
        ans -= c+r-a;
      else
        ans = 0;
    }

    if(c-r <= b && b < c)
      if(a <= c-r)
        ans -= b-c+r;
      else
        ans = 0;

    cout << ans << '\n';
  }
}