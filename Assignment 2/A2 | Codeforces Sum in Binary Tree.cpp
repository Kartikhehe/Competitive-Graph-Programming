//Assignment 2
//Sum in Binary Tree
//Problem Link: https://codeforces.com/problemset/problem/1843/C?csrf_token=7a339062a5a56389e6c8fff105390cb2

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin>> n;
    for (int i=0;i<n;i++){
        long long int x;
        cin>>x;
        long long int sum=0;
        while(x!=0){
            sum+=x;
            x/=2;
        }cout<<sum<<endl;
    }
    return 0;
}