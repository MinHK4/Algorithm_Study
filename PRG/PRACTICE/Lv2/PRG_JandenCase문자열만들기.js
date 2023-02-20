// https://school.programmers.co.kr/learn/courses/30/lessons/12951

function solution(s) {
  return s
    .split(' ')
    .map(
      (word) => word.substr(0, 1).toUpperCase() + word.substr(1).toLowerCase()
    )
    .join(' ');
}
