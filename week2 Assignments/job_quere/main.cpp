#include<bits/stdc++.h>
#include <fstream>
using namespace std;
typedef pair<long long int, int> pi;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    priority_queue<pi, vector<pi>, greater<pi> > threads;
    int n,m,x;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        threads.push(make_pair(0,i));
    }
    for(int i=0; i<m; i++)
    {
        cin>>x;
        pi p=threads.top();
        threads.pop();
        cout<<p.second<<" "<<p.first<<endl;
        threads.push(make_pair(p.first+x,p.second));
    }
    return 0;
}
