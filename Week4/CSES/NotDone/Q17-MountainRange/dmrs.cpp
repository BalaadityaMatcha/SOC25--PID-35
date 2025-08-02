#include<bits/stdc++.h>
#define ain(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define F first
#define S second
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin>>n;
    int a[n];
    ain(a,n)
    stack<pair<int,int>> st;
    int answer=1;
    st.push({a[0],1});
    for(int i=1;i<n;i++)
    {
        int removed=-1;
        if(st.top().F<a[i])
        {
            while(!st.empty() && st.top().F<a[i])
            {
                removed=max(removed,st.top().S);
                st.pop();
            }
        }
        if(removed>0)
        {
            if(st.empty() || st.top().F>a[i])
            {
                answer=max(answer,removed+1);
                st.push({a[i],removed+1});
            }
            else
            {
                removed=max(removed,st.top().S);
                st.pop();
                answer=max(answer,removed);
                st.push({a[i],removed});
            }
        }
        else if(st.top().F>a[i])
        {
            answer=max(answer,int(st.size())+1);
            st.push({a[i],st.size()+1});
        }
    }
    cout<<answer<<endl;
}