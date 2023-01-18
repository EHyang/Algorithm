/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/150365
 * 
 * 처음 단순 DFS라고 생각하고 문제를 풀었다. 무수히 쏟아지는 빨간 불의 향연..
 * k가 2500 까지이기에 시간초과가 날것인데.. 이걸 인지 못했다. 시간을 엄청 버렸다.
 * 
 * 다시 찾은 풀이법
 * 문제에서 '사전순' 이기에 lrud 를 사전순으로 나열 해보면
 * d l r u
 * 순으로 사용을 해야한다.
 * 
 * 1. 최대한 d를 많이쓰자.
 * 
 * d를 최대한 많이 사용해야 한다. d가 많을 수록 사전순으로 빠르다.
 * 
 * 2. 그 다음으로 l을 많이 쓰자.
 * 
 * 다음 순서가 l이기에 d와 l을 최대한 많이 사용해야한다.
 * 
 * 1과 2의 합으로 (n, 1)로 최대한 가까워 질수록 사전순으로 유리하다.
 * 
 * 처음 주어진 x,y r,c를 통해 최소 거리를 도출한다. 
 * 최소한의 d,l,r,u 의 움직임을 사용하고, 움직여야할 거리가 남아있다면, 최대한 x 는 n으로, y는 1로 근접한다.
 * 
 * x 가 n으로 움직인(d) 만큼 반대방향(u)에 동일한 거리를 추가해준다.
 * y 또한 동일하다. 1로 움직인(l) 만큼 반대방향(r)에 동일한 거리를 추가해준다.
 * 
 * n,1에 도착하고도 가야할 거리가 남았다면, rl 또는 ud를 반복해주어야 하지만, rl이 ud 보다 사전순으로 빠르기에 rl 남은 수의 반만큼 반복해준다.
 * 
테스트 1 〉	통과 (0.08ms, 33.6MB)
테스트 2 〉	통과 (0.08ms, 33.4MB)
테스트 3 〉	통과 (0.07ms, 33.4MB)
테스트 4 〉	통과 (0.12ms, 33.4MB)
테스트 5 〉	통과 (0.08ms, 33.4MB)
테스트 6 〉	통과 (0.08ms, 33.5MB)
테스트 7 〉	통과 (0.08ms, 33.4MB)
테스트 8 〉	통과 (0.13ms, 33.5MB)
테스트 9 〉	통과 (0.08ms, 33.5MB)
테스트 10 〉	통과 (0.08ms, 33.4MB)
테스트 11 〉	통과 (0.08ms, 33.6MB)
테스트 12 〉	통과 (0.09ms, 33.4MB)
테스트 13 〉	통과 (0.08ms, 33.6MB)
테스트 14 〉	통과 (0.08ms, 33.5MB)
테스트 15 〉	통과 (0.08ms, 33.5MB)
테스트 16 〉	통과 (0.08ms, 33.6MB)
테스트 17 〉	통과 (0.08ms, 33.5MB)
테스트 18 〉	통과 (0.08ms, 33.5MB)
테스트 19 〉	통과 (0.08ms, 33.5MB)
테스트 20 〉	통과 (0.08ms, 33.4MB)
테스트 21 〉	통과 (0.13ms, 33.4MB)
테스트 22 〉	통과 (0.08ms, 33.4MB)
테스트 23 〉	통과 (0.08ms, 33.4MB)
테스트 24 〉	통과 (0.08ms, 33.4MB)
테스트 25 〉	통과 (0.09ms, 33.5MB)
테스트 26 〉	통과 (0.08ms, 33.5MB)
테스트 27 〉	통과 (0.08ms, 33.5MB)
테스트 28 〉	통과 (0.08ms, 33.5MB)
테스트 29 〉	통과 (0.08ms, 33.5MB)
테스트 30 〉	통과 (0.08ms, 33.5MB)
테스트 31 〉	통과 (0.07ms, 33.5MB)
 */

const solution = (n, m, x, y, r, c, k) => {
  let dist = k - (Math.abs(x - r) + Math.abs(y - c));

  if (dist < 0 || dist % 2 != 0) return 'impossible';

  let answer = '';

  const dlru = [0, 0, 0, 0];

  dlru[0] = r > x ? r - x : 0; // 아래로 최소 움직임
  dlru[1] = y > c ? y - c : 0; // 좌측 최소 움직임
  dlru[2] = c > y ? c - y : 0; // 우측 최소 움직임
  dlru[3] = x > r ? x - r : 0; // 위로 최소 움직임

  answer += 'd'.repeat(dlru[0]);

  let t = Math.min(n - (x + dlru[0]), dist / 2);
  answer += 'd'.repeat(t);
  dlru[3] += t;
  dist -= 2 * t;

  answer += 'l'.repeat(dlru[1]);
  let tm = Math.min(y - (1 + dlru[1]), dist / 2);
  answer += 'l'.repeat(tm);
  dlru[2] += tm;
  dist -= 2 * tm;

  answer += 'rl'.repeat(dist / 2);
  answer += 'r'.repeat(dlru[2]);
  answer += 'u'.repeat(dlru[3]);

  return answer;
}


console.log(solution(3, 4, 2, 3, 3, 1, 5)) // dllrl
// console.log(solution(10, 2, 1, 1, 9, 2, 13))
// console.log(solution(2, 3, 1, 2, 1, 1, 3))

