// https://www.acmicpc.net/problem/9177

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

string str1, str2, str3;
int len1, len2, len3;
bool flag;

void DFS(int i, int j, int k){
  // end case
  // 원하고자 하는 길이까지 다 찾은 경우 
  // 답을 찾았다는 전역 flag를 set해주기
  if(k >= len3){
    flag = true;
    return;
  }

  // 아직 답이 나오지 않았고 str1쪽으로 탐색 가능
  if(!flag && i<len1 && str3[k] == str1[i])
    DFS(i+1, j, k+1);

  // 아직 답이 나오지 않았고 str2쪽으로 탐색 가능
  if(!flag && j<len2 && str3[k] == str2[j])
    DFS(i, j+1, k+1);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int TC;
  cin >> TC;
  for(int i=1; i<=TC; i++){
    cin >> str1 >> str2 >> str3;

    len1= str1.length();
    len2= str2.length();
    len3= str3.length();
    
    flag = false;

    // 구성 자체가 합해서 나오지 않는 경우가 있을 수 있으므로 확인해주기
    // 일단 문자들의 구성 자체가 같은 경우에 DFS 탐색 해주기
    string temp1 = str1 + str2;
    string temp2 = str3;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    if(temp1 == temp2)
      DFS(0, 0, 0);

    if(flag)
      cout << "Data set " << i << ": yes\n";
    else 
      cout << "Data set " << i << ": no\n"; 
  }
}

/*
독특한 Backtracking 문제라고 생각함
Backtracking의 경우 DFS를 돌리면서 답이 안 되는 경우를 가지치기를 하는 개념인데
여기서는 답을 찾았을 경우를 set해주고 그걸로 가지치기를 처리하는 느낌
따라서 처음 시간초과가 떳을 때 당연히 가지치기를 제대로 처리하지 못 했을 거라고 생각하게 되는데
사실 시간초과는 그냥 아예 불가능한 문자열 조합의 경우를 선처리 해줘야 함
*/