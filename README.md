# ■ Data Structure

* 자료구조(資料構造, 영어: data structure)는 전산학에서 자료를 효율적으로 이용할 수 있도록 컴퓨터에 저장하는 방법이다. 신중히 선택한 자료구조는 보다 효율적인 알고리즘을 사용할 수 있게 한다. 이러한 자료구조의 선택문제는 대개 추상 자료형의 선택으로부터 시작하는 경우가 많다. 효과적으로 설계된 자료구조는 실행시간 혹은 메모리 용량과 같은 자원을 최소한으로 사용하면서 연산을 수행하도록 해준다.

## ★ 정렬 (Sorting)

#### # Insert Sorting (삽입정렬)

#### # Quick Sorting (퀵정렬)

* 퀵 정렬(Quicksort)은 찰스 앤터니 리처드 호어가 개발한 정렬 알고리즘이다. 다른 원소와의 비교만으로 정렬을 수행하는 비교 정렬에 속한다. 퀵 정렬은 n개의 데이터를 정렬할 때, **최악의 경우에는 O(n2)번의 비교를 수행**하고, **평균적으로 O(n log n)번의 비교를 수행**한다. **퀵 정렬의 내부 루프는 대부분의 컴퓨터 아키텍처에서 효율적으로 작동하도록 설계되어 있고(그 이유는 메모리 참조가 지역화되어 있기 때문에 CPU 캐시의 히트율이 높아지기 때문이다.)**, 대부분의 실질적인 데이터를 정렬할 때 제곱 시간이 걸릴 확률이 거의 없도록 알고리즘을 설계하는 것이 가능하다. 때문에 **일반적인 경우 퀵 정렬은 다른 O(n log n) 알고리즘에 비해 훨씬 빠르게 동작한다. 그리고 퀵 정렬은 정렬을 위해 O(log n)만큼의 memory를 필요로한다.** 또한 **퀵 정렬은 불안정 정렬에 속한다.**

<p align="center">
	<img src="https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif" />
</p>

###### ※ Quick Sorting Process

* 리스트 가운데서 하나의 원소를 고른다. 이렇게 고른 원소를 피벗이라고 한다.

* 피벗 앞에는 피벗보다 값이 작은 모든 원소들이 오고, 피벗 뒤에는 피벗보다 값이 큰 모든 원소들이 오도록 피벗을 기준으로 리스트를 둘로 나눈다. 이렇게 리스트를 둘로 나누는 것을 분할이라고 한다. 분할을 마친 뒤에 피벗은 더 이상 움직이지 않는다.

* 분할된 두 개의 작은 리스트에 대해 재귀(Recursion)적으로 이 과정을 반복한다. 재귀는 리스트의 크기가 0이나 1이 될 때까지 반복된다.

###### ※ Quick Sorting Source Code

```C++
#define SWAP(X, Y, Z) Z=X; X=Y; Y=Z;

/* Quick Sorting */
void QuickSort(int * mArr, int left, int right)
{
	int pivot = mArr[(left + right) / 2]; /* 중심축 */
	int mLeft = left; /* 정렬 대상의 가장 왼쪽 지점 */
	int mRight = right; /* 정렬 대상의 가장 오른쪽 지점 */
	int mTemp = 0;

	while (mLeft <= mRight) /* mLeft와 mRight가 교차하지 않을 때 경우까지 반복한다. */
	{
		while (mArr[mLeft] < pivot) { ++mLeft; } /* pivot 보다 큰 값을 찾는 경우 */
		while (mArr[mRight] > pivot) { --mRight; } /* pivot 보다 작은 값을 찾는 경우 */

		if (mLeft <= mRight) /* mLeft 보다 mRight가 값이 크거나 같은 경우 */
		{
			SWAP(mArr[mLeft], mArr[mRight], mTemp); /* mLeft와 mRight 값을 교환한다. */
			++mLeft, --mRight; /* mLeft 증가, mRight 감소 */
		}
	}

	if (left < mRight) { QuickSort(mArr, left, mRight); }
	if (mLeft < right) { QuickSort(mArr, mLeft, right); }
}
```

## ★ 선형 구조

#### # Stack (스택 구조)
스택(stack)은 제한적으로 접근할 수 있는 나열 구조이다. 그 접근 방법은 언제나 목록의 끝에서만 일어난다. 끝먼저내기 목록(Pushdown list)이라고도 한다.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/29/Data_stack.svg/300px-Data_stack.svg.png" />
</p>

