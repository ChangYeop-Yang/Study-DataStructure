/* Trie의 각 노드들은 MAX_LEN 만큼의 자식노드들을 가질 수 있다. */
#define MAX_LEN 26
#define TO_NUMBER(X) X - 'A'

/* Trie의 하나의 노드를 나타내는 객체 */
typedef struct TrieNode {

	/* 해당 노드가 종료 노드인지 확인하는 변수 */
	bool terminal = false;
	TrieNode * children[MAX_LEN];

	TrieNode() { memset(children, 0, sizeof(children)); }

	~TrieNode() {
		for (int index = 0; index < MAX_LEN; index++) {
			if (children[index]) { delete children[index]; }
		}
	}

	/* 이 노드를 루트로 하는 Trie에 문자열 Key를 추가한다. */
	void insert(const char * key) {

		// 문자열이 끝나면 종료 노드임을 표시
		if (*key == 0) { terminal = true; }
		else {
			const int next = TO_NUMBER(*key);

			// 해당 자식 노드가 없으면 생성한다.
			if (children[next] == NULL) { children[next] = new TrieNode(); }
			children[next]->insert(key + 1); // 해당 자식 노드를 재귀로 호출한다.
		}
	}

	/* 이 노드를 루트로 하는 Trie에 문자열 Key와 대응되는 노드를 찾고 없는경우 NULL을 반환한다. */
	TrieNode* find(const char * key) {
		if (*key == 0) { return this; }
		
		const int next = TO_NUMBER(*key);
		if (children[next] == NULL) { return NULL; } // 문자열 Key와 대응되는 노드를 찾기 못한 경우
		return children[next]->find(key + 1); // 문자열 Key와 대응되는 노드를 찾은 경우
	}
} Trie;

void printWord(string & contents, const Trie * node) {

	if (node->terminal) { cout << contents << endl; return; }

	for (int ii = 0; ii < MAX_LEN; ii++) {
		if (node->children[ii]) {
			contents.push_back(ii + 'A');
			printWord(contents, node->children[ii]);
			contents.pop_back();
		}
	}
}
