//Codeforces problem
//link: https://codeforces.com/contest/1476/problem/A
//K -divisible sum
#include <iostream>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++){
        int n,k;
        cin>>n;
        cin>>k;
        if(n==k){cout<<"1"<<endl;}
        else if(n<k){
            if(k%n==0){
                cout<<k/n<<endl;
            }
            else{cout<<k/n + 1<<endl; }
        }else{
            if(n%k==0){cout<<"1"<<endl;}
            else{
            int temp = (n/k +1) * k;
            if(temp == n){
                cout<<"1"<<endl; 
            }else{cout<<"2"<<endl; }}
        }

    }


    
    return 0;
}