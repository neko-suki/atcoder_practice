#include<iostream>
#include <climits>
#include<cstdio>
using namespace std;

const int MAX = 2 * 100000;
long long count=0;
int a[MAX];


void Merge(int a[],int l,int mid,int r){
  int n1 = mid - l+1,n2 = r-mid;
  int L[n1+1],R[n2+1];
  for(int i=0;i<n1;i++){
    L[i]=a[l+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=a[mid+i+1];
  }
  L[n1]=R[n2]=INT_MAX;
  int pr =0,pl = 0;
  for(int i=l;i<r+1;i++){
    if ( L[pl] <= R[pr]){
      a[i]=L[pl++];
    }
    else if (L[pl]>R[pr]){
      ::count+=n1-pl;
      //cout << R[pr] << endl;
      a[i]=R[pr++];
    }
  }
  
}

void MergeSort(int a[],int l,int r){
  if (l < r){
    int q = (r+l)/2;
    MergeSort(a,l,q);
    MergeSort(a,q+1,r);
    Merge(a,l,q,r);
  }

}

int main(){
  string in;
  cin >> in;
  int n = in.size();
  ::count = 0;
  for(int i = 0;i < n;i++){
    if (in[i] == 'W'){
      a[i] = 0;
    } else if (in[i] == 'B'){
      a[i] = 1;
    }
  }
  MergeSort(a, 0, n-1);
  cout << ::count << endl;
}


/*
int main(){
  string in;
  cin >> in;
  int n = in.size();
  long long ans=  0;
  int bcnt = 0;
  for(int i = 0;i < n;i++){
    if (in[i] == 'W'){
      ans += bcnt;
    } else if (in[i] == 'B'){
      bcnt++;
    }
  }
  cout << ans << endl;
}
*/
