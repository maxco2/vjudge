#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <memory>
#include <stack>
#define MAXN 1000
#define FILL(container, value,size) std::fill(std::begin(container), std::end(container), value);
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
	int pre = -1;
	int d = -1;
	std::vector<int> links;
	ll wl;
	void reset() { visited = false; pre = -1; d = -1; }
};
std::vector<Vertex> unMap;

int center(int st, int ed)//center should more far from startnode
{
	if (st == ed) return st;
	vint v;
	v.push_back(ed);
	int pre = unMap[ed].pre;
	while (pre != st && pre != -1)
	{
		v.push_back(pre);
		pre = unMap[pre].pre;
	}
	if (pre == st) v.push_back(st);
	int res=v[(0 + v.size()) / 2];
	return res;
}

vector<bool> visited;

void insertEdge(int st,int ed)
{
	unMap[st ].links.push_back(ed );
	unMap[ed ].links.push_back(st );
}

int bfs(int pos,int& maxnode, bool resetAfterBFS = true)
{
	std::queue<int> q;
	q.push(pos);
	unMap[pos].d = 0;
	if (!resetAfterBFS)
		unMap[pos].visited = true;
	else
		visited[pos] = true;
	int maxd = 0;
	maxnode = pos;
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		for (auto i : unMap[pos].links)
		{
			if (resetAfterBFS)
			{
				if (!visited[i])
				{
					visited[i] = true;
					unMap[i].d = unMap[pos].d + 1;
					unMap[i].pre = pos;
					if (unMap[i].d > maxd)
					{
						maxd = unMap[i].d;
						maxnode = i;
					}
					q.push(i);
				}
			}
			else if (!unMap[i].visited)
			{
				unMap[i].visited = true;
				unMap[i].d = unMap[pos].d + 1;
				unMap[i].pre = pos;
				if (unMap[i].d > maxd)
				{
					maxd = unMap[i].d;
					maxnode = i;
				}
				q.push(i);
			}
		}
	}
	return maxd;
}

void resetBFSProp(int n)
{
	for (int j = 0; j < n; ++j)
	{
		if (visited[j])
		{
			unMap[j].reset();
			visited[j] = false;
		}
	}
}

void solve(int n)
{
	struct Info
	{
		int width = 0;
		int center = -1;
		int halfdia = 0;
		Info() {}
		Info(int w, int c, int h) :width(w), center(c), halfdia(h) {}
	};
	vector<Info> allInfo;
	auto genInfo = [](int i,int n)
	{
		//BFS1
		int maxnode = -1, maxnode2 = -1;
		bfs(i, maxnode);
		//bfs2
		resetBFSProp(n);
		int treewidth = bfs(maxnode, maxnode2, false);
		int curcenter = center(maxnode, maxnode2);
		int halfdia = std::max(unMap[curcenter].d, treewidth - unMap[curcenter].d);
		return Info{ treewidth,curcenter,halfdia };
	};
	for (int i = 0; i < n; ++i)
	{
		if (!unMap[i].visited)
		{
			Info tmp = genInfo(i,n);
			allInfo.emplace_back(tmp);
		}
	}
	
	if (allInfo.size() > 1)
	{
		auto sortInfo = [&allInfo]() {sort(allInfo.begin(), allInfo.end(), [](const Info& l, const Info& r) {return l.width < r.width; }); };
		int maxdia = 0;
		sortInfo();
		vector<pair<int,int>> allcenter;
		Info right = allInfo.back();
		allInfo.pop_back();
		while (!allInfo.empty())
		{
			Info left = allInfo.back();
			allInfo.pop_back();
			allcenter.push_back({ right.center,left.center });
			insertEdge(right.center, left.center);
			int maxnode = 0;
			int curHalfdia = bfs(right.center, maxnode);
			resetBFSProp(n);
			int maxnode2 = 0;
			int curWidth = bfs(maxnode, maxnode2);
			int curcenter = center(maxnode, maxnode2);
			resetBFSProp(n);
			curHalfdia = std::max(unMap[curcenter].d, curWidth - unMap[curcenter].d);
			allInfo.emplace_back( curWidth, curcenter, curHalfdia );
			sortInfo();
			right = allInfo.back();
			allInfo.pop_back();
		}

		cout << right.width << endl;
		for (auto& i : allcenter) cout << i.first+1 << " " << i.second+1 << endl;
		
	}
	else
	{
		cout << allInfo[0].width << endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n,m;
	cin >> n>>m;
	unMap = vector<Vertex>(n);
	visited = vector<bool>(n,false);
	for (int i = 0; i < m; ++i)
	{
		int st, ed;
		cin >> st >> ed;
		unMap[st - 1].links.push_back(ed - 1);
		unMap[ed - 1].links.push_back(st - 1);
	}
	solve(n);
}
