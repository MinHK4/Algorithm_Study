// https://www.acmicpc.net/problem/11170

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int T;
  cin >> T;
  while(T--){
    int N, M;
    cin >> N >> M;
    
    int ans = 0;
    for(int i=N; i<=M; i++){
      if(i==0)
        ans++;
      else{
        int temp = i;
        while(temp){
          if(temp % 10 == 0)
            ans++;
          temp /= 10;
        }
      }
    }
    cout << ans  << '\n';
  }
}

/*
Brute Force로 그냥 다 처리해서 확인해주기
*/