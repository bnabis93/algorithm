# 강한 연결 요소

#### [To do lists] 

- 10265  
- 4013  
- 6497  



## 강한 연결 요소란?

방향이 있는 그래프 (Directed graph) 의 연결요소 (Connected component, 서로 연결되어 있는 Node) 내 임의의 노드 'u'에서 'v'로 향하는 경로와 'v'에서 'u'로 향하는 경로가 존재할 때 이를 강한 연결 요소라 한다. (어느 한쪽에서 출발하여도 상대편으로 도착이 가능하다.)  다음 그림에서는 총 4개의 강한 연결요소가 존재한다. 그림을 보면 이해 할 수 있듯이 직접적인 Cycle이 아니더라도 돌아올 수 있다면, 강한 연결 요소가 생성이 된다.  
<img src="https://i.imgur.com/CtlPGFw.png" alt="img" style="zoom:67%;" />

이미지 출처 : https://ratsgo.github.io/data%20structure&algorithm/2017/11/23/SCC/

이를 찾아내는 방법은 기법의 핵심 아이디어는 다음과 같다.  
원 그래프 'G' 의 Node 'a'에서 'b'로 향하는 경로가 존재 할 때, 경로를 뒤집은 그래프인 $G^{T}$ 를 분석 해 본 결과 'b'에서 'a'로 향하는 경로가 존재한다면, 'a'와 'b'는 서로 강한 연결요소 속성을 만족한다.  
<img src="https://i.imgur.com/NHUDUaH.png" alt="img" style="zoom:50%;" />



## Algorithm

강한 연결 요소는 깊이 우선 탐색(DFS)를 기본으로 하여 구한다. DFS를 사용 한 다는 말은 한 Node에 대해서 모든 경로를 탐색하겠다는 의미가 된다. 아마 DFS를 두번 수행하여 강한 연결 요소를 구하게 될 것이라 예측 할 수 있다. (원 그래프, Transpose 그래프)  
핵심은 다음의 두가지 과정이다.  

- 먼저 DFS를 수행한다. 그 후 원 그래프를 Transpose 한다. (엣지 방향만 바꾸어 준다.)
- Transpose 한 그래프를 다시 DFS 수행해준다.

큰 흐름은 다음과 같고, 바로 문제와 Code 보면서 이해를 하는것이 좋을 것 이라 생각한다.  



## Problem BOJ #6497 설명

백준 6497번 문제 : https://www.acmicpc.net/problem/6497  

해당 문제는 강한 연결 요소 문제이지만, 최소 신장 트리 + 크루스칼 알고리즘으로 푼 경우가 대다수 이다.  

![BOJ6797](./img/scc_BOJ6497.png)

- 입력 조건에서 모든 Node가 강한 연결 요소임을 전제하고 있음
- Node간 사이클이 존재해야 한다.
- A -> C로 가는 방법이 A -> C / A -> B -> C 가 존재함
- 두 가지 경로 중, 돈이 많이 드는 경로는 불을 끄겠다.
- 돈이 많이 든다의 기준은, 거리가 멀다
- 거리 = 가중치 / 가중치가 가장 작은 Edge간 연결을 찾는 것  => 최소 신장 트리 (MST) 문제로 귀결
- MST를 찾기위하여 크루스칼 알고리즘을 사용한다.  

  

### 최소 스패닝 트리 (Minimum Spanning Tree, MST)

#### Spanning Tree

그래프 내 모든 정점을 포함하는 Tree. 즉, 그래프 내 일부 Edge를 선택하여 Tree 구조를 만든 것

- 한 그래프 내 여러 Spanning Tree가 존재한다.   
- Spanning Tree는 트리의 특수한 형태이다.
- 따라서 모든 Node 들이 연결되어 있어야 하고, 사이클을 포함하지 않는다.
- n개의 Node를 n-1개의 edge로 연결하는 형태이다.

<img src="https://gmlwjd9405.github.io/images/algorithm-mst/spanning-tree.png" alt="img" style="zoom: 33%;" />

이미지 출처 : https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html

#### Minumum Spanning Tree (MST)

한 그래프 내 수많은 Spanning Tree중 Edge의 가중치 합이 최소인 Tree  

- MST는 Edge의 가중치를 고려하여 최소비용의 Tree를 구성한다.
- 따라서 구성된 MST는 여러 spanning tree중 최소의 가중치 합을 가지는 Edge 조합으로 이루어져 있음
- 이또한 Spanning Tree이므로 n개의 node에 대하여 n-1개의 edge를 가지고 있음
- 사이클이 존재해서는 안된다.

#### 크루스칼 알고리즘

Greedy한 방식으로 edge 가중치 합을 최소로 하는 조합을 구하는 방법

- 모든 Node의 Edge를 끊어놓는다. (가중치만을 고려하여 선택하기 위한 준비)
- 가중치 순으로 Edge를 오름차순으로 정렬한다.
- 정렬된 간선을 순서대로 선택한다. 
- 선택 할 때, 선택된 Node들이 연결되어 있는지 확인을 한 후, 연결되어 있지 않다면 연결시켜준다.  

크루스칼 알고리즘 : [https://www.weeklyps.com/entry/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Kruskals-algorithm](https://www.weeklyps.com/entry/크루스칼-알고리즘-Kruskals-algorithm) 

## Code review, c++







## Reference

- https://ratsgo.github.io/data%20structure&algorithm/2017/11/23/SCC/
- https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html