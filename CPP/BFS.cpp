#include<bits/stdc++.h>
using namespace std;
int temp[1000];
int bucket[10];
int maxBit(int data[],int n)
{
   int maxData=data[0];
   for(int i=1;i<n;i++)
   {
      if(data[i]>maxData)
         maxData=data[i];
   }
   int d=1;
   while(maxData>0)
   {
      maxData/=10;
      d++;
   }
   return d;
}
void radixsort(int data[],int n)
{
   int d=maxBit(data,n);
   int i,j,k;
   int radix=1;
   for(i=1;i<=d;i++)
   {
      for(j=0;j<10;j++)
      bucket[j]=0;
      for(j=0;j<n;j++)
      {
         k=(data[j]/radix)%10;
         bucket[k]++;
      }
      for(j=1;j<10;j++)
      bucket[j]=bucket[j-1]+bucket[j];
      for(j=n-1;j>=0;j--)
      {
         k=(data[j]/radix)%10;
         temp[bucket[k]-1]=data[j];
         bucket[k]--;
      }
      for(j=0;j<n;j++)
      data[j]=temp[j];
      radix=radix*10;
   }
}
int main()
{
   int data[1000];
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   cin>>data[i];
   radixsort(data,n);
   for(int i=0;i<n;i++)
   cout<<data[i]<<" ";
   cout<<endl;
   return 0;
}