#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace::std;

constexpr int N(2e4 + 4), M(2e5 + 5), inf{ 0x3f3f3f3f };
int n{}, s{}, t{}, tot{};
int v[M << 1]{}, w[M << 1]{}, first[N]{}, next[M << 1]{};
int h[N], e[N], gap[N << 1], inq[N];

struct cmp {
  inline bool operator()(int a, int b) const {
    return h[a] < h[b];
  }
};
queue<int> Q;
priority_queue<int, vector<int>, cmp> pQ;
inline void add_edge(int from, int to, int flow) {
  tot += 2;
  v[tot + 1] = from; v[tot] = to; w[tot] = flow; w[tot + 1] = 0;
  next[tot] = first[from]; first[from] = tot;
  next[tot + 1] = first[to]; first[to] = tot + 1;
  return;
}
inline bool bfs() {
  int now{};
  int go{};
  memset(h + 1, 0x3f, sizeof(int) * n);
  h[t] = 0; Q.push(t);
  while(!Q.empty()) {
    now = Q.front(); Q.pop();
    for (go = first[now]; go; go = next[go]) if (w[go ^ 1] && h[v[go]] > h[now] + 1) h[v[go]] = h[now] + 1, Q.push(v[go])