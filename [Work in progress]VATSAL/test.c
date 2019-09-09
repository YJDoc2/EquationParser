#include<stdio.h>
int deter(int n,float A[20][20])
{
    int i,j,k;
    float ratio,det=0.0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(j>i){
                ratio = A[j][i]/A[i][i];
                for(k = 1; k <= n; k++){
                    A[j][k] -= ratio * A[i][k];
                }
            }
        }
    }
    det = 1; //storage for determinant
    for(i = 1; i <=n; i++)
        det *= A[i][i];
    printf("The determinant of matrix is: %.2f\n\n", det);
    return det;
}
int main()

{
    int i,j,k,n,d,e,f;
    float A[20][20],c,X[10],sum=0.0,res=0.0;
    printf("Enter co-efficients of variables and constant at last.\nStd.Equations:\na1x1 + b1x2 +c1x3+...=d1\na2x1 + b2x2 +c2x3+...=d2\n.\n.\n.\n.\nanx1 + bnx2 +cnx3+...=dn\n\nEnter th order of rows: ");
    scanf("%d",&n);
    printf("Enter the value of matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n+1);j++)
        {
            printf("A[%d][%d]: ",i,j);
        scanf("%f",&A[i][j]);
        }
    }
  /* for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(j>i){
                ratio = A[j][i]/A[i][i];
                for(k = 1; k <= n; k++){
                    A[j][k] -= ratio * A[i][k];
                }
            }
        }
    }
    det = 1; //storage for determinant
    for(i = 1; i <=n; i++)
        det *= A[i][i];
    printf("The determinant of matrix is: %.2f\n\n", det);*/
    res=deter(n,A);
    if(res!=0)
    {
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1;k<=n+1;k++)
                {
                    A[i][k]=A[i][k]-(c*A[j][k]);
                }
            }
        }
    }
   /* printf("\nThe Upper Triangular Matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%f",A[i][j]);
        }
        printf("\n");
    }*/
    X[n]=A[n][n+1]/A[n][n];
    for(i=n-1;i>=1;i--)
    {
        sum=0.0;
        for(j=i+1;j<=n;j++)
        {
            sum+=A[i][j]*X[j];
        }
        X[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("\nSolution : \n");
    for(i=1;i<=n;i++)
    {
        printf("\n%f\n",X[i]);
    }
    return 0;
    }
    else
        printf("*****Infinite or No Solutions!****");
}
