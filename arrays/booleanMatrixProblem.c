#include <stdio.h>
#include <stdlib.h>
int main() {
	//code
	int t;
	scanf("%d",&t);
	while(t>0) {
	    int r,c;
	    scanf("%d",&r);
	    scanf("%d",&c);
	    int i,j,k;
	    
	    //declare array
	    int **a = (int **)malloc(r * sizeof(int *));
        for (i=0; i<r; i++)
             a[i] = (int *)malloc(c * sizeof(int));
        
       //initialise array 
	    for(i=0;i<r;++i)
	        for(j=0;j<c;++j)
	            scanf("%d",&a[i][j]);
	            
	    int rcol=0,bcol=0;
	    for(i=0;i<c;++i)
	        if(a[0][i]==1)
	            rcol=1;
	            
	    for(i=0;i<r;++i)
	        if(a[i][0]==1)
	            bcol=1;
	    
	    for(i=1;i<r;++i)
		{
	        for(j=1;j<c;++j)
            {
                if(a[i][j]==1)
				{
					a[i][0]=1;
					a[0][j]=1;
				}
            }
		}

        for(i=1;i<r;++i)
	    {
			if(a[i][0]==1)
			{
				for(j=0;j<c;++j)
					a[i][j]=1;
			}
	    }
		
	    for(j=1;j<c;++j)
	    {
			if(a[0][j]==1)
			{
				for(i=0;i<r;++i)
					a[i][j]=1;
			}
	    }
	   if(rcol==1)
	    for(j=0;j<c;++j)
	           a[0][j]=1;
	   if(bcol==1)
	    for(j=0;j<r;++j)
	           a[j][0]=1;
	            
	            
	   //print array
	     for(i=0;i<r;++i)
	     {
	        for(j=0;j<c;++j)
	            printf("%d ",a[i][j]);
	            
	          
	     }
	   //free array
	    for (i = 0; i < r; i++) {
          free(a[i]);
        }
        free(a);
         printf("\n");   
	   t--;
	}
	
	
	return 0;
}