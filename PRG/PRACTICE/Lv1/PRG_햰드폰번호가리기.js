// https://school.programmers.co.kr/learn/courses/30/lessons/12948

function solution(phone_number) {
  return [...phone_number]
    .map((val, idx) => (phone_number.length - idx <= 4 ? val : '*'))
    .join('');
}

// 정규표현식 풀이
function hide_numbers(s) {
  return s.replace(/\d(?=\d{4})/g, '*');
}

// repeat + slice
function hide_numbers(s) {
  return '*'.repeat(s.length - 4) + s.slice(-4);
}
