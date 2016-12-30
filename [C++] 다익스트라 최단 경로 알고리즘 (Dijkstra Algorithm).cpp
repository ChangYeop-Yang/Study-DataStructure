/* Function */
vector<int> dijkstra(int src, int V) /* V - 정점의 갯수, src - 출발점 */
{
	/* Vector */
	vector<int> dist(V, INF); /* 최단 거리 값 Vector */
	dist[src] = 0;

	/* Queue */
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty())
	{
		/* Integer */
		int cost = -pq.top().first;
		int here = pq.top().second; pq.pop();

		/* 만약 지금 꺼낸 값보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시 */
		if (dist[here] < cost) { continue; }

		/* 인전합 정점 모두 검사 */
		int mSize = adj[here].size();
		for (int ii = 0; ii < mSize; ii++)
		{
			int there = adj[here][ii].first; /* 연결된 정점 번호 */
			int nextDist = cost + adj[here][ii].second; /* 비용 + 현 리스트의 간선 가중치 */

			/* 더 짧은 경로를 발견할 경우 큐와 최단 거리 Vector를 갱신 */
			if (dist[there] > nextDist) { dist[there] = nextDist; pq.push(make_pair(-nextDist, there)); }
		}
	}

	return dist;
}

/* Function */
vector<int> dijkstra(int src, int V) /* V - 정점의 갯수, src - 출발점 */
{
	/* Vector */
	vector<int> dist(V, INF); /* 최단 거리 값 Vector */
	vector<bool> visited(V, false); /* 각 정점 방문 여부 확인 Vector */

	/* 시작점의 값 저장과 방문 표시 */
	dist[src] = 0; visited[src] = true;
	
	/* 아직 방문하지 않은 정점 중 가장 가까운 정점을 찾을 때 까지 반복 */
	while (true)
	{
		/* Integer */
		int closest = INF, here = 0;

		for (int ii = 0; ii < V; ii++)
		{
			/* 해당 번째의 가중치 값이 작거나 방문하지 않은 경우 */
			if ((dist[ii] < closest) && !visited[ii]) { here = ii; closest = dist[ii]; }
		}

		if (closest == INF)
		{	break;	}

		/* 가장 가까운 정점 방문 */
		visited[here] = true; /* 현재 노드 방문 표시 */
		
		int mSize = adj[here].size(); /* 현재 노드의 연결 된 인접 리스트의 길이 */
		for (int ii = 0; ii < mSize; ii++)
		{
			int there = adj[here][ii].first; /* 연결된 정점 번호 */
			
			/* 해당 리스트를 방문을 했을 경우 건너뛴다. */
			if (visited[there]) { continue; } 

			int nextDist = dist[here] + adj[here][ii].second; /* 최단 거리 값 + 간선 가중치 */
			dist[there] = min(dist[there], nextDist); /* 최단 거리와 다음 최단 거리 값 중 작은 것을 통해 갱신 */
		}
	}

	return dist;
}
