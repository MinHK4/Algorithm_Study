// https://school.programmers.co.kr/learn/courses/30/lessons/12903

function solution(s) {
  return s.length % 2
    ? [...s].splice(Math.floor(s.length / 2), 1).join('')
    : [...s].splice(s.length / 2 - 1, 2).join('');
}

// substr 활용, ceil한거에서 - 1 한 값이 홀짝 상관없이 중간 인덱스임
function solution(s) {
  return s.substr(Math.ceil(s.length / 2) - 1, s.length % 2 === 0 ? 2 : 1);
}
