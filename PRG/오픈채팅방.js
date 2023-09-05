// https://school.programmers.co.kr/learn/courses/30/lessons/42888
// 18 min

function solution(record) {
  const nickNameMap = new Map();
  record.forEach((r) => {
    const [act, uid, nickname] = r.split(' ');
    if (act === 'Enter') {
      nickNameMap.set(uid, nickname);
    }
    if (act === 'Change') {
      nickNameMap.set(uid, nickname);
    }
  });

  const ans = [];
  record.forEach((r) => {
    const [act, uid, nickname] = r.split(' ');
    if (act === 'Enter') {
      ans.push(nickNameMap.get(uid) + '님이 들어왔습니다.');
    }
    if (act === 'Leave') {
      ans.push(nickNameMap.get(uid) + '님이 나갔습니다.');
    }
  });
  return ans;
}
