// https://www.acmicpc.net/problem/10090

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <ll> arr, temp;

// merge_sort 병합하는 역할 진행
void merge(ll left, ll right) {
  ll mid = (left + right) / 2;
  ll i = left;
  ll j = mid + 1;
  ll k = left;

  // 양쪽에서 큰 애들부터 차례로 채워넣어주기
  while (i <= mid && j <= right) {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];

  for (ll l = left; l <= right; l++)
    arr[l] = temp[l];
}

// 재귀적으로 분할해서 카운트할 뿐 아니라 merge_sort의 분할 역할도 진행
ll inv_count(ll left, ll right) {
  
  // 원소의 개수가 하나인 경우 inversion 0개 찾은걸로 return
  if (left == right)
      return 0;

  // 현재의 구간에서 얻어지는 inversion 개수 구해주기
  ll count = 0;

  // 반으로 분할해서 각각의 영역 재귀로 탐색하기
  ll mid = (left + right) / 2;
  count += inv_count(left, mid);
  count += inv_count(mid + 1, right);

  // 앞쪽과 뒤쪽 사이에서 발생하는 inversion 세줘서 현재 구간의 개수 업데이트
  // 각각 가장 앞에 있는 원소부터 시작해서 앞의 원소가 뒤의 원소보다 크면 inversion 발생
  // 위 경우시 뒤쪽 인덱스를 미는 방식이므로 이후에 또 inversion이 발생하면
  // 앞쪽 인덱스의 앞까지 다 inversion임을 알 수 있음
  ll i = left;
  ll j = mid + 1;
  while (i <= mid && j <= right) {
    if (arr[i] > arr[j]) {
      count += (mid + 1 - i);
      j++;
    }
    else
      i++;
  }

  //sorting in ascending order
  merge(left, right);

  return count;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll num;
    
    cin >> num;
    arr.resize(num);
    temp.resize(num);
    for (ll i = 0; i < num; i++)
        cin >> arr[i];

    cout << inv_count(0, num - 1);
}

/*
분할정복 풀이

기본적인 접근자체는 반으로 나누고 그 반 안에서 찾은 inversion들과
각각의 반 사이에서 발생하는 inversion들을 모두 합쳐서 세어주는 개념으로 접근

이런 접근이 가능하기 위해서는 각각의 영역이 정렬됨이 전제되어야 함
따라서 merge_sort를 진행하는 과정에서 count 해주는 방식으로 풀이
*/