# 최소 신장 트리 

### To-do lists

- BOJ #1922
- BOJ #1944
- BOJ #9373 (-ing)



## Concepts

신장트리란 (Spanning tree)   

1. 원 그래프의 모든 Node를 포함하고  
2. 모든 Node가 서로 연결되어 있으며  
3. Tree의 속성을 만족하는 Graph를 뜻함  

다음의 그림을 보면 쉽게 이해 할 수 있다. 밑의 그래프는 오른쪽과 같은 Spanning tree를 가진다.

<img src="https://i.imgur.com/xYkNNxl.png" alt="img" style="zoom:50%;" />   
이미지 출처 : https://ratsgo.github.io/data%20structure&algorithm/2017/11/28/MST/  

최소신장트리는 이러한 Spanning tree 중 edge의 가중치 합이 최소가 되는 spanning tree를 말한다.  
<img src="https://i.imgur.com/kITm4WO.png" alt="img" style="zoom:50%;" />  
이미지 출처 : 이미지 출처 : https://ratsgo.github.io/data%20structure&algorithm/2017/11/28/MST/    

이를 구현하기 위하여 유명한 두가지 알고리즘이 있는데 이를 소개하고자 한다.  



## 크루스칼 알고리즘

크루스칼 알고리즘은 Greedy한 방식으로 최소신장트리를 찾는 방법이다.  
이는 분석하고자 하는 Node로부터 가중치가 최소가 되는 **Edge를 찾고 (Find)** 연결된 **Node를 이어준 후 (Union)** 이로써 형성된 그래프가 **Tree 구조를 만족하는지 확인 (Safety check)** 을 하는 방식으로 동작된다.  
이때 분석하고자 하는 Node로 부터 **가중치가 최소인 edge를 light edge** 이로써 이어진 Node가 **트리 구조를 만족한다면 해당 Edge를 Safe**하다고 한다.  
이를 구현하기 위해서 일반적으로 **Disjoint set 자료구조**를 이용한다.  

- **Disjoint set**  
서로 중복되지 않는 부분집합으로 나뉘어진 원소에 대하여 저장 / 조작을 해주는 자료구조  
  이는 전체 집합이 존재할때 이를 겹치지 않는 부분집합으로 나누는데 주로 사용이 된다.    
  

### Algorithm 

크루스칼 알고리즘은 다음의 순서로 진행이 된다.  

1. 모든 Edge들을 오름차순으로 정렬한다.  

2. 이 중에서 가중치가 가작 작은 Edge를 선택한다.  

3. 선택된 Edge를 Find & Safe (서로 다른 집합인가?̊̈, 트리구조를 만족하는가?̊̈) 을 해준 후, 이를 만족한다면 Union (Node를 연결) 해준다.  

4. 이를 반복해준다.  



## 프림 알고리즘





## BOJ #9373

https://www.acmicpc.net/problem/9373  
- 복도가 존재하고, 복도의 너비는 [1, 100,000] 이다.  
- 복도에는 센서가 존재하고 센서의 인식범위는 원의 형태를 가진다.  
- 센서 사이를 지나 목표 지점으로 가고자하고 이때 센서 사이를 지나는 객체를 원이라 가정한다.   
- 이때 센서에 걸리지 않고 목표지점으로 도달 할 수있는 객체의 최소 반지름을 구하자  

센서의 위치와 반지름을 알고 있고 이 사이를 지나는 원의 최소 반지름  
![BOJ9373](BOJ9373.png)

## Reference

- 최소신장트리 : https://ratsgo.github.io/data%20structure&algorithm/2017/11/28/MST/
- 크루스칼 알고리즘 : https://hongku.tistory.com/159 