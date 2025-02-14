#include<stdio.h>
#include<stdlib.h>
void printSolution(int **board, int N)
{
	int i,j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
 
int isSafe(int **board,int n, int row, int col)
{
    int i,j;
    for(i=0;i<col;i++){
        if(board[row][i]){
            return 0;
        }
    }
    
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return 0;
        }
    }
    
    for(i=row,j=col;j>=0 && i<n;i++,j--){
        if(board[i][j]){
            return 0;
        }
    }
    
    return 1;
}

int solveNQUtil(int **board,int n, int col)
{
    if(col>=n){
        return 1;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board,n,i,col)){
            board[i][col]=1;
            if(solveNQUtil(board,n,col+1)){
                return 1;
            }
            board[i][col]=0;
        }
    }
    return 0;
}

int solveNQ(int n)
{
    int **board,i;
    board=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        *(board+i)=(int*)calloc(n,sizeof(int));
    }
    if(solveNQUtil(board,n,0)){
        printSolution(board,n);
    }
    return 1;
}
 
int main()
{
	int N;
    scanf("%d",&N);
    solveNQ(N);
    return 0;
}
