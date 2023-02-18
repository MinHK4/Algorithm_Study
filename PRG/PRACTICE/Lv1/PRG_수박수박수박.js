// https://school.programmers.co.kr/learn/courses/30/lessons/12922

function solution(n) {
  return Array(n)
    .fill()
    .map((_, idx) => (idx % 2 ? '박' : '수'))
    .join('');
}
