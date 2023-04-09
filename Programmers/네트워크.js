/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/43162
 * 
 * 백준의 `섬의 개수`와 비슷한 유형의 문제라 생각하여 BFS로 접근 했었다.
 * 
 * 많은 테스트 케이스가 틀렸었고, 접근 방법이 잘못 되었음을 깨달았다.
 * 
 * 이제야 안 사실인데, Union-find 형태의 문제라고 한다.
 * 
 * 
 * -- 풀이방법
 * 길이 n의 배열을 만들어 내가 연결된 컴퓨터를 적어둔다.
 * 최초 생성시에는 본인의 인덱스가 들어간다.
 * 
 * computers를 탐색하며, (i, j) 가 연결 되어 있을 경우
 * check[i] check[j] 를 비교하여 더 작은 인덱스 값으로 변경해준다.
 * 이때, check 배열에서 변경되기 전 값과 동일한 값을 가지고 있는 컴퓨터가 있다면, 모두 동시에 변경해준다.
 *
테스트 1 〉	통과 (0.18ms, 33.6MB)
테스트 2 〉	통과 (0.09ms, 33.5MB)
테스트 3 〉	통과 (0.20ms, 33.5MB)
테스트 4 〉	통과 (0.21ms, 33.5MB)
테스트 5 〉	통과 (0.07ms, 33.4MB)
테스트 6 〉	통과 (0.28ms, 33.6MB)
테스트 7 〉	통과 (0.19ms, 33.4MB)
테스트 8 〉	통과 (0.27ms, 33.6MB)
테스트 9 〉	통과 (0.28ms, 33.7MB)
테스트 10 〉	통과 (0.23ms, 33.6MB)
테스트 11 〉	통과 (0.95ms, 33.7MB)
테스트 12 〉	통과 (0.58ms, 33.7MB)
테스트 13 〉	통과 (0.53ms, 33.6MB)

+ DFS로는 더빠르게 풀수 있었다...

 */

const changeMin = (tar, val, check) => {
  while (check.indexOf(tar) > 0) {
    check.splice(check.indexOf(tar), 1, val);
  }
}

const solution = (n, computers) => {
  const check = Array.from(Array(n), (_, i) => i);

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (computers[i][j]) {
        computers[i][j] = 0;

        if (check[i] !== check[j]) {
          changeMin(Math.max(check[i], check[j]), Math.min(check[i], check[j]), check);
        }
      }
    }
  }

  return [...new Set(check)].length;
}

// console.log(solution(
//   7,
//   [[1, 0, 0, 0, 0, 0, 1],
//   [0, 1, 1, 0, 1, 0, 0],
//   [0, 1, 1, 1, 0, 0, 0],
//   [0, 0, 1, 1, 0, 0, 0],
//   [0, 1, 0, 0, 1, 1, 0],
//   [0, 0, 0, 0, 1, 1, 1],
//   [1, 0, 0, 0, 0, 1, 1]]
// ))