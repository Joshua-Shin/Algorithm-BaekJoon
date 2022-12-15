1 일 1 알고리즘 풀이 저장소 for 백준
=================
- 지금은 [바킹독 문제집](https://github.com/Joshua-Shin/basic-algo-lecture/blob/master/workbook.md) 및 [solved class](https://solved.ac/class) 문제 중심으로 풀고 있습니다.
- [백준 Platinum V](https://solved.ac/profile/sjh910805)
<img src="http://mazassumnida.wtf/api/v2/generate_badge?boj=sjh910805">

-------------------

나만의 알고리즘 전략
-------------
- **테스트가 일주일도 안남았다면, 완전 탐색 및 시뮬레이션 문제를 위주로 연습한다.**

- 그리디
  - 100% 신뢰할만한 풀이법이 떠오르지 않은 상태라면, 일단 스킵하고 마지막에 푼다.
  - 100% 신뢰할만한 풀이법으로 구현을 했는데 틀렸다면, 일단 스킵하고 마지막에 푼다. 
  - 풀이법이 틀렸는지, 구현을 잘못했는지 확인할 수 없기 때문.
  - 떠올린 풀이법에서 **'지금 당장은 손해보더라도, 나중가서 이득을 볼 수 있는 상황이 있는 것은 아닌가?'** 라는 방향으로 고민하면 반례를 찾을 수도 있다.
  
- DP
  - 풀이법에는 Top-Down 방식과 Bottom-Up 방식이 있다.
  - Top-Down 방식은 재귀를 통해, Bottom-Up 방식은 배열과 for문을 통해 구현할 수 있다.
  - 두 가지 모두에 익숙해 지려 하지 말고, 한 가지 방식으로만 판다.
  - 전반적으로 성능면에서 Top-Down 방식이 손해가 있긴 하다.
  - 다만, 재귀를 활용한 완전탐색으로 문제를 풀다가 시간복잡도가 너무 크다 싶으면, 메모이제이션을 활용하면서 자연스럽게 top-down 재귀형태로 문제를 풀수가 있게 되니, 생각의 흐름이 조금 더 자연스럽고 직관적이다.
  - 따라서 나는 일단은 Top-Down 방식으로 연습한다.
  - 유감스럽게도 구글링 했을때 나오는 풀이법들로는 Bottom-Up 방식이 많긴 하다.
  - **최적화 문제 동적 계획법 구현 방법**
    1. 앞으로 남은 선택들에 해당하는 결과들을 반환하도록 함수를 잘~ 정의
    2. 점화식 구성
    3. 기저사례들을 정리
    4. 메모이제이션 적용해서 함수 구현
    
- 백트래킹
  - '종만북'에서 굳이 백트래킹을 다른 챕터로 두어 다루지 않았던 이유는 종만북에서 소개한 완전탐색에서 이미 그 개념을 포함하여 함수를 구현했기 때문인듯하다.
  - 더 이상 탐색을 할 필요 없는 상황에서 탐색을 멈추는것을 백트래킹이라 하는데, 사실상 내가 알고있는 재귀를 활용한 완전탐색 함수에서 기저사례를 두는것이 이 개념과 동일하다.
 
- 최소 신장 트리 ( = 최소 스패닝 트리)
  - 신장 트리 중 가중치의 총합이 최소값을 이루는 트리
  - 크루스칼 알고리즘 + 유니온 파인드 알고리즘으로 푼다.
  - 간선의 가중치를 오름차순으로 정렬한뒤, 가장 값이 작은 가중치를 갖는 간선부터 하나씩 추가한다.
  - 이때 사이클이 형성되나 안되나 확인하는데 사이클이 형성되면 간선을 더한것을 취소하고 사이클이 형성 안되면 확정한다. 
  - 확인하는 방법은 유니온 파인드를 활용한다.
  - 완성된 최소 스패닝 트리 특성상 간선의 개수가 정점의 개수보다 하나가 작다.
  - 떄문에 추가된 간선의 개수 정점의 개수보다 하나가 적은 시점까지 사이클이 형성되지 않도록 간선을 추가하는 과정을 밟으면 된다.
  - [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Gold/1197.%E2%80%85%EC%B5%9C%EC%86%8C%E2%80%85%EC%8A%A4%ED%8C%A8%EB%8B%9D%E2%80%85%ED%8A%B8%EB%A6%AC)
  
- 시뮬레이션
  - 풀이법에 특정 알고리즘이 필요한것이 아니라 그냥 빡구현 하는 문제를 시뮬레이션이라 분류한다.
 
- 투 포인터
  - 엄밀히 따지면 슬라이딩 윈도우는 배열의 크기가 고정적인 상태이고 투 포인터는 아닌 상태로 이 둘을 구분하기도 한다. 
  - 다만 굳이 이 둘을 구분해서 이해할 필요 없을듯
  
- 이진 검색 트리 ( = 이진 탐색 트리)
  - set 활용

- 다익스트라
  - 가중치가 2 이상인 그래프에서 최단 경로를 찾는 알고리즘
  - 작동 원리
    1. 출발 노드를 설정
    2. 출발 노드를 기준으로 인접 노드의 최소비용을 저장 (인접 노드로 방문한게 아직 아니라, 인접노드까지 가는데 얼마만큼의 비용이 드는지만 확인하는 과정)
    3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택
    4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신
    5. 위 과정에서 3번~4번을 반복합니다.
  - [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Gold/1753.%E2%80%85%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C)
  
- 트리
  - 루트에서 bfs를 돌릴 경우 depth 순서대로 방문을 한다.(= 레벨 순회)
  - 이를 이용해, bfs를 돌며 각 노드의 부모배열과 depth 배열을 채울 수 있다.
  - 트리의 부모 배열 채우기 [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Silver/11725.%E2%80%85%ED%8A%B8%EB%A6%AC%EC%9D%98%E2%80%85%EB%B6%80%EB%AA%A8%E2%80%85%EC%B0%BE%EA%B8%B0)
  - 이진 트리의 경우 입력을 받을 때 lc[x](= x 노드의 왼쪽 자식 노드 값), rc[x] 배열을 채우면 클래스를 정의할 필요 없이 진행할 수 있다.
  - 이진 트리의 전위, 중위, 후위 순회 [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Silver/1991.%E2%80%85%ED%8A%B8%EB%A6%AC%E2%80%85%EC%88%9C%ED%9A%8C)

- 위상 정렬
  - 사이클이 없는 방향 그래프에서 선후 관계의 모순 없이 나열하는 것
  - 사이클이 없는 무방향(=양방향) 그래프를 트리라고 하고, 사이클이 없는 방향 그래프는 DAG라 함
  - 때문에 위상 정렬을 돌려 결과 배열을 나열하면 전체 정점 개수와 크기 비교를 통해 사이클이 있는지 없는지도 판단할 수 있음.
  - 구현 방법
    1. 입력을 받을때 배열 deg[x](정점 x의 indegree값)을 갱신, adj[x] 갱신
    2. deg[x]==0 인 x 값들 큐에 넣음
    3. 큐에서 정점 꺼내면서 result 배열에 해당 정점 넣어주고, 해당 정점과 연결된 정점들의 deg[nx] 값 1씩 빼줌
    4. 1을 뺄때 값이 0이 되는 정점은 큐에 넣어줌
    5. c~d 반복
  - [모범 에제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Gold/2252.%E2%80%85%EC%A4%84%E2%80%85%EC%84%B8%EC%9A%B0%EA%B8%B0)
