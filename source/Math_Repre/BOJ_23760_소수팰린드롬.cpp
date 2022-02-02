// https://www.acmicpc.net/problem/1747

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

#define MAX_SIZE 4000001

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  // 선행처리 - 에라토스테네스의 체
  vector<bool> prime(MAX_SIZE, true);
  prime[1] = false;
  for(int i=2; i*i<=MAX_SIZE; i++){
    if(prime[i]){
      for(int j=i+i; j<=MAX_SIZE; j+=i)
        prime[j] = false;
    }
  }

  int N;
  cin >> N;
  for(int i=N; i<=MAX_SIZE; i++){
    // 소수인 경우 팰린드롬인지 확인
    if(prime[i]){
      string temp1 = to_string(i);
      string temp2 = to_string(i);
      reverse(temp2.begin(), temp2.end());

      if(temp1 == temp2){
        cout << i;
        return 0;
      }
    }
  }
}

/*
에라토스테네스의 체 이용해서 소수 판정 선처리해주기
문제 제시에 맞게 소수 판정 범위 잘 정하고 1 소수 제외 신경써주기
*/