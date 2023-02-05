// https://school.programmers.co.kr/learn/courses/30/lessons/150368

let answer = [];

function solution(users, emoticons) {
  dfs(users, emoticons, []);

  return answer;
}

const dfs = (users, emoticons, saleList) => {
  // 모든 이모티콘의 할인율이 지정된 경우
  if (saleList.length === emoticons.length) {
    const percent = [10, 20, 30, 40];

    let plusUserCount = 0;
    let totalSum = 0;
    users.forEach((user) => {
      let sum = 0;
      saleList.forEach((sale, idx) => {
        if (percent[sale] >= user[0]) {
          sum += ((100 - percent[sale]) / 100) * emoticons[idx];
        }
      });

      if (sum >= user[1]) plusUserCount++;
      else totalSum += sum;
    });

    // 값 갱신하기
    if (
      answer.length === 0 ||
      answer[0] < plusUserCount ||
      (answer[0] === plusUserCount && answer[1] < totalSum)
    )
      answer = [plusUserCount, totalSum];
    return;
  }

  // 완전 탐색 돌리기
  for (let i = 0; i < 4; i++) dfs(users, emoticons, [...saleList, i]);
};
