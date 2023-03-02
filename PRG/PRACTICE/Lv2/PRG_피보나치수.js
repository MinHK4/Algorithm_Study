// https://school.programmers.co.kr/learn/courses/30/lessons/12945

function solution(n) {
  const MOD = 1234567;

  const arr = Array(n + 1).fill(0);
  arr[1] = 1;
  for (let i = 2; i <= n; i++)
    arr[i] = ((arr[i - 2] % MOD) + (arr[i - 1] % MOD)) % MOD;

  return arr[n];
}
