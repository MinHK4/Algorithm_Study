// https://www.acmicpc.net/problem/5800

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int K;
  cin >> K;

  for(int k=1; k<=K; k++){
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for(int i=0; i<N; i++)
      cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<>());

    int max_diff = -1;
    for(int i=0; i<N-1; i++)
      max_diff = max(max_diff, arr[i]-arr[i+1]);
    
    cout << "Class " << k << '\n';
    cout << "Max " << arr[0] << ", Min " << arr[N-1] <<  ", Largest gap " << max_diff << '\n';
  }
}

/*
Sorting기반의 문제
Input 크기가 크지 않아서 그냥 bruteforce하게 돌리면 되는데
숫자 크기가 큰 경우 고려하면 어려울 듯
*/ 