#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int n, s, k;
  cin >> n >> s >> k;

  vector<int> info(n);
  while(k--){
    int temp;
    cin >> temp;

    int cnt = 0;
    while(temp>s){
      temp -= s;
      cnt++;
    }
    
    if(0<=cnt && cnt<n)
      info[cnt]++;
  }

  int max_cnt = *max_element(info.begin(),info.end());
  vector<vector<char>> H(max_cnt+1, vector<char>(n, '.'));
  for(int i=0; i<n; i++)
    H[max_cnt][i] = '-';
  
  // info 참조
  for(int i=0; i<n; i++){
    for(int j=1; j<=info[i]; j++)
      H[max_cnt-j][i] = '#';
  }

  for(int i=0; i<max_cnt+1; i++){
    for(int j=0; j<n; j++)
      cout << H[i][j];
    cout << '\n';
  }
}