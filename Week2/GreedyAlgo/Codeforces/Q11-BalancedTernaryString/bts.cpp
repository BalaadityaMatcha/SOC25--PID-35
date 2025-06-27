#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    vi freq(3);string s;
    cin >> s;
    for(int i=0;i<n;i++){
        freq[s[i]-'0']++;
    }
    if(freq[0]==freq[1] && freq[1]==freq[2]){cout << s;return 0;}
    else{
        int a=0;
        while((freq[0]!=freq[1] || freq[1]!=freq[2]) && a<n){
            int dig = s[a]-'0';
            if(freq[dig] > n/3){
                for(int i=0;i<3;i++){
                    if(freq[i]<n/3 && dig > i){s[a]=i+'0';freq[i]++;freq[dig]--;break;}
                }
            }
            a++;
        }
        if(a==n){
            a--;
            while((freq[0]!=freq[1] || freq[1]!=freq[2]) && a<n){
                int dig = s[a]-'0';
                if(freq[dig] > n/3){
                    for(int i=2;i>=0;i--){
                        if(freq[i]<n/3 && dig < i){s[a]=i+'0';freq[i]++;freq[dig]--;break;}
                    }
                }
                a--;
            }
        }

        cout << s;
    }

    return 0;
}