// https://school.programmers.co.kr/learn/courses/30/lessons/68935

function solution(n) {
  return n
    .toString(3)
    .split('')
    .reverse()
    .reduce((acc, val) => acc * 3 + Number(val), 0);
  return parseInt(n.toString(3).split('').reverse().join(''), 3);
}
