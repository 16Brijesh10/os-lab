#include<stdio.h>
//#include<conio.h>
#include<math.h>
int main()
{
int i,j,sum=0,c=0,n,st,temp,t,s;
int a[20],b[20],dd[20];
//clrscr();
do
{
printf("\nEnter the block number between 0 and 200: ");
scanf("%d",&st);
}while((st>=200)||(st<0));
printf("\nOur disk head is on the %d block",st);
a[0]=st;
printf("\nEnter the no. of request: ");
scanf("%d",&n);
printf("\nEnter request: ");
for(i=1;i<=n;i++)
{
printf("\nEnter %d request: ",i);
scanf("%d",&a[i]);
do{
if((a[i]>200)||(a[i]<0))
{
printf("\nBlock number must be between 0 and 200!");
}}while((a[i]>200)||(a[i]<0));
}
for(i=0;i<=n;i++)
dd[i]=a[i];
s=a[0];
for(i=0;i<=n;i++)
for(j=i+1;j<=n;j++)
if(dd[i]>dd[j])
{
temp=dd[i];
dd[i]=dd[j];
dd[j]=temp;
}
for(i=0;i<=n;i++)
{
if(s==dd[i])
{
b[c]=st;
for(j=i+1;j<=n;j++)   //for(j=i-1;j>0;j--)
b[++c]=dd[j];
//b[++c]=200;
for(j=i-1;j>=0;j--)   //for(j=i+1;j<=n;j++)
b[++c]=dd[j];
}}
printf("\n\t\tLOOK TECHNIQUE: ");
printf("\nDISK QUEUE:");
for(i=0;i<=n;i++)
printf("\t%d",a[i]);
printf("\n\nACCESS ORDER:");
for(i=0;i<=c;i++)
{
printf("\t%d",b[i]);
if(i!=c)
sum+=abs(b[i]-b[i+1]);
}
printf("\n\nTotal no. of head movements: %d",sum);
return 0;
//getch();
}