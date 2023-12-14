#include <stdio.h>
#include <mpi.h>
#define DADOS 100

int main()
{
   int i,j,k;
   int n=2;

   int rank; 
   int total;
   MPI_Status s;
   MPI_Init(NULL,NULL);

   MPI_Comm_size(MPI_COMM_WORLD,&total);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);

   if(rank == 0) //mestre
   {
      double A[n][n],B[n][n],C[n][n],linha[n],linha1[n];

      for(i=0; i<n; i++){       
         for(j=0; j<n; j++){
            A[i][j]=1;
            B[i][j]=2;
         }
      }
      //-----------------------------------
      for(i=0; i<n; i++){
         for(j=0; j<n; j++)
            printf("%.1lf ",A[i][j]);
         printf("\n");
      }
      printf("\n");
      //-----------------------------------
      
      for(i=0;i<n;i++){
         MPI_Send(&A[0][i],n,MPI_DOUBLE,1,DADOS,MPI_COMM_WORLD);
         MPI_Send(&A[1][i],n,MPI_DOUBLE,2,DADOS,MPI_COMM_WORLD);
      }

      MPI_Send(&B[0][0],n*n,MPI_DOUBLE,1,DADOS,MPI_COMM_WORLD);
      MPI_Send(&B[0][0],n*n,MPI_DOUBLE,2,DADOS,MPI_COMM_WORLD);

      MPI_Recv(&linha[0],n,MPI_DOUBLE,1,DADOS,MPI_COMM_WORLD,&s);
      MPI_Recv(&linha1[0],n,MPI_DOUBLE,2,DADOS,MPI_COMM_WORLD,&s);
      
    for(i=0; i<n; i++)
        C[0][i] = linha[i];
    for(i=0; i<n; i++)
        C[1][i] = linha1[i];

    for(j=0; j<n;j++){
      printf("\n");
      for(i=0; i<n; i++)
         printf("%.1lf ",C[j][i]);
    }
      
   else if(rank == 1)
   {  
      double A[n];
      double B[n][n];
      double linha[n];
      for(k=0;k<n;k++)
         MPI_Recv(&A[k],n,MPI_DOUBLE,0,DADOS,MPI_COMM_WORLD,&s);

      MPI_Recv(&B[0][0],n*n,MPI_DOUBLE,0,DADOS,MPI_COMM_WORLD,&s);

      for(int j=0; j<n; j++){
            linha[j]=0;
            for(int k=0;k<n;k++)
               linha[j] = linha[j] + A[k]*B[k][j];
      }
      MPI_Send(&linha[0],n,MPI_DOUBLE,0,DADOS,MPI_COMM_WORLD);
   }
   else if(rank == 2)
   {  
      double A[n];
      double B[n][n];
      double linha1[n];
      for(k=0;k<n;k++)
         MPI_Recv(&A[k],n,MPI_DOUBLE,0,DADOS,MPI_COMM_WORLD,&s);

      MPI_Recv(&B[0][0],n*n,MPI_DOUBLE,0,DADOS,MPI_COMM_WORLD,&s);

      for(int j=0; j<n; j++){
            linha1[j]=0;
            for(int k=0;k<n;k++)
               linha1[j] = linha1[j] + A[k]*B[k][j];
      }
      MPI_Send(&linha1[0],n,MPI_DOUBLE,0,DADOS,MPI_COMM_WORLD);
   }
 
   MPI_Finalize();

return 0;
}


