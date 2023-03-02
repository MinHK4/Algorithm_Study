// https://school.programmers.co.kr/learn/courses/30/lessons/70129?language=javascript

function solution(s) {
  let cnt = 0,
    zeros = 0;
  let str = s;
  while (str != '1' && cnt < 10) {
    const temp = str
      .split('')
      .filter((val) => {
        if (val === '1') return true;
        zeros++;
        return false;
      })
      .join('');
    str = numToBinStr(temp.length);
    cnt++;
  }

  return [cnt, zeros];

  function numToBinStr(num) {
    let str = '';
    while (num) {
      str += num % 2 ? '1' : '0';
      num = Math.floor(num / 2);
    }
    return str.split('').reverse().join('');
  }
}

// 정규표현식 활용 및 toString(2) 활용한 풀이
function solution(s) {
  var answer = [0, 0];
  while (s.length > 1) {
    answer[0]++;
    answer[1] += (s.match(/0/g) || []).length;
    s = s.replace(/0/g, '').length.toString(2);
  }
  return answer;
}
