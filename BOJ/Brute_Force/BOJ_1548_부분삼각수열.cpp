// https://www.acmicpc.net/problem/1548

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  int ans = 1;

  // 구간 설정
  for(int i=0; i<N; i++){
    for(int j=N-1; j>i; j--){

      // x와z 설정했으니 y들로 조건 충족여부 확인
      bool flag = true;
      for(int k=i+1; k<j; k++){
        if(arr[i]+arr[k]<=arr[j]){
          flag = false;
          break;
        }
      }

      // 조건 충족한 경우에 대해서 최대 길이 업데이트
      if(flag){
        ans = max(ans, j-i+1);
        // cout << i << ' ' << j << '\n';
      }
    }
  }

  cout << ans;
}

/*
삼각수열의 조건 충족을 고려할 때 배열이 정렬되어있으면 x+y>z의 조건만 충족하면 됨
그래서 작은 수부터 자기를 제외한 수 두 개의 쌍과 조건 확인해가면서 뺄 개수 업데이트

-틀렸습니다!

1 5 6 7 8 9 100와 같은 예시처럼
한쪽에서 빼지는 것이 아니라 양쪽에서 빠져야 하는 경우들을 고려해줄 수 있어야 함
x와 z의 값이 충족시키게 만들어주는지 여부를 고려는 해주되
양쪽이 번갈아가면서 빠지는 경우를 케어할 수 있게!!

--> 
N의 크기가 작기 때문에 구간들 자체를 다 잡아서 BruteForce하게 확인해주면 됨
그리고 정렬을 해놓고 양쪽 끝만 확인을 해주면 된다는 점에서 그리디하게 확인하는 것도 좀 섞인 느낌 
*/