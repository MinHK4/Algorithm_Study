// https://school.programmers.co.kr/learn/courses/30/lessons/12954

function solution(x, n) {
  return Array(n)
    .fill()
    .map((_, idx) => (idx + 1) * x);
}
