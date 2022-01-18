#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector <int> arr;
int N, K;

bool solve(int key){
  int cnt = 1;
  int cur = 0;
  for(int i=1; i<N; i++){
    if(arr[i]-arr[cur] >= key){
      cnt++;
      cur = i;
    }
  }
  if(cnt >= K)
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  cin >> N >> K;
  arr.resize(N);

  for(int i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  int s = 1;
  int e = arr[N-1] - arr[0];
  int ans;
  while(s<=e){
    int mid = (s+e) / 2;
    if(solve(mid)){
      ans = mid; 
      s = mid+1;
    }
    else
      e = mid -1;
  }
  cout << ans;
}  