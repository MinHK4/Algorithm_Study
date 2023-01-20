// https://school.programmers.co.kr/learn/courses/30/lessons/12947

function solution(x) {
  const sum = x
    .toString()
    .split('')
    .map((val) => val / 1)
    .reduce((a, b) => a + b);

  return x % sum === 0;
}
