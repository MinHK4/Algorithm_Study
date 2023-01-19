// https://www.acmicpc.net/problem/7983

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool sortby(pii a, pii b){
  if(a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  
  vector<pii> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i].first >> arr[i].second;
  sort(arr.begin(), arr.end(), sortby);
  
  int date = arr[N-1].second;
  for(int i=N-1; i>=0; i--){
    date = min(date, arr[i].second);
    date -= arr[i].first;
  }
  cout << date;
}

/*
그리디 접근법
최대한 쉴 수 있는 공간을 확보하려면 마지막 마감일부터 내려오면서 체크
해당 마감일 과제의 소요시간을 차감해서 얻은 일이 다음 마감일보다 작으면
딱 맞춰서 시작하지 못 하고 일찍 시작해야 하고
다음 마감일보다 크면 중간에 한번 더 쉬는 시간이 있는 개념
*/ 