/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/77486
 * 
 * 그래프 문제인건가, 노드 문제인건가..
 * 
 * 처음에 reduce를 활용해서 노드를 만들었는데, 자꾸 시간초과가 떠서.. 
 * reduce를 버렸는데, 바로 통과가 되었다.
 * 
 * reduce O(n), foreach O(n) 으로 알고있었는데.... 다른가..?
 * 
 * 문제 구현할때 중요한점은 부모 노드에게 줄 돈이 0이라면, 더 이상 재귀를 타지 않는다는 것.
 * 
테스트 1 〉	통과 (0.34ms, 33.5MB)
테스트 2 〉	통과 (0.49ms, 33.5MB)
테스트 3 〉	통과 (0.34ms, 33.6MB)
테스트 4 〉	통과 (0.34ms, 33.6MB)
테스트 5 〉	통과 (0.72ms, 33.6MB)
테스트 6 〉	통과 (3.47ms, 40.8MB)
테스트 7 〉	통과 (4.15ms, 40MB)
테스트 8 〉	통과 (6.39ms, 40.9MB)
테스트 9 〉	통과 (10.71ms, 40.5MB)
테스트 10 〉	통과 (27.02ms, 48MB)
테스트 11 〉	통과 (22.43ms, 49.1MB)
테스트 12 〉	통과 (25.63ms, 47.9MB)
테스트 13 〉	통과 (23.17ms, 48.8MB)
 */

const solution = (enroll, referral, seller, amount) => {
  const node = {};

  enroll.forEach((e, idx) => {
    node[e] = {
      pay: 0,
      parent: referral[idx]
    }
  });

  const makeMoney = (me, pay) => {
    const perc = Math.floor(pay * 0.1);
    node[me].pay += pay - perc;

    if (perc === 0) return;

    if (node[me].parent === '-') return;

    return makeMoney(node[me].parent, perc);
  }

  seller.forEach((e, idx) => {
    makeMoney(e, amount[idx] * 100)
  });

  return enroll.map(it => node[it].pay);
}

console.log(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"], ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"], ["young", "john", "tod", "emily", "mary"], [12, 4, 2, 5, 10]))

