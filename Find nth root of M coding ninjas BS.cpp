//Find Nth root of M
// Coding Ninjas - Binary Search
//Link: https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

int expo(int i,int n,int m){
  long long answer=1;
  for(int k=0;k<n;k++){
      answer*=i;
      
      if(answer>m){return 1;}
  }if(answer==m){return 0;}
  return -1;
}


int NthRoot(int n, int m) {
  // Write your code here.
  int low=1,high=m;
  while(low<=high){
    int mid=(low+high)/2;
    if(expo(mid,n,m)==0){return mid;}
    else if(expo(mid,n,m)==1){high=mid-1;}
    else low=mid+1;
  }return -1;
}
