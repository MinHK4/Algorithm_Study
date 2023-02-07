// https://school.programmers.co.kr/learn/courses/30/lessons/87946

function solution(k, dungeons) {
  let answer = -1;

  goToD(k, [], 0);

  function goToD(cur, visited, cnt) {
    for (let i = 0; i < dungeons.length; i++) {
      if (!visited.includes(i) && cur >= dungeons[i][0]) {
        answer = Math.max(answer, cnt + 1);
        goToD(cur - dungeons[i][1], [...visited, i], cnt + 1);
      }
    }
  }

  return answer;
}
