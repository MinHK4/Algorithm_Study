// https://school.programmers.co.kr/learn/courses/30/lessons/12912

function solution(a, b) {
  const small = Math.min(a, b);
  const big = Math.max(a, b);

  let sum = 0;
  for (let i = small; i <= big; i++) sum += i;

  return sum;
}
