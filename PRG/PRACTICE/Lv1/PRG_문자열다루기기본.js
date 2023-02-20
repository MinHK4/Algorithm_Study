// https://school.programmers.co.kr/learn/courses/30/lessons/12918

function solution(s) {
  if (s.length != 4 && s.length != 6) return false;
  return s.split('').every((val) => Number(val) >= 0);
}

// 정규표현식 적용
function alpha_string46(s) {
  var regex = /^\d{6}$|^\d{4}$/;

  return regex.test(s);
}
