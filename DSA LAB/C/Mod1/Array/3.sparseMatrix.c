#include<stdio.h>

int create_sparse(int row,int col,int matrix[][10],int sparseMatrix[][3])
{
    int k=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]!=0)
            {
                sparseMatrix[k][0]=i;
                sparseMatrix[k][1]=j;
                sparseMatrix[k][2]=matrix[i][j];
                k++;
            }
        }
    }
    return k;
}


int main()
{
    int matrix[][10]={
        {0, 0, 3, 0, 24},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 10, 0},
        {14, 0, 15, 0, 0}
    };
    int sparseMatrix[10][3];
    int row=4,col=5;
    int k=create_sparse(row,col,matrix,sparseMatrix);
    printf("The actual matrix: \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    printf("THe sparce matrix: \n");
    for(int i=0;i<k;i++)
    {
        printf("%d %d %d\n",sparseMatrix[i][0],sparseMatrix[i][1],sparseMatrix[i][2]);
        // printf("\n");
    }

}

