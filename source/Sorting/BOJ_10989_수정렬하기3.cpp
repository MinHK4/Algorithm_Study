#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int num;
  cin >> num;

  vector <int> arr(10001, 0);
  while(num--){
    int temp;
    cin >> temp;
    arr[temp]++;
  }

  for(int i=1; i<=10000; i++){
    while(arr[i]){
      cout << i << '\n';
      arr[i]--;
    }
  }
}  