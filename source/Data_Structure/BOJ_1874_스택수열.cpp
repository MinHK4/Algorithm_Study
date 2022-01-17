#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int N;
  cin >> N;

  vector <int> model;
  for(int i=0; i<N; i++){
    int temp;
    cin >> temp;
    model.push_back(temp);
  }

  stack <int> arr;
  string ans = "";
  int idx = 0;
  for(int i=1; i<=N; i++){
    arr.push(i);
    ans += '+';
    while(!arr.empty() && arr.top() == model[idx]){
      arr.pop();
      ans += '-';
      idx++;
    }
  }

  if(!arr.empty())
   cout << "NO";
  else{
    for(int i=0; i<ans.length(); i++)
      cout << ans[i] << '\n';
  }
}