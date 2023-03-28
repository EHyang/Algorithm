/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/1844
 * 
 * 역시 DFS로 접근했다가, 다시 BFS로 회귀
 * 
 * 전형적인 BFS 문제 방식.
 * 
 * 처음 이중 배열 visit을 만들때
 * 
 * ```javascript
 *  const visit = Array.from(maps).fill(Array.from(maps[0]).fill(0));
 * ```
 * 
 * 이와 같이 배열을 생성했다가 visit[0][1] 하나 바꿨을 뿐인데 한줄이 바뀌는 바람에 맞게 풀었다 생각했다가 오래걸린 문제
 * 
 * 구글 검색을 통해 신 문법하나 배워감
 * ES6
 * 
 * ```javascript
 *  const arr = Array.from(Array(5), () => Array(2).fill(null));
 *  const arr2 = Array.from(Array(5), () => new Array(2));
 * // 동일한 결과
 * ```
 * 
테스트 1 〉	통과 (0.22ms, 33.5MB)
테스트 2 〉	통과 (0.21ms, 33.4MB)
테스트 3 〉	통과 (0.23ms, 33.4MB)
테스트 4 〉	통과 (0.22ms, 33.4MB)
테스트 5 〉	통과 (0.23ms, 33.4MB)
테스트 6 〉	통과 (0.24ms, 33.5MB)
테스트 7 〉	통과 (0.24ms, 33.4MB)
테스트 8 〉	통과 (0.22ms, 33.4MB)
테스트 9 〉	통과 (0.23ms, 33.4MB)
테스트 10 〉	통과 (0.24ms, 33.5MB)
테스트 11 〉	통과 (0.22ms, 33.6MB)
테스트 12 〉	통과 (0.22ms, 33.6MB)
테스트 13 〉	통과 (0.23ms, 33.5MB)
테스트 14 〉	통과 (0.22ms, 33.4MB)
테스트 15 〉	통과 (0.22ms, 33.5MB)
테스트 16 〉	통과 (0.21ms, 33.5MB)
테스트 17 〉	통과 (0.24ms, 33.4MB)
테스트 18 〉	통과 (0.12ms, 33.4MB)
테스트 19 〉	통과 (0.15ms, 33.4MB)
테스트 20 〉	통과 (0.10ms, 33.5MB)
테스트 21 〉	통과 (0.10ms, 33.4MB)

<효율성>
테스트 1 〉	통과 (55.90ms, 37.7MB)
테스트 2 〉	통과 (31.05ms, 36.9MB)
테스트 3 〉	통과 (30.35ms, 37.3MB)
테스트 4 〉	통과 (27.99ms, 37MB)
 */

const dx = [0, 0, -1, 1];
const dy = [-1, 1, 0, 0];

const solution = (maps) => {
  const Max_x = maps[0].length;
  const Max_y = maps.length;

  const visit = Array.from(Array(Max_y).fill(0), () => Array(Max_x).fill(0));
  const q = [{ x: 0, y: 0, n: 1 }];

  while (q.length) {
    const { x, y, n } = q.shift();

    if (visit[y][x] == 1) continue;

    if (x == Max_x - 1 && y == Max_y - 1) {
      return n;
    }

    visit[y][x] = 1;

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (nx >= 0 && nx < Max_x && ny >= 0 && ny < Max_y) {
        if (maps[ny][nx] == 1 && visit[ny][nx] == 0) q.push({ x: nx, y: ny, n: n + 1 });
      }
    }
  }

  return -1;
}

const map = [
  [1, 0, 1, 1, 1],
  [1, 0, 1, 0, 1],
  [1, 0, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [0, 0, 0, 0, 1]
];

solution(map);