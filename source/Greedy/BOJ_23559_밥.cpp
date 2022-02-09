// https://www.acmicpc.net/problem/23559

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

// 5000원짜리로 업그레드 할 때 가장 큰 효용을 얻을 수 있도록 정렬
bool cmp(pii a, pii b){
  return (a.first - a.second) > (b.first - b.second);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, X;
  cin >> N >> X;

  vector<pii> arr(N);
  int ans = 0;
  for(int i=0; i<N; i++){
    cin >> arr[i].first >> arr[i].second;

    // 우선은 1000원짜리 메뉴만 선택했다고 가정
    X -= 1000;
    ans += arr[i].second;
  }

  // 5000원짜리로 업데이트 할 때 발생 효용이 큰 순으로 정렬
  sort(arr.begin(), arr.end(), cmp);

  // 다 1000원 메뉴만 선택한 상황에서
  // 최대한 할 수 있는 만큼 5000원 메뉴로 효용 업그레이드 
  for(int i=0; i<N; i++){
    if(X>=4000 && arr[i].first > arr[i].second){
      X -= 4000;
      ans += arr[i].first - arr[i].second; 
    }
  }
  
  cout << ans;
}

/*
!! 매일 두 메뉴 중 하나를 선택하기는 해야한다 !!
!! 돈도 1000원짜리는 매일 사먹을 수 있는 금액이 최소금액으로 전제됨 !! 

우선은 다 1000원 선택하고
5000원 업그레이드 효용 기준으로 정렬해서
이후 가능한만큼 업그레이드 해주기
*/