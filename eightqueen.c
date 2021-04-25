#include<stdio.h>
#include<math.h>
 
int board[100],count;

void queen(int row,int n);
void print(int n);
int place(int row,int column);

int main()
{
 int n,i,j;
 
 printf(" - N Queens Problem Using Backtracking -\n");
 printf("Enter number of Queens:");
 scanf("%d",&n);
 queen(1,n);
 return 0;
}
 
//印出解
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 
 for(i=1;i<=n;++i)
  printf("\t%d",i);
 
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) 
  {
   if(board[i]==j)
    printf("\tQ"); 
   else
    printf("\t-"); 
  }
 }
}
 
//看皇后的位置對不對
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  if(board[i]==column) //看直行有沒有重複擺放
   return 0;
  else
   if((board[i]-column==i-row)||(board[i]-column==row-i))   //看斜的
    return 0;
 }
 
 return 1; //可以放皇后就回傳1
}

void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; 
   if(row==n) //每一直排都試過後，印出解
    print(n); 
   else //還沒試過每一個直排，繼續嘗試
    queen(row+1,n);
  }
 }
}