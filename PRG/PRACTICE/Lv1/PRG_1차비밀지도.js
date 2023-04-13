// https://school.programmers.co.kr/learn/courses/30/lessons/17681

function solution(n, arr1, arr2) {
  const temp1 = arr1.map((val) => toBinStrLen(n, val));
  const temp2 = arr2.map((val) => toBinStrLen(n, val));

  return temp1.map((val, idx) => {
    return val
      .split('')
      .map((c, i) => (c === '0' && temp2[idx][i] === '0' ? ' ' : '#'))
      .join('');
  });

  function toBinStrLen(len, num) {
    const str = num.toString(2);

    return '0'.repeat(len - str.length) + str;
  }
}

// padStart 사용한 풀이
var solution = (n, a, b) =>
  a.map((a, i) =>
    (a | b[i]).toString(2).padStart(n, 0).replace(/0/g, ' ').replace(/1/g, '#')
  );
