// O(nlogn)

#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

/* Let's try a tree that stores the max element on its left as it's left child
   Other as the max element on its right till its parent if its on right
*/
class tree
{
    private:
        int value,index; // of current node
        tree* left=nullptr;tree* right=nullptr;
    public:
        // constructor
        tree(int val,int ind){
            this->value = val;
            this->index = ind;
        }
        int top(){
            // return data[0].first;
            return value;
        }
        /*int pop(){    // since i wont be using pop in my code,im not writing it
            int temp = data[0].first;
            data.erase(data.begin());
            return temp;
            
        }*/
        void push(int val,int ind){
            if(val > value){
                tree* old = new tree(value, index);
                old->left = this->left;
                old->right = this->right;
                this->left = old;
                this->right = nullptr;
                this->value = val;
                this->index = ind;
            }
            else{
                if(this->right) this->right->push(val,ind);
                else{
                    tree* r = new tree(val,ind);
                    this->right = r;
                }
            }
        }

        void add(int val,int ind){
            if(val > value){
                int temp_val = value,temp_ind = index;
                value = val;index = ind;
                if(index > temp_ind){
                    if(left == nullptr){
                        left = new tree(temp_val,temp_ind);  
                    }
                    else left->add(temp_val,temp_ind);
                }
                else{
                    if(right == nullptr){
                        right = new tree(temp_val,temp_ind);
                    }
                    else right->add(temp_val,temp_ind);
                }
            }
            else{
                if(index > ind){
                    if(left == nullptr){
                        left = new tree(val,ind);
                    }
                    else left->add(val,ind);
                }
                else{
                    if(right == nullptr){
                        right = new tree(val,ind);
                    }
                    else right->add(val,ind);
                }
            }
        }
        int depth(){
            int leftDepth = left ? left->depth() : 0;
            int rightDepth = right ? right->depth() : 0;
            return 1 + max(leftDepth,rightDepth);
        }
};

//Your function here
int maxmountains(const vi& h,int posn,bool direction,int lb,int ub){
    int cnt = 1;
    if(direction){
        auto max_it = max_element(h.begin()+posn+1,h.begin()+ub);
        int new_posn = max_it - h.begin();
        if(new_posn >= ub) return 0; // i.e, if posn+1 = ub i.e, new_posn = ub-1 in previous level
        cnt+=max(maxmountains(h,new_posn,false,posn+1,new_posn),maxmountains(h,new_posn,true,new_posn,ub));
    }
    else{
        auto max_it = max_element(h.begin()+lb,h.begin()+posn);
        int new_posn = max_it - h.begin();
        if(new_posn >= posn) return 0; // i.e, if posn = lb ,i.e, new_posn = lb in previous level
        cnt+=max(maxmountains(h,new_posn,false,lb,new_posn),maxmountains(h,new_posn,true,new_posn,posn));
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin >> n;
    /*vi h(n);in(h,n)
    cout << maxmountains(h,-1,1,0,n);*/
    // lets try for O(nlogn) using Tree
    int f;cin >> f;
    tree q(f,0);
    for(int i=1;i<n;i++){
        int x;cin>>x;q.push(x,i);
    }
    cout << q.depth();
    return 0;
}