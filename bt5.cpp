#include <stdio.h>
#include<conio.h>
#define MAX 100
int main()
{
	int n, i, j;
	int A[MAX][MAX];
	FILE *in, *out1,*out2;
	
    in= fopen("input2.txt","r");
    out1= fopen("input2_1.txt","w");
    out2= fopen("input2_2.txt","w");
    if((in==NULL)||(out1==NULL))
	{
    	printf("Khong mo duoc tep!");
    	return -1;
    }
    fscanf(in,"%d",&n);// n la so dinh
    
    int sum=0;
    for(i=0; i<n; i++)
    {	
    	for(j=0; j<n; j++)	
    	{	
    		fscanf(in,"%d",&A[i][j]);
    		sum+=A[i][j];
        }    
    }
    
	fprintf(out2,"%d  ",n);
	fprintf(out2,"%d\n",sum/2);// sum/2 bang so canh
	
	for(i=0; i<n; i++)
    {	
    	for(j=i; j<n; j++)	
    	{	
    		if(A[i][j]==1)
    		{
    			fprintf(out2,"%d\t%d",i+1,j+1);
    			fprintf(out2,"\n");
			}
        }    
    }
   
    int T[MAX], k=0, m;
	fprintf(out1,"%d\n",n);
	for(i=0; i<n; i++)
    {	
        m=k;
    	for(j=0; j<n; j++)	
    	{	
    		if(A[i][j]==1)
    		{
    			T[k]=j+1;
    			k++;
			}
        }
        fprintf(out1,"%d\t", k);
        for(int l=m; l<k; l++)
        {
        	fprintf(out1,"%d\t",T[l]);
		}
		fprintf(out1,"\n");    
    }
    

    fclose(in);
    fclose(out1);
    fclose(out2);
	getch ();	
	return 0;	
}

		
