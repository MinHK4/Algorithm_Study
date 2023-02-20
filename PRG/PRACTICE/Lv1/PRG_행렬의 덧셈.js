// https://school.programmers.co.kr/learn/courses/30/lessons/12950

function solution(arr1, arr2) {
  return arr1.map((ar1, i) => ar1.map((a1, j) => a1 + arr2[i][j]));
}
