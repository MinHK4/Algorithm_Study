// https://school.programmers.co.kr/learn/courses/30/lessons/92342

/*
화살에 가중치를 두게되면 화살의 개수가 제한적이기 때문에 몇몇 케이스를 통과하지 못합니다
때문에 그리디 방식을 이용하는 것이 아닌 전체를 탐색해야 합니다

하지만 문제가 되는 부분이 있습니다
작은 화살을 많이 맞춘 결과를 리턴 해줘야한다는 것이죠
결과가 나올때마다 적은 화살이 더많은지를 확인하면 비효율적입니다
때문에 적은 화살부터 맞추어 결과를 갱신하는 방법을 사용하여 보다 효율적으로 풀이해 주시면 되겠습니다
*/

function solution(n, info) {
  let winScore = 0;
  let answer = [-1];

  // 점수차 계산
  function calcScore(lion) {
    return info.reduce((acc, val, idx) => {
      if (val === 0 && lion[idx] === 0) return acc;
      if (val < lion[idx]) return acc + 10 - idx;
      return acc - 10 + idx;
    }, 0);
  }

  function dfs(left, idx, lion) {
    // 남은 화살이 없으면 점수 계산해서 업데이트
    if (left === 0) {
      const score = calcScore(lion);
      if (winScore < score) {
        winScore = score;
        answer = lion;
      }
      return;
    }

    // 작은 점수 화살부터 쏘기
    for (let i = idx; i >= 0; i--) {
      const copy = [...lion];

      if (left > info[i]) {
        copy[i] = info[i] + 1;
        dfs(left - copy[i], i - 1, copy);
      } else {
        copy[10] += left;
        dfs(0, i - 1, copy);
      }
    }

    // 남은 화살은 모두 작은 화살에 쏘기
    const copy = [...lion];
    copy[10] += left;
    dfs(0, -1, copy);
  }

  dfs(n, 10, Array(11).fill(0));

  return answer;
}