* 스택은 한 쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조(LIFO - Last In First Out)으로 되어 있다. 자료를 넣는 것을 '밀어넣는다' 하여 푸시(push)라고 하고 반대로 넣어둔 자료를 꺼내는 것을 팝(pop)이라고 하는데, 이때 꺼내지는 자료는 가장 최근에 보관한 자료부터 나오게 된다. 이처럼 나중에 넣은 값이 먼저 나오는 것을 LIFO 구조라고 한다.

* * *

#### # Queue (큐 구조)
큐(queue)는 컴퓨터의 기본적인 자료 구조의 한가지로, 먼저 집어 넣은 데이터가 먼저 나오는 FIFO (First In First Out)구조로 저장하는 형식을 말한다. 영어 단어 queue는 표를 사러 일렬로 늘어선 사람들로 이루어진 줄을 말하기도 하며, 먼저 줄을 선 사람이 먼저 나갈 수 있는 상황을 연상하면 된다. 나중에 집어 넣은 데이터가 먼저 나오는 스택과는 반대되는 개념이다.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/405px-Data_Queue.svg.png" />
</p>

* 프린터의 출력 처리나 윈도 시스템의 메시지 처리기, 프로세스 관리 등 데이터가 입력된 시간 순서대로 처리해야 할 필요가 있는 상황에 이용된다.

* * *

#### # Deque (덱 구조)
양쪽 끝에서 삽입과 삭제가 모두 가능한 자료 구조의 한 형태이다. 두 개의 포인터를 사용하여, 양쪽에서 삭제와 삽입을 발생 시킬 수 있다.

* 스크롤 (Scroll) - 입력이 한쪽 끝으로만 가능하도록 설정한 데크 (입력 제한 데크)
* 셸프 (Self) - 출력이 한쪽 끝으로만 가능하도록 설정한 데크 (출력 제한 데크)

<p align="center">
  <img src="http://image.hanb.co.kr/blog/7609/1245239894@stl_05_02.gif" />
</p>

##### ※ Deque Example
게임 서버는 클라이언트에서 보낸 패킷을 차례대로 처리합니다. 서버에서 네트워크 데이터를 받는 함수에서 데이터를 받으면 패킷으로 만든 후 받은 순서대로 순차적으로 처리합니다. 이렇게 **순차적으로 저장한 패킷을 처리할 때는 deque가 가장 적합한 자료구조**입니다. 다만, 실제 현업에서는 이 부분에 STL의 deque를 사용하지 않는 경우가 종종 있습니다. 이유는 네트워크에서 데이터를 받아 패킷으로 만들어 저장하고, 그 패킷을 처리하는 부분은 게임 서버의 성능 면에서 가장 중요한 부분이므로 deque보다 더 빠르게 처리하기를 원하므로 독자적인 자료구조를 만들어 사용합니다(즉, 범용성보다는 성능을 우선시합니다).

- 크기가 가변적이다.
- 앞과 뒤에서 삽입과 삭제가 좋다.
- 중간에 데이터 삽입, 삭제가 용이하지 않다.
- 구현이 쉽지 않다.
- 랜덤 한 접근이 가능하다.

* * *

#### # Circular Queue (환형 큐)
A circular buffer, circular queue, cyclic buffer or ring buffer is a data structure that uses a single, fixed-size buffer as if it were connected end-to-end. This structure lends itself easily to buffering data streams.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif" />
</p>

```c++
increment_address_one = (address + 1) % Length

decrement_address_one = (address + Length - 1) % Length
```

## ★ 비선형 구조

#### # Tree (트리 구조)
트리 구조(tree 構造, 문화어: 나무구조)란 그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 구조이다. 간단하게는 회로가 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/200px-Binary_tree.svg.png" />
</p>

* 트리에서 최상위 노드를 루트 노드(root node 뿌리 노드[*])라고 한다. 또한 노드 A가 노드 B를 가리킬 때 A를 B의 부모 노드(parent node), B를 A의 자식 노드(child node)라고 한다. 자식 노드가 없는 노드를 잎 노드(leaf node 리프 노드[*])라고 한다. 잎 노드가 아닌 노드를 내부 노드(internal node)라고 한다.

* * *

##### ※ B+ Tree

<p align="center">
 <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/37/Bplustree.png/1024px-Bplustree.png" width="300" height="200" />
</p>

