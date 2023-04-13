// https://school.programmers.co.kr/learn/courses/30/lessons/12981

function solution(n, words) {
  const prev = [];
  let turn = 1,
    time = 1,
    flag = 1;

  for (let i = 0; i < words.length; i++) {
    if (words[i].length === 1) {
      flag = 0;
      break;
    }

    if (i > 0 && words[i - 1].split('').splice(-1)[0] !== words[i][0]) {
      flag = 0;
      break;
    }

    if (prev.includes(words[i])) {
      flag = 0;
      break;
    }

    prev.push(words[i]);
    turn++;
    if (turn === n + 1) {
      turn = 1;
      time++;
    }
  }

  return flag ? [0, 0] : [turn, time];
}

// reduce를 이용한 풀이
function solution(n, words) {
  let answer = 0;
  words.reduce((prev, now, idx) => {
    answer =
      answer ||
      (words.slice(0, idx).indexOf(now) !== -1 || prev !== now[0]
        ? idx
        : answer);
    return now[now.length - 1];
  }, '');

  return answer ? [(answer % n) + 1, Math.floor(answer / n) + 1] : [0, 0];
}
