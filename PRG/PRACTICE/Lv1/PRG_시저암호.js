// https://school.programmers.co.kr/learn/courses/30/lessons/12926?language=javascript

function solution(s, n) {
  return s
    .split('')
    .map((c) => {
      if (c === ' ') return c;

      let num = c.charCodeAt(0);

      // 대문자 경우 처리
      if ('A'.charCodeAt(0) <= num && num <= 'Z'.charCodeAt(0)) {
        num -= 'A'.charCodeAt(0);
        num = (num + n) % 26;
        num += 'A'.charCodeAt(0);
        return String.fromCharCode(num);
      }

      // 소문자 경우 처리
      num -= 'a'.charCodeAt(0);
      num = (num + n) % 26;
      num += 'a'.charCodeAt(0);
      return String.fromCharCode(num);
    })
    .join('');
}
