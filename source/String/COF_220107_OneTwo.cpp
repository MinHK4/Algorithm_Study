#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair <ll, ll>;
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  freopen("inp.txt", "r", stdin);
  
  int t;
  cin >> t;
  while(t--){
    string str;
    cin >> str; 
 
    vector<int> ans;
    int cnt = 0;
    int len = str.length();
    for(int i=0; i<=len-3;){
      if(i<=len-5 && str.substr(i,5) == "twone"){
        cnt++;
        ans.push_back(i+3);
        i+=5;
      }
      else if(str.substr(i,3) == "two"){
        cnt++;
        ans.push_back(i+2);
        i+=3;
      }
      else if(str.substr(i, 3) == "one"){
        cnt++;
        ans.push_back(i+2);
        i+=3;
      }
      else
        i++;
    }
    cout << cnt << '\n';
 
    if(cnt == 0)
      cout << '\n';
 
    else{
      for(int x : ans)
        cout << x << ' ';
      cout << '\n';
    }
  }
}