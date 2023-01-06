#include <stdio.h>

int part(int a[],int l,int h)
{
  int pivot=a[h];
  int temp,i,j=l-1;
  for(i=l;i<=h-1;i++)
    {
      if (a[i]<=pivot)
      {
        j++;
        temp=a[j];
        a[j]=a[i];
        a[i]= temp;
      }
    }
  temp=a[j+1];
  a[j+1]=a[h];
  a[h]=temp;
  return j+1;
}
void quicksort(int a[],int l,int h)
{
  if (l<h){
    
  
int pp = part(a,l,h);
  quicksort(a,l,pp-1);
  quicksort(a,pp+1,h);
    }
}

int main(void) {
  int a[]={10,3,9,2,7,12,15,6};
 int n=sizeof(a)/sizeof(a[0]);
  quicksort(a,0,n-1);
  for(int i=0;i<n;i++){
    printf("%d \t",a[i]);
  }
  
  
    
}