// https://www.acmicpc.net/problem/23364

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<pii> arr(N);
  for(int i=0; i<N; i++){
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr.begin(), arr.end());

  for(int i=0; i<N; i++){
    for(int j=i+1; j<N && arr[j].first < arr[i].first*4000; j++){
      if(arr[j].first % arr[i].first == 0){
        cout << arr[i].second+1 << ' ' << arr[j].second+1;
        return 0;
      }
    }
  }
}

/*
무작위 랜덤 정수를 추출할 때의 나눠지는 수의 쌍 배출 확률은 매우 낮기 때문에
상식적인 수준에서 접근해서 정렬하고 작은 수부터 어느 정도 값 까지만 확인해주기
*/ 