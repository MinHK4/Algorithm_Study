// https://school.programmers.co.kr/learn/courses/30/lessons/17684
// 30 min

function solution(msg) {
  const indexMap = new Map();
  for (i = 1; i <= 26; i++) {
    indexMap.set(String.fromCharCode(64 + i), i);
  }

  const ans = [];
  let index = 27;
  for (let i = 0; i < msg.length; ) {
    let len = 1;
    while (i + len + 1 <= msg.length && indexMap.has(msg.substr(i, len + 1))) {
      len++;
    }

    const curWord = msg.substr(i, len);
    const nextWord = msg.substr(i, len + 1);

    ans.push(indexMap.get(curWord));
    indexMap.set(nextWord, index++);
    i += len;
  }

  return ans;
}
