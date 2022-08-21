#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  while(N--){
    int a, b, c;
    cin >> a >> b >> c;
  
    int cnt = 0;
    for(int x=1; x<=a; x++){
      for(int y=1; y<=b; y++){
        for(int z=1; z<=c; z++){
          if(x%y == y%z && y%z == z%x){
            cnt++;
          }
        }
      }
    }
    cout << cnt << '\n';
  }
}