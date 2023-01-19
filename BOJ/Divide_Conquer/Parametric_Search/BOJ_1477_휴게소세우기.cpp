#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector <int> arr;
int N, M, L;

bool sol(int num) {
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        int diff = arr[i + 1] - arr[i];
        while (diff > num) {
            cnt++;
            diff -= num;
        }
        if (cnt > M)
            return false;
    }
    if (cnt > M)
        return false;
    else
        return true;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  cin >> N >> M >> L;
  arr.resize(N+2);
  for (int i = 0; i < N; i++)
      cin >> arr[i];
  arr[N] = 0;
  arr[N + 1] = L;
  sort(arr.begin(), arr.end());

  int s = 1;
  int e = L;
  int ans = 0;
  while (s <= e) {
      int mid = (s + e) / 2;
      if (sol(mid)) {
          e = mid - 1;
          ans = mid;
      }
      else
          s = mid + 1;
  }
  cout << ans;
}