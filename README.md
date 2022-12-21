1 일 1 알고리즘 풀이 저장소
=================
- 지금은 [바킹독 문제집](https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook.md) 및 [solved class](https://solved.ac/class) 문제 중심으로 풀고 있습니다.
- [백준 - Platinum V](https://solved.ac/profile/sjh910805) 
     
     
     <img src="http://mazassumnida.wtf/api/v2/generate_badge?boj=sjh910805">
- [프로그래머스 - Lv3](https://career.programmers.co.kr/pr/sjh910805_1792)

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
  - 왼쪽 서브트리의 모든 값이 부모노드 보다 작고, 오른쪽 서브트리의 모든 요소 값들이 부모노드 보다 작은 이진 트리
  - 일반 배열보다 삽입 삭제 조회가 빠름. O(lgN)
  - 해시는 값을 정렬 안해주지만 얘는 정렬해줌.
  - 여태 map을 해시로 알고 있었는데, 이진검색트리였음..
  - 해시로 구현한 C++ STL : unordered_set, unordered_multiset, unordered_map
  - 이진검색트리로 구현한 C++ STL : set, multiset, map
  - 엄밀히 말하면 그냥 이진검색트리가 아니라 균형잡힌 이진검색 트리임. 그 중 내가 구현해본 모델로 AVL가 있는데, C++에서는 레드블랙트리로 구현함. 이게 더 성능 좋으니.

- 다익스트라
  - 가중치가 2 이상인 그래프에서 한 정점에서 시작하여 다른 모든 정점까지의 최단 경로를 찾는 알고리즘
  - 음수 간선 불가능 (음수 간선이 있는 경우에는 벨만포드 알고리즘 사용)
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
    5. c~d번 반복
  - [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Gold/2252.%E2%80%85%EC%A4%84%E2%80%85%EC%84%B8%EC%9A%B0%EA%B8%B0)
  
- 플로이드 알고리즘
  - 모든 쌍의 최단 거리와 그것의 경로를 O(V^3)로 구하는 알고리즘
  - 시간 복잡도가 높아서, 정점의 수가 1000개는 상황에 따라 아슬아슬하고, 500개 정도면 충분히 가능
  - 음수 간선 가능, 음수 사이클 불가능
  - 최단 거리 구현 방법
    1. cost[i][j] = i 정점에서 j 정점까지 가는데 드는 최소 비용. 을 나타내는 이 테이블을 갱신해줄거야
    2. 처음 테이블의 모든 요소를 1e9로 갱신. 두 요소를 더하는 상황도 있기에 2e9로 하지 않음.
    3. 자기 자신까지 가는데는 0으로 갱신
    4. 바로 인접한 정점까지의 비용만 입력을 받으면서 갱신
    5. 정점을 하나씩 정해주면서, 해당 정점을 거쳐가는 경우의 비용과 거쳐가지 않는 기존의 비용과 대소 비교를 통해 작은쪽으로 갱신
        - a = min(a, b); 는 매번 대입을 하기 때문에, if(a > b) a = b; 라고 하는 편이 성능면에서 이득
    6. d번 에서 결국 3중 for문을 돌게 되는데, 이때 거쳐갈 정점을 맨 바깥으로 빼놔야돼.
  - [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Gold/11404.%E2%80%85%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C)
  - 경로 복원 구현 방법
    1. nxt[i][j] = i 정점에서 j 정점까지 최소 비용으로 갈때, i에서 이동하는 그 다음 정점
    2. 바로 인접한 정점까지의 입력을 받을때 1차로 갱신
    3. k 정점을 거쳐가는 경우의 비용이 작을때, nxt[i][j] = nxt[i][k]로 갱신
    4. i에서 j까지의 경로 담는법 : while(st != j) { path.push_back(st); st = nxt[st][j]; } path.push_back(j);
  - [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Gold/11780.%E2%80%85%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C%E2%80%852)

- KMP 알고리즘 (코테에 나올 확률 매우 적음)
     - 이해 못함
     - 단순히 부분 문자열이 있냐 없냐만 확인할거라면 strstr 함수 활용해. 시간복잡도 O(N+M)
     - [strstr 활용한 모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Bronze/16916.%E2%80%85%EB%B6%80%EB%B6%84%E2%80%85%EB%AC%B8%EC%9E%90%EC%97%B4)
     - 그런게 아니라 조금 더 응용해야 되는 상황이면 str.find() 쓰고. 시간복잡도 O(N*M)
     - 시간초과 뜨면 문제 포기해.
     - find를 활용하여 부분 문자열이 몇개 들어있는지 찾기
     - ``` 
       while(1) {
            int findedIdx = str.find(pattern, idx);
            if(findedIdx == -1) break;
            idx = findedIdx + pattern.size();
            cnt++;
       }
       ```
     - map이나 set, hash 값을 이용하는 다른 방법이 없을까 고민해봤는데 결국 for문 안에서 substr을 만들어서 그걸 map에 넣거나 hash값을 만들어서 패턴과 비교하는건데, for문이 O(N), substr은 O(M) 이라, find 쓰는거랑 별 차이 없는듯.
     - Rabin-karp가 시간복잡도가 O(N)인, 해쉬값을 활용한 알고리즘 이라는데,,, 나중에 다시 보자.

- 트라이
     - 문자열을 저장할 수 있는 트리 자료구조
     - 단순 문자열 삽입/삭제/조회 할때는 그냥 시간상 공간상 map 쓰는게 훨씬 이득
     - 다만, 트라이를 써야만 풀리는 문제들이 있어. 자동완성기능처럼 접두사만 가지고 이래저래 해야 하는 문제들.
     - [트라이 구현](https://github.com/Joshua-Shin/Algorithm-BaekJoon/blob/main/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EA%B5%AC%ED%98%84%ED%95%A8%EC%88%98/%ED%8A%B8%EB%9D%BC%EC%9D%B4.cpp)
     - [모범 예제](https://github.com/Joshua-Shin/Algorithm-BaekJoon/tree/main/%EB%B0%B1%EC%A4%80/Silver/14425.%E2%80%85%EB%AC%B8%EC%9E%90%EC%97%B4%E2%80%85%EC%A7%91%ED%95%A9)

- 이후 과정
     - 연습문제 + 기본문제 + 응용문제 체크 표시된 문제중 안푼거 풀기
     - 랜덤 디펜스 : 티어와 알고리즘 분류를 보이지 않게 하고 문제를 푸는거. 실3~골3 난이도 안에서 랜덤 디펜스를 진행.
     - 취약한 알고리즘 분야 다시 개념 복습 및 응용 문제 풀기
     - 세그먼트 트리, 기하, 라빈 카프, 유량, SCC, BCC, 게임 이론 등 다양한 알고리즘 익혀가기
     - 코드 포스, 앳코드, 대회 참여.
