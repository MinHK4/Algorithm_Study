#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int left(char c){
  if(c == 'q')
    return 1;
  if(c == 'w')
    return 1;
  if(c == 'e')
    return 1;
  if(c == 'r')
    return 1;
  if(c == 't')
    return 1;
  if(c == 'a')
    return 1;
  if(c == 's')
    return 1;
  if(c == 'd')
    return 1;
  if(c == 'f')
    return 1;
  if(c == 'g')
    return 1;
  if(c == 'z')
    return 1;
  if(c == 'x')
    return 1;
  if(c == 'c')
    return 1;
  if(c == 'v')
    return 1;
  if(c == 'b')
    return 1;
  return -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  string str;
  cin >> str;

  int len = str.length();
  int check = left(str[0]);
  
  bool flag = true;
  for(int i=1; i<len; i++){
    if(check == left(str[i])){
      flag = false;
      break;
    }
    check = left(str[i]);
  }

  if(flag)
    cout << "yes";
  else
    cout << "no";
} 