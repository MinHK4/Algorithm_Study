// https://school.programmers.co.kr/learn/courses/30/lessons/150369

function solution(cap, n, deliveries, pickups) {
  var answer = 0;

  let go = 0;
  let back = 0;

  for (let i = n - 1; i >= 0; i--) {
    go += deliveries[i];
    back += pickups[i];

    while (go > 0 || back > 0) {
      go -= cap;
      back -= cap;
      answer += (i + 1) * 2;
    }
  }

  return answer;
}
