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
using ull = unsigned long long;
using vint = vector<int>;
using mii = map<int, int>;
template <typename T>
using uptr = unique_ptr<T>;

struct Vertex
{
	bool visited = false;
	int pre = -1;
	int d = -1;
	std::vector<int> links;
	bool tryOdd = false;
	void reset() { visited = false; pre = -1; d = -1; tryOdd = false; }
};
std::vector<Vertex> unMap;

void insertEdge(int st, int ed)
{
	unMap[st].links.push_back(ed);
	unMap[ed].links.push_back(st);
}

constexpr ull mod = 998244353;
bool bfs(int pos, ull &sum)
{
	std::queue<int> q;
	q.push(pos);
	ull sum1 = 1;
	ull sum2 = 1;
	auto addSum = [&sum1, &sum2](bool tryOdd) {
		if (tryOdd)
		{
			sum1 *= 2;
			sum2 *= 1;
		}
		else
		{
			sum2 *= 2;
			sum1 *= 1;
		}
		sum1 %= mod;
		sum2 %= mod;
	};
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		unMap[pos].visited = true;
		addSum(unMap[pos].tryOdd);
		for (auto i : unMap[pos].links)
		{
			if (!unMap[i].visited)
			{
				unMap[i].visited = true;
				unMap[i].tryOdd = !unMap[pos].tryOdd;
				q.push(i);
			}
			else
			{
				if (unMap[pos].tryOdd == unMap[i].tryOdd)
					return false;
			}
		}
	}
	sum = (sum1 + sum2) % mod;
	return true;
}

ull solve(int vsize)
{
	if (vsize == 1)
		return 3;
	ull sum = 1;
	for (int i = 0; i < vsize; ++i)
		unMap[i].reset();
	for (int i = 0; i < vsize; ++i)
	{
		if (!unMap[i].visited)
		{
			ull tmpSum = 0;
			bool res = bfs(i, tmpSum);
			if (res) {
				sum *= tmpSum; sum %= mod;
			}
			else return 0;
		}
	}
	return sum % mod;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG

	int n;
	cin >> n;
	for (int test = 0; test < n; ++test)
	{
		int vsize;
		int esize;
		cin >> vsize >> esize;
		unMap = vector<Vertex>(vsize);
		for (int i = 0; i < esize; ++i)
		{
			int st, ed;
			cin >> st >> ed;
			insertEdge(st - 1, ed - 1);
		}
		cout << solve(vsize) << endl;
	}
}