* B+ 트리(Quaternary Tree라고도 알려져 있음)는 컴퓨터 과학용어로, **키에 의해서 각각 식별되는 레코드의 효율적인 삽입, 검색과 삭제를 통해 정렬된 데이터를 표현하기 위한 트리자료구조**의 일종이다. </br></br>이는 동적이며, 각각의 인덱스 세그먼트 (보통 블록 또는 노드라고 불리는) 내에 최대와 최소범위의 키의 개수를 가지는 다계층 인덱스(multilevel index)로 구성된다. </br></br>B트리와 대조적으로 B+트리는, 모든 레코드들이 트리의 가장 하위 레벨에 정렬되어있다. 오직 키들만이 내부 블록에 저장된다.

* The difference between a B and B+ tree is that, in a B-tree, the keys and data can be stored in both the internal and leaf nodes, whereas in a B+ tree, the data and keys can only be stored in the leaf nodes.

* A B+ tree is the same as a B tree; the only difference is that, in the B+ tree there is an additional level added at the bottom with linked leaves. Also, unlike the B tree, each node in a B+ tree contains only keys and not key–value pairs.

* * *

##### ※ 이진 트리(二進-, 영어: binary tree)
각각의 노드가 최대 두 개의 자식 노드를 가지는 트리 자료 구조로, 자식 노드를 각각 왼쪽 자식 노드와 오른쪽 자식 노드라고 한다. 단순히 집합론의 개념을 사용하는 재귀적 정의에서 (비어있지 않은) 이진 트리는 하나의 튜플 (L, S, R)로, L과 R은 이진 트리 또는 공집합이고 S는 싱글턴 집합이다. 일부 구현자는 공집합인 이진 트리도 허용한다.

## ★ Graph

#### # DFS (Depth First Serarch)
이 우선 탐색(depth-first search: DFS)은 맹목적 탐색방법의 하나로 탐색트리의 최근에 첨가된 노드를 선택하고, 이 노드에 적용 가능한 동작자 중 하나를 적용하여 트리에 다음 수준(level)의 한 개의 자식노드를 첨가하며, 첨가된 자식 노드가 목표노드일 때까지 앞의 자식 노드의 첨가 과정을 반복해 가는 방식이다.

<p align="center">
	<img src="https://static1.squarespace.com/static/559b400fe4b0dfcd52aea108/t/5898f99620099ed3b8b24601/1487544777373/new_dfs.gif?format=500w" />
</p>

|장점|단점|
|:--:|:--:|
|현 경로상의 노드들만을 기억하면 되므로 저장 공간의 수요가 비교적 적다.|해가 없는 경로에 깊이 빠질 가능성이 있다. 따라서 실제의 경우 미리 지정한 임의의 깊이까지만 탐색하고 목표노드를 발견하지 못하면 다음의 경로를 따라 탐색하는 방법이 유용할 수 있다.|
|목표노드가 깊은 단계에 있을 경우 해를 빨리 구할 수 있다.|얻어진 해가 최단 경로가 된다는 보장이 없다. 이는 목표에 이르는 경로가 다수인 문제에 대해 깊이우선 탐색은 해에 다다르면 탐색을 끝내버리므로, 이때 얻어진 해는 최적이 아닐 수도 있다.|

* * *

##### ※ Recalsive DFS Source Code
```C++
void recalsiveDFS(int index, int length) {
	isVisit[index] = true;
	cout << index << endl;

	for (int ii = 0; ii < length; ii++) {
		if (!isVisit[ii] && vertaxs[index][ii] == 1) { recalsiveDFS(ii, length); }
	}
}
```

* * *

##### ※ Stack DFS Source Code
```C++
void stackDFS(int index, int length) {
	
	stack<int> stx;

	stx.push(index);
	isVisit[index] = true;

	while (!stx.empty()) {
		
		const int box = stx.top(); stx.pop();

		for (int ii = 0; ii < length; ii++) {
			if (!isVisit[ii] && vertaxs[box][ii] == 1) {
				stx.push(ii);
				isVisit[ii] = true;
			}
		}

		// Output
		cout << box << endl;
	}
}
```

* * *

#### # BFS (Breadth First Search)

* * *

#### # Tree traversal (트리순회)

<p align="center">
 <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/67/Sorted_binary_tree.svg/250px-Sorted_binary_tree.svg.png" />
</p>

* 트리 구조에서 각각의 노드를 정확히 한 번만, 체계적인 방법으로 방문하는 과정을 말한다. 이는 노드를 방문하는 순서에 따라 분류된다.

```C++
typedef struct node {
	char value;
	struct node * reftChild;
	struct node * rightChild;

	node(const char val) {
		this->value = val;
		this->reftChild = NULL;
		this->rightChild = NULL;
	}
} Node;

```

