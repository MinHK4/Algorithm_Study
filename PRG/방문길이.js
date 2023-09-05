// https://school.programmers.co.kr/learn/courses/30/lessons/49994
// 15 min

function solution(dirs) {
  const dir = ['U', 'D', 'R', 'L'];
  const dx = [1, -1, 0, 0];
  const dy = [0, 0, 1, -1];

  const root = new Set();
  let curX = 5;
  let curY = 5;
  dirs.split('').forEach((d) => {
    const nextX = curX + dx[dir.indexOf(d)];
    const nextY = curY + dy[dir.indexOf(d)];

    if (!isValidPos(nextX, nextY)) return;

    root.add(`${curX},${curY},${nextX},${nextY}`);
    root.add(`${nextX},${nextY},${curX},${curY}`);
    curX = nextX;
    curY = nextY;
  });

  return root.size / 2;

  function isValidPos(x, y) {
    return 0 <= x && x <= 10 && 0 <= y && y <= 10;
  }
}
