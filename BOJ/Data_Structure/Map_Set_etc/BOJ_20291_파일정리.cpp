#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  
  map <string, int> M;
  while (N--) {
    string str;
    cin >> str;
    
    int i;
    for (i = 0; str[i] != '.'; i++);
    M[&str[i+1]]++;
  }
  vector <pair<string, int >> v(M.begin(), M.end());
  sort(v.begin(), v.end());

  for (pair<string, int> x : v)
    cout << x.first << ' ' << x.second << '\n';
}