###### § Preorder (전위순회) - 전위 순회는 깊이 우선 순회(depth-first traversal)라고도 한다.

001. 노드를 방문한다.
002. 왼쪽 서브 트리를 전위 순회한다.
003. 오른쪽 서브 트리를 전위 순회한다.

```C++
/* Result: F->B->A->D->C->E->G->I->H*/

void preOrder(Node * node) {
	if (node) {
		cout << "※ PreOrder: " << node->value << endl;
		preOrder(node->reftChild);
		preOrder(node->rightChild);
	}
}
```

###### § Inorder (중위순회)

001. 왼쪽 서브 트리를 중위 순회한다.
002. 노드를 방문한다.
003. 오른쪽 서브 트리를 중위 순회한다.

```C++
/* Result: Result: A->B->C->D->E->F->G->H->I */

void inOrder(Node * node) {
	if (node) {
		inOrder(node->reftChild);
		cout << "※ InOrder: " << node->value << endl;
		inOrder(node->rightChild);
	}
}
```

###### § Postorder (후위순회)

001. 왼쪽 서브 트리를 후위 순회한다.
002. 오른쪽 서브 트리를 후위 순회한다.
003. 노드를 방문한다.

```C++
/* Result: Result: A->C->E->D->B->H->I->G->F */

void postOrder(Node * node) {
	if (node) {
		postOrder(node->reftChild);
		postOrder(node->rightChild);
		cout << "※ PostOrder: " << node->value << endl;
	}
}
```

###### § Level-order (레벨 순서 순회)

* 레벨 순서 순회(level-order)는 모든 노드를 낮은 레벨부터 차례대로 순회한다. 
* 레벨 순서 순회는 너비 우선 순회(breadth-first traversal)라고도 한다.

```C++
/* Result: F-B-G-A-D-I-C-E-H */
void leverOrder(Node * node) {

	queue<Node*> que;
	que.push(node);

	while (!que.empty()) {

		Node * child = que.front();	que.pop();
		cout << "※ LevelOrder: " << child->value << endl;

		if (child->reftChild) { que.push(child->reftChild); }
		if (child->rightChild) { que.push(child->rightChild); }
	}
}
```

## ★ REFERENCE

✈️ [자료 구조 - 위키백과](https://ko.wikipedia.org/wiki/%EC%9E%90%EB%A3%8C_%EA%B5%AC%EC%A1%B0)

✈️ [Queue - 위키백과](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))

✈️ [Stack - 위키백과](https://ko.wikipedia.org/wiki/%EC%8A%A4%ED%83%9D)

✈️ [Deque - 위키백과](https://ko.wikipedia.org/wiki/%EB%8D%B1_(%EC%9E%90%EB%A3%8C_%EA%B5%AC%EC%A1%B0))

✈️ [About STL : C++ STL 프로그래밍(5)-덱(deque) : (1) - 한빛출판네트워크](http://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS3942847236)

✈️ [Circular buffer - 위키백과](https://en.wikipedia.org/wiki/Circular_buffer)

✈️ [깊이 우선 탐색 - 위키백과](https://ko.wikipedia.org/wiki/%EA%B9%8A%EC%9D%B4_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89)

✈️ [Depth-first Search (DFS) Maze Generation in GameMaker: Studio](https://www.zackbanack.com/blog/dfs)

✈️ [트리 순회(Tree traversal) - 위키백과](https://ko.wikipedia.org/wiki/%ED%8A%B8%EB%A6%AC_%EC%88%9C%ED%9A%8C)

✈️ [B+ Tree - 위키백과](https://en.wikipedia.org/wiki/B%2B_tree)

✈️ [B+ Tree - CS Animated](http://www.csanimated.com/animation.php?t=B-tree)

✈️ [Quick Sort - 위키백과](https://ko.wikipedia.org/wiki/%ED%80%B5_%EC%A0%95%EB%A0%AC)

## ★ Developer Information

|:rocket: Github QR Code|:pencil: Naver-Blog QR Code|:eyeglasses: Linked-In QR Code|
|:---------------------:|:-------------------------:|:----------------------------:|
|![](https://user-images.githubusercontent.com/20036523/50044128-60406880-00c2-11e9-8d57-ea1cb8e6b2a7.jpg)|![](https://user-images.githubusercontent.com/20036523/50044131-60d8ff00-00c2-11e9-818c-cf5ad97dc76e.jpg)|![](https://user-images.githubusercontent.com/20036523/50044130-60d8ff00-00c2-11e9-991a-107bffa2bf57.jpg)|
