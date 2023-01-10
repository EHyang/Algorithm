
/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/150369
 * 
 * Level 2
 * 
 * 처음엔 인덱스를 직접 배열에 저장해서 reverse 한뒤 사용하였고,
 * shift와 splice를 사용해서 조금 더럽게 풀었었다.
 * 
 * 결국 17번에서 시간 초과가 떴고, 16, 18번도 아슬아슬했다.
 * 배열을 걷어내고, 인덱스만을 사용해서 값을 참조했고,
 * 
 * deliveries, pickups 배열 모두 값이 0인 곳은 참조할 필요가 없어 바로 지나가도록 했다.
 * 
 * 조금 더 JS 스럽게.
 * 

테스트 1 〉	통과 (0.07ms, 33.4MB)
테스트 2 〉	통과 (0.07ms, 33.5MB)
테스트 3 〉	통과 (0.17ms, 33.6MB)
테스트 4 〉	통과 (0.17ms, 33.4MB)
테스트 5 〉	통과 (0.17ms, 33.4MB)
테스트 6 〉	통과 (0.17ms, 33.6MB)
테스트 7 〉	통과 (0.29ms, 33.5MB)
테스트 8 〉	통과 (1.05ms, 33.5MB)
테스트 9 〉	통과 (7.15ms, 36.7MB)
테스트 10 〉	통과 (5.78ms, 36.7MB)
테스트 11 〉	통과 (2.73ms, 36.7MB)
테스트 12 〉	통과 (0.64ms, 33.7MB)
테스트 13 〉	통과 (0.85ms, 33.7MB)
테스트 14 〉	통과 (0.85ms, 33.8MB)
테스트 15 〉	통과 (4.31ms, 40MB)
테스트 16 〉	통과 (38.02ms, 43.5MB)
테스트 17 〉	통과 (61.98ms, 43.4MB)
테스트 18 〉	통과 (7.51ms, 40.2MB)
테스트 19 〉	통과 (18.91ms, 40.4MB)
테스트 20 〉	통과 (21.78ms, 40.8MB)
 */

function solution(cap, n, deliveries, pickups) {
  let answer = 0;
  let d_idx = n - 1, p_idx = n - 1;

  while (d_idx >= 0 || p_idx >= 0) {
    while (deliveries[d_idx] === 0) d_idx--;
    while (pickups[p_idx] === 0) p_idx--;

    answer += d_idx >= p_idx ? (d_idx + 1) * 2 : (p_idx + 1) * 2;

    let box = 0;
    while (d_idx >= 0 || box <= cap) {
      if (deliveries[d_idx] + box <= cap) {
        box += deliveries[d_idx];
        d_idx--;
      } else {
        deliveries[d_idx] -= (cap - box);
        break;
      }
    }

    box = 0;
    while (p_idx >= 0 || box <= cap) {
      if (pickups[p_idx] + box <= cap) {
        box += pickups[p_idx];
        p_idx--;
      } else {
        pickups[p_idx] -= (cap - box);
        break;
      }
    }
  }

  return answer;
}

const c = 2, n = 7;
const de = [1, 0, 2, 0, 1, 0, 2];
const pi = [0, 2, 0, 1, 0, 2, 0];

solution(c, n, de, pi);