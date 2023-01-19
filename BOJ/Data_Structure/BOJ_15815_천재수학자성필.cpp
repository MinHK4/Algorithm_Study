#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  string str;
  cin >> str;
  int len = str.length();

  stack<int> s;
  int ans = 0;
  for(int i=0; i<len; i++){
    if(str[i] >= '0' && str[i] <= '9')
      s.push(str[i] - '0');
    else{
      int temp1 = s.top();
      s.pop();
      int temp2 = s.top();
      s.pop();
      if(str[i] == '+')
        s.push(temp2+temp1);
      if(str[i] == '-')
        s.push(temp2-temp1);
      if(str[i] == '*')
        s.push(temp2*temp1);
      if(str[i] == '/')
        s.push(temp2/temp1);
    }
  }
  cout << s.top();
}