// https://www.acmicpc.net/problem/2179

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  int max_comm = -1;
  string str1;
  string str2;
  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      // 문자열 하나씩 잡아서 그 중 더 작은 길이까지 비교 
      for(int k=0; k < min(arr[i].length(), arr[j].length()); k++){
        // 문자열의 문자가 다르면 버리고
        if(arr[i][k]!=arr[j][k])
          break;
        // 같은 경우에 지금까지 나온 접두사 길이보다 크면 정보 업데이트
        // 큰 경우에만 업데이트하게 해놨고 앞부터 인덱싱해서 우선순위도 고려됨
        else{
          if(max_comm < k){
            max_comm = k;
            str1 = arr[i];
            str2 = arr[j];
          }
        }
      }
    }
  }
  cout << str1 << '\n' << str2;
}

/*
Bruteforce하게 접근
최대로 접두사를 공유하는 문자를 찾고 그 다음에 실제로 나온 순서 바탕으로 우선권 주기 때문에
하나씩 다 비교해가면서 현재까지의 최대 접두사보다 길게 나오면 업데이트 하는 방식으로 구현
*/