#include <iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

vector<int>parent;
vector<long long int>rnk;
long long int mx=0;
int Find(int i)
{
   if(i!=parent[i])
        parent[i]=Find(parent[i]);
    return parent[i];
}
void Union(int d,int s)
{
    int i_s =Find(s);
    int i_d =Find(d);
    if(i_s==i_d)
        return;
    parent[i_s]=i_d;
    rnk[i_d]+=rnk[i_s];
    rnk[i_s]=0;
    if(mx < rnk[i_d])
        mx=rnk[i_d];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,row,s,d;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>row;
        parent.push_back(i);
        rnk.push_back(row);
        if(row > mx)
            mx=row;
    }
    for(int i=0; i<m; i++)
    {
        cin>>d>>s;
        Union(d-1,s-1);
        cout<<mx<<"\n";

    }

    return 0;
}
