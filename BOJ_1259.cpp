// https://www.acmicpc.net/problem/1259

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  while(1){
    
    int num;
    cin >> num;
    
    if(num == 0)
      break;

    int temp = num;
    int rev = 0;
    while(temp){
      rev = rev*10 + temp%10;
      temp /= 10;
    }
    if(rev == num)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}