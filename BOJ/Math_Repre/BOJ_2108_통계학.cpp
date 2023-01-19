//https://www.acmicpc.net/problem/2108

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int num;
  cin >> num;

  vector <int> count(8001, 0);
  vector <int> arr(num);
  int sum = 0;
  
  for(int i=0; i<num; i++){
    cin >> arr[i];
    sum += arr[i];
    count[arr[i]+4000]++;
  }
  sort(arr.begin(), arr.end());
  int max = -1;
  int idx = -1;
  for(int i=0; i<8001; i++){
    if(count[i] > max){
      max = count[i];
      idx = i;
    }
  }
  for(int i=idx+1; i<8001; i++){
    if(count[i] == max){
      idx = i;
      break;
    }
  }

  int ans1 = round((double)sum / num);
  int ans2 = arr[num/2];
  int ans3 = idx - 4000;
  int ans4 = arr[num-1] - arr[0]; 

  cout << ans1 << '\n';
  cout << ans2 << '\n';
  cout << ans3 << '\n';
  cout << ans4 << '\n';
}

/*
간단한 수학 구현
floating point 크게 고려하지 않고 형 변환 처리만 잘 해놓고
최빈값 겹치는 거일 때 두 번째 구하는 것만 좀 신경써서 처리
*/