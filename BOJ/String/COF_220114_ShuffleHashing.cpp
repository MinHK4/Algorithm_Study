#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair <int, int>;
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  //freopen("inp.txt", "r", stdin);
 
  int T;
  cin >> T;
  while(T--){
    string org;
    cin >> org;
    sort(org.begin(), org.end());
 
    string hash;
    cin >> hash;
 
    int org_len = org.length();
    int hash_len = hash.length();
    bool flag = false;
    for(int i=0; i+org_len-1 < hash_len; i++){
      string temp = hash.substr(i, org_len);
      sort(temp.begin(), temp.end());
      if(org == temp){
        flag = true;
        break;
      }
    }
    
    if(flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}