#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <memory>
#include <stack>
#define MAXN 200000
#define FILL_RESIZE(container, value,size) std::fill(std::begin(container), std::end(container), value);\
container.resize(size)
using namespace std;
using ll = long long;
using vint = vector<int>;
using mii = map<int, int>;
template <typename T>
using uptr = unique_ptr<T>;

struct Vertex
{
	ll w = 0;
	bool visited = false;
	std::vector<int> links;
	ll wl;
	void reset() { visited = false; }
};
std::vector<Vertex> tree;

vint fa;
vector<ll> curAllWeights;
ll maxWL = 0;
void dfs1(int pos, int father, int depth)
{
	fa[pos] = father;
	tree[pos].wl += tree[pos].w * depth;
	curAllWeights[pos] += tree[pos].w;
	tree[pos].visited = true;
	for (auto i : tree[pos].links)
		if (!tree[i].visited)
		{
			dfs1(i, pos, depth + 1);
			tree[pos].wl += tree[i].wl;
			curAllWeights[pos] += curAllWeights[i];
		}
}

void dfs2(int pos, ll fatherSum, int n)
{
	ll curSum = 0;
	int father = fa[pos];
	if (father == -1)
	{
		curSum = maxWL = tree[pos].wl;
	}
	else
	{
		curSum =
			fatherSum + (curAllWeights[0] - curAllWeights[pos]) - (curAllWeights[pos]);
		maxWL = max(curSum, maxWL);
	}
	tree[pos].visited = true;
	for (auto i : tree[pos].links)
		if (!tree[i].visited)
		{
			dfs2(i, curSum, n);
		}
}

int main()
{
	int n;
	cin >> n;
	tree = vector<Vertex>(n);
	fa = vint(n, -1);
	curAllWeights = vector<ll>(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> tree[i].w;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int st, ed;
		cin >> st >> ed;
		tree[st - 1].links.push_back(ed - 1);
		tree[ed - 1].links.push_back(st - 1);
	}
	dfs1(0, -1, 0);
	for (int i = 0; i < n; ++i) tree[i].reset();
	dfs2(0, 0, n);
	cout << maxWL << endl;
}
