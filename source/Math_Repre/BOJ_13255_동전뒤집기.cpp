#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int N, K;
  cin >> N >> K;
  
  double pr = N;
  while(K--){
    int a;
    cin >> a;
    double temp = 0.0;
    temp += pr * (1 - (double)a / N);
    temp += (N-pr) * ((double) a / N);
    pr = temp;
  }

  cout.fixed;
  cout.precision(11);
  cout << pr;
}

/*
기댓값의 선형성
: 제비뽑기에서 먼저 뽑든지 나중에 뽑든지가 확률적으로는 영향을 안 미치듯이
전체 N개에서 a개를 랜덤하게 수행한다고 했을 때
각각의 개체가 수행될 확률은 모두 a/N으로 동일함

-> 따라서 한 과정을 거칠때마다 이전 단계에서 가지고 있던 기댓값을 바탕으로
(앞면 기댓값 * 안 뒤집을 확률) + (뒷면 기댓값 * 뒤집을 확률)
이런 방식으로 업데이트해나가면 된다.
*/