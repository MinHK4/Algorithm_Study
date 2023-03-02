// https://school.programmers.co.kr/learn/courses/30/lessons/12930

function solution(s) {
  return s
    .split(' ')
    .map((word) =>
      word
        .split('')
        .map((val, idx) => (idx % 2 ? val.toLowerCase() : val.toUpperCase()))
        .join('')
    )
    .join(' ');
}
