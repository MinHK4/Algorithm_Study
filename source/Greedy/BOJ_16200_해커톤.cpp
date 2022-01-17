#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

#define INF 40000

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  int team_cnt = 0;
  int people = 0;
  for(int i=0; i<N; i++){
    if(people == 0){
      people = arr[i]-1;
      team_cnt++;
    }
    else
      people--;
  }
  cout << team_cnt;
}