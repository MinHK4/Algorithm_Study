#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<vector<int>> v(N+1);

  for(int i=1; i<=N; i++){
    int temp = i;
    while(temp<=N && v[temp].size()==0){
      int temp_i = temp; 
      int temp_sum = temp_i;
      while(temp_i){
        temp_sum += temp_i % 10;
        temp_i /= 10;
      }
      if(temp_sum <= N)
        v[temp_sum].push_back(temp);
      temp = temp_sum;
    }
  }
  cout << v[N].size();
}