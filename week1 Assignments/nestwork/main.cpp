#include <iostream>
#include<vector>
#include<queue>
#include <fstream>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    vector<int>time;
    queue<int>packets;
    int s,t,finish,a,p,start;
    cin>>s>>t;
    for(int i=0; i<t; i++)
    {
        cin>>a>>p;
        if(!packets.empty() && a>=packets.front())
        {
            packets.pop();
        }
        if(packets.size()<s)
        {
            if(packets.empty())
                start=a;
            else
                start=packets.back();
            packets.push(max(start,a)+p);
            time.push_back(max(start,a));
        }
        else
            time.push_back(-1);

    }
    for(int i=0;i<t; i++)
    {
        cout<<time[i]<<"\n";
    }
    return 0;
}
