// https://www.acmicpc.net/problem/1759

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<char> arr;
string ans = "";
int L, C;

void backtrack(int idx, int size){
  
  // end case
  if(size == L){
    
    // 자음, 모음 수 확인하기
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<size; i++){
      if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' ||
        ans[i] == 'o' || ans[i] == 'u')
        cnt1++;
      else 
        cnt2++;
    }

    if(cnt1 >= 1 && cnt2 >=2)
      cout << ans << '\n';
    return;
  }

  // 알파벳 사전 순으로 하나씩 추가해넣기
  for(int i=idx; i<C; i++){
    ans += arr[i];
    backtrack(i+1, size+1);
    ans.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> L >> C;
  for(int i=0; i<C; i++){
    char c;
    cin >> c;
    arr.push_back(c);
  }
  sort(arr.begin(), arr.end());
  
  backtrack(0, 0);
}

/*
문자 정렬해서 하나씩 넣어가면서 암호 만드록
최종적으로 암호 길이는 맞췄을 때 자음, 모음 수 확인해서 
가능한 암호만 정답으로 출력하기
*/