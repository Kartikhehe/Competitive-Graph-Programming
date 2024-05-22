//Binary Cut problem codeforces
//Link: https://codeforces.com/contest/1971/problem/D



#include <bits/stdc++.h>
using namespace std;


int main() {


    int n;
    cin>>n;

    for(int j=0;j<n;j++){
        string str;
        cin>>str;
        int check =0;
        int answer = 1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0' && str[i+1]=='1'){
                check =1;
            }

            if(i!=0 && str[i]!= str[i-1]){
                answer++;
            }


            
        }cout<<answer-check<<endl;

    }
    

    
    return 0;
}
