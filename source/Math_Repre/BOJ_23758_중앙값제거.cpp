#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  
  int ans = 0;
  for(int i=0; i<(N+1)/2; i++){
    while(arr[i]!=1){
      ans++;
      arr[i] /= 2;
    }
  }
  cout << ans + 1;
}  