#include <iostream>
#include<vector>
#include <fstream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,max_height=1,x;
    vector<int>node;

    cin >> n;
    node.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> node[i];
    }
    for(int i=0; i<n; i++)
    {
        int height=1;
        x=node[i];
        while(x!=-1)
        {
            height++;
            x=node[x];
        }
        max_height=max(max_height,height);
    }
cout<<max_height;
    return 0;
}
