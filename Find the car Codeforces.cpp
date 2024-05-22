//Codeforces problem
//Find the Car
//link: https://codeforces.com/contest/1971/problem/E


#include <bits/stdc++.h>
using namespace std;


int main() {


    int num;
    cin>>num;

    for(int j=0;j<num;j++){
        
        int n, k, q;
        cin>>n>>k>>q;
        int Ai[k];
        for(int i=0;i<k;i++){
            cin>>Ai[i];
        }int Bi[k];
        for(int i=0;i<k;i++){
            cin>>Bi[i];
        }
        int Qi[q];

        for(int i=0;i<q;i++){
            cin>>Qi[i];
        }

        float speed[k];
        speed[0] = float(Ai[0])/Bi[0];
        //cout<<Qi[0]<<endl;
        
        if (k>1){
        for(int i=1;i<k;i++){
            speed[i] = float(Ai[i]-Ai[i-1])/(Bi[i]-Bi[i-1]);
            //cout<<speed[i]<<endl;
        }}

            for(int i=0;i<q;i++){
                int temp = Qi[i];
                int time = 0;
                int z=0;

                while(temp>=Ai[z]){
                    time = Bi[z];
                    z++;
                    
                    
                }if(z>0){
                time+= int((temp-Ai[z-1])/speed[z]);}
                if(z==0){
                    time= int(float(temp)/speed[0]);
                }
                cout<<time<<" ";

            
            }cout<<endl;

        
        
    }
    

    
    return 0;
}
