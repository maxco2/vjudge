#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cassert>
#define NDEBUG
//#include "catch.hpp"

using namespace std; 
#define MAXL 505
typedef long long num;
num table[MAXL];
num parent[MAXL];
void LCIS(num arr1[], int n, num arr2[], int m) 
{ 
    memset(table,0,sizeof(table));
    memset(parent,-1,sizeof(parent));
    for (int i=0; i<n; i++) 
    { 
        num current = 0, last = -1; 
        for (int j=0; j<m; j++) 
        { 
            if (arr1[i] == arr2[j]
                    &&current + 1 > table[j]) 
                table[j] = current + 1,parent[j] = last; 
            if (arr1[i] > arr2[j] 
                    &&table[j] > current) 
                current = table[j],last = j; 
        } 
    } 
    num* pos=max_element(table,table+m);
    num idx=pos-table;
    num result=*pos;
    cout<<result<<endl;
    if(result>0)
    {
        vector<num> lcis;
        for (num i=0; idx!= -1; i++) 
        { 
            lcis.push_back(arr2[idx]);
            idx = parent[idx]; 
        } 
	assert(lcis.size()==result);
        for (num i=result-1; i!=0; i--) 
            cout<<lcis[i]<<" ";
        cout<<lcis[0];
    }
        cout<<endl;
} 
num arr1[MAXL];
num arr2[MAXL];
int main() 
{ 
    int n1,n2;
    cin >> n1;
    for (int i = 0; i < n1; ++i)
        cin >> arr1[i];
    cin >> n2;
    for (int i = 0; i < n2; ++i)
        cin >> arr2[i];
    LCIS(arr1, n1, arr2, n2); 
    return 0; 
} 
