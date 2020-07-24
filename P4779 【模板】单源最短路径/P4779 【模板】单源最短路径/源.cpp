#include <iostream>
#include <queue>
#include <vector>

#define MAXN 100001

using namespace::std;

int n = 0, m = 0, s = 0;

struct Edge
{
	int to;
	int dis;
	int next;
	Edge(int v, int w, int u) : to(v), dis(w), next(u) {};
	Edge() : to(0), dis(0), next(0) {};
};

vector<Edge> vedge(1);
int head[MAXN] = { 0 };

void add_edge(int u, int v, int w)
{
	vedge.push_back(Edge(v, w, head[u]));
	head[u] = vedge.size() - 1;
}

struct Node
{
	int poi;
	int dis;
	Node(int p, int d) : poi(p), dis(d) {};
	bool operator>(const Node n) const{ return dis > n.dis; };
};
bool cmp_Node(Node n, Node n2) { return n.dis > n2.dis; };

priority_queue<Node, vector<Node>, greater<Node>> que;
vector<int> arrd;
bool ab1[MAXN] = { false };

void dijkstra(int sta)
{
	arrd[sta] = 0;
	que.push(Node(sta, 0));
	while (!que.empty())
	{
		Node thn = que.top();
		que.pop();
		if (ab1[thn.poi])
			continue;
		ab1[thn.poi] = true;
		for (auto i1 = head[thn.poi]; i1; i1 = vedge[i1].next)
			if (arrd[vedge[i1].to] > arrd[thn.poi] + vedge[i1].dis)
			{
				arrd[vedge[i1].to] = arrd[thn.poi] + vedge[i1].dis;
				que.push(Node(vedge[i1].to, arrd[vedge[i1].to]));
			}
	}
}

int main()
{
	cin >> n >> m >> s;
	arrd.resize(n + 1);
	for (auto& i1 : arrd)
		i1 = 0x7fffffff;
	int u, v, d;
	for (auto i1 = 0; i1 < m; i1++)
	{
		cin >> u >> v >> d;
		add_edge(u, v, d);
	}
	dijkstra(s);
	for (auto i1 = arrd.begin() + 1; i1 < arrd.end(); i1++)
		cout << *i1 << ' ';
	return 0;
}