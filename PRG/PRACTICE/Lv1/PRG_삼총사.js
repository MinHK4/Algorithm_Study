// https://school.programmers.co.kr/learn/courses/30/lessons/131705

function solution(number) {
  let answer = [];

  dfs([]);

  return answer.length;

  function dfs(arr) {
    if (arr.length === 3) {
      const sum = arr.reduce((acc, val) => acc + number[val], 0);
      const str = JSON.stringify(arr.sort());

      if (sum == 0 && !answer.includes(str)) {
        answer.push(str);
      }
      return;
    }

    for (let i = 0; i < number.length; i++) {
      if (arr.includes(i)) continue;
      dfs([...arr, i]);
    }
  }
}

// 재귀함수로 조합 돌리는 풀이
function solution(number) {
  let result = 0;

  const combination = (current, start) => {
    if (current.length === 3) {
      result += current.reduce((acc, cur) => acc + cur, 0) === 0 ? 1 : 0;
      return;
    }

    for (let i = start; i < number.length; i++) {
      combination([...current, number[i]], i + 1);
    }
  };
  combination([], 0);
  return result;
}
