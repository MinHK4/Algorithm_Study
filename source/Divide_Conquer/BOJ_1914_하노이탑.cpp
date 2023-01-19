// https://www.acmicpc.net/problem/1914

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int getTempStop(int src, int dst){
  int res;
  for(int i=1; i<=3; i++){
    if(i != src && i != dst)
      res = i;
  }
  return res;
}

void hannoi(int cur, int src, int dst){
  if(cur == 0) return;

  int temp_stop = getTempStop(src, dst); 
  
  hannoi(cur-1, src, temp_stop);
  cout << src << ' ' << dst << '\n';
  hannoi(cur-1, temp_stop, dst);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  // 하노이 탑 N개를 옮기는데 필요한 횟수는 2^N -1
	string a = to_string(pow(2, N));
	int x = a.find('.');    // pow 함수 결과가 실수형이기에 소수점 찾기
	a = a.substr(0, x);		  // 소수점 앞자리만 나오게하기
	a[a.length() - 1] -= 1;	// string a에 대한 마지막 위치의 인덱스 값에 -1

	cout << a << endl;

  if(N <= 20){
    hannoi(N, 1, 3);
  }
}