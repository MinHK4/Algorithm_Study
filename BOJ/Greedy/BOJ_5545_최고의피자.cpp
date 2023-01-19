// https://www.acmicpc.net/problem/5545

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  int A, B;
  cin >> A >> B;

  int C;
  cin >> C;

  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end(), greater<>());

  int cal_sum = C;
  int price_sum = A;
  int max_cal = cal_sum / price_sum;

  for(int i=0; i<N; i++){
    cal_sum += arr[i];
    price_sum += B;
    if((cal_sum / price_sum) < max_cal)
      break;
    else
      max_cal = cal_sum / price_sum;
  }
  cout << max_cal;
}

/*
약간 그리디 개념도 추가됨
최고의 피자를 만들기 위해서는 토핑을 추가할지 말지인데
토핑의 가격은 다 동일하므로 열랑이 높은 토핑을 우선적으로 추가하면서
원당 열량이 작아지는 경우에 break
*/