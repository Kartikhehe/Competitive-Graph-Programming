// assignment 2
//Problem Link: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/chocolate-stack-746c1b56/?purpose=login&source=problem-page&update=google

#include<bits/stdc++.h>
using namespace std;
vector<int> solution (int N, vector<int> C) {
    vector<int> answer;
    vector<int> temp;
    for(int i=0;i<N;i++){
        if(C[i]==0 &&  temp.empty()==false){
            answer.push_back(*(temp.end()-1));
            temp.pop_back();
        }else{
            temp.push_back(C[i]);
        }
    }return answer;
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> C(N);
    for(int i_C = 0; i_C < N; i_C++)
    {
    	cin >> C[i_C];
    }

    vector<int> out_;
    out_ = solution(N, C);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}