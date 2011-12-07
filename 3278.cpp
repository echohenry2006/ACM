#include<iostream>
#include<queue>
#include<memory.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int color[200000];
int dis[200000];
queue<int> q1;
int t;
int bfs(int n ,int k)
{
    if(n>=k)
        return n-k;
    color[n]=GRAY;
    q1.push(n);
    while(!q1.empty())
    {
        int s=q1.front();
        q1.pop();
        //s-1
        t=s-1;
        if(t>=0 && color[t]==WHITE)
        {
            color[t]=GRAY;
            dis[t]=dis[s]+1;
            if(t==k)
            {

                return dis[t];
            }
            else
            {
                q1.push(t);

            }
        }

        //s+1
        t=s+1;
        if(t<=100000 && color[t]==WHITE)
        {
            color[t]=GRAY;
            dis[t]=dis[s]+1;
            if(t==k)
            {

                return dis[t];
            }
            else
            {
                q1.push(t);

            }

        }

        //s*2
        t=s*2;
        if(t<=100000 && color[t]==WHITE)
        {
            color[t]=GRAY;
            dis[t]=dis[s]+1;
            if(t==k)
            {

                return dis[t];
            }
            else
            {
                q1.push(t);

            }
        }

        color[s]=BLACK;




    }




}

int main()
{
    int n,k;  //n--farmer john ;k---cow
    cin >> n >> k;

    memset(color,WHITE,sizeof(color));
    memset(dis,0,sizeof(dis));

    cout << bfs(n,k) << endl;
    return 0;
}
