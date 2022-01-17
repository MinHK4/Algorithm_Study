#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int num;
  cin >> num;

  stack <int> s;

  while(num--){
    int temp;
    cin >> temp;
    if(temp != 0)
      s.push(temp);
    else
      s.pop();
  }

  int ans = 0;
  while(!s.empty()){
    ans += s.top();
    s.pop();
  }
  cout << ans;
}