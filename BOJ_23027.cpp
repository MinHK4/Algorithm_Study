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

  int cnt_A = 0; 
  int cnt_B = 0; 
  int cnt_C = 0;

  for(int i=0; i<len; i++){
    if(str[i]=='A')
      cnt_A++;
    if(str[i]=='B')
      cnt_B++;
    if(str[i]=='C')
      cnt_C++;
  }

  if(cnt_A > 0){
    for(int i=0; i<len; i++){
      if(str[i] == 'B' || str[i] == 'C' || str[i] == 'D' || str[i] == 'F')
        str[i] = 'A';
    }
  }
  else if(cnt_B > 0){
    for(int i=0; i<len; i++){
      if(str[i] == 'C' || str[i] == 'D' || str[i] == 'F')
        str[i] = 'B';
    }
  }
  else if(cnt_C > 0){
    for(int i=0; i<len; i++){
      if(str[i] == 'D' || str[i] == 'F')
        str[i] = 'C';
    }
  }
  else{
    for(int i=0; i<len; i++){
      str[i] = 'A';
    }
  }

  cout << str;
}