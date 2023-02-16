function solution(s, skip, index) {
  var answer = '';

  const skipList = Array(26).fill(false);

  [...skip].forEach((s) => (skipList[s.charCodeAt(0) - 97] = true));

  [...s].forEach((c) => {
    let cur = c.charCodeAt(0) - 97;
    let cnt = index;
    while (cnt) {
      cur = (cur + 1) % 26;
      if (!skipList[cur]) cnt--;
    }
    answer += String.fromCharCode(97 + cur);
  });

  return answer;
}
