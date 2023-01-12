
/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/118667
 * 
 * Level 2
 * 
 * dfs가 갑자기 생각나서 풀어봤다가 피본 문제
 * dfs로만 파니 계속해서 시간초과..
 * 
 * array.shift() 는 O(N) 이라는 정보를 얻었다.
 * 

테스트 1 〉	통과 (0.08ms, 33.5MB)
테스트 2 〉	통과 (0.08ms, 33.5MB)
테스트 3 〉	통과 (0.08ms, 33.4MB)
테스트 4 〉	통과 (0.08ms, 33.6MB)
테스트 5 〉	통과 (0.19ms, 33.6MB)
테스트 6 〉	통과 (0.20ms, 33.5MB)
테스트 7 〉	통과 (0.21ms, 33.6MB)
테스트 8 〉	통과 (0.28ms, 33.6MB)
테스트 9 〉	통과 (0.34ms, 33.7MB)
테스트 10 〉	통과 (0.48ms, 33.8MB)
테스트 11 〉	통과 (15.56ms, 45.5MB)
테스트 12 〉	통과 (11.71ms, 40.8MB)
테스트 13 〉	통과 (10.42ms, 43.5MB)
테스트 14 〉	통과 (11.60ms, 44.8MB)
테스트 15 〉	통과 (15.44ms, 47.1MB)
테스트 16 〉	통과 (13.25ms, 47.6MB)
테스트 17 〉	통과 (13.45ms, 45.5MB)
테스트 18 〉	통과 (33.81ms, 66.6MB)
테스트 19 〉	통과 (38.94ms, 67.1MB)
테스트 20 〉	통과 (44.52ms, 71.4MB)
테스트 21 〉	통과 (43.40ms, 71.4MB)
테스트 22 〉	통과 (45.55ms, 71.7MB)
테스트 23 〉	통과 (43.76ms, 71.8MB)
테스트 24 〉	통과 (45.84ms, 73.2MB)
테스트 25 〉	통과 (0.21ms, 33.5MB)
테스트 26 〉	통과 (0.28ms, 33.5MB)
테스트 27 〉	통과 (0.29ms, 33.4MB)
테스트 28 〉	통과 (30.34ms, 54.7MB)
테스트 29 〉	통과 (1.79ms, 35MB)
테스트 30 〉	통과 (26.33ms, 51.3MB)
 */

function solution(queue1, queue2) {
  let count = 0;
  let Max = queue1.length * 3;
  let sumQu1 = queue1.reduce((acc, cur) => acc + cur, 0);
  let targetValue = Math.round([...queue1, ...queue2].reduce((acc, cur) => acc + cur, 0) / 2);
  let q1_idx = 0, q2_idx = 0;

  while (sumQu1 !== targetValue && count < Max) {
    if (sumQu1 > targetValue) {
      sumQu1 -= queue1[q1_idx];
      queue2.push(queue1[q1_idx]);
      q1_idx++;
    } else {
      sumQu1 += queue2[q2_idx];
      queue1.push(queue2[q2_idx]);
      q2_idx++;
    }
    count++;
  }

  return sumQu1 === targetValue ? count : -1;
}

const q_1 = [1, 2, 1, 2], q_2 = [1, 10, 1, 2];
solution(q_1, q_2);