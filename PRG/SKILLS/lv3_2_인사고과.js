// https://school.programmers.co.kr/learn/courses/30/lessons/152995

function solution(scores) {
  // 완호 점수 따로 보존
  const target = scores[0];

  // 정렬이 핵심!!
  // 근무 태도 점수는 내림차순으로 해서 신경 안 쓰도록
  // 동료 평가 점수는 오름차순으로 해서 이전까지의 최대값을 기준으로 작으면 석차에서 제외
  scores.sort((a, b) => {
    if (a[0] === b[0]) return a[1] - b[1];
    return b[0] - a[0];
  });

  let cnt = 1;
  let maxB = -1;
  for (const score of scores) {
    // 완호가 인센티브 못 받는 경우 예외처리
    if (target[0] < score[0] && target[1] < score[1]) return -1;

    // 완호의 점수 합보다 같거나 낮은 경우 cnt에 포함 X
    if (score[0] + score[1] <= target[0] + target[1]) continue;

    // 석차에 반영되는지 여부 체크
    if (score[1] >= maxB) {
      maxB = score[1];
      cnt++;
    }
  }

  return cnt;
}
