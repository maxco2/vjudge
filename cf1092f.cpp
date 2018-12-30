#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define FILL(n, value) std::fill(std::begin(n), std::end(n), value)
using namespace std;
struct Vertex
{
    int w=0;
    bool visited=false;
    std::vector<int> links;
    void reset(){visited=false;}
};
std::vector<Vertex> map;

void dfs(int pos,int &sum,int dist)
{
    sum+=map[pos].w*dist;
    map[pos].visited=true;
    for(auto i:map[pos].links)
    if(!map[i].visited)
    dfs(i,sum,dist+1);
}

int main()
{
    int maxsum=0;
    int n;
    cin >> n;
    map.resize(n);
    for (int i = 0; i < n; ++i)
        {
            cin >> map[i].w;
        }
    for (int i = 0; i < n - 1; ++i)
        {
            int st, ed;
            cin >> st >> ed;
            map[st - 1].links.push_back(ed-1);
            map[ed-1].links.push_back(st-1);
        }
    for (int i = 0; i < n; ++i)
        {
            for(auto& i:map) i.reset();
            int sum = 0;
            dfs(i, sum, 0);
            maxsum = sum > maxsum ? sum : maxsum;
        }
    cout << maxsum << endl;
}
