class Spiralorder {
	
		static void spiralorder(int a[][],int m,int n){
		 int top=0,left=0,right=n-1,bottom=m-1;
		 int dir=0;
		 while(top<=bottom && left <= right){
		     if(dir==0){
		         for(int i=left;i<=right;++i)
		         System.out.print(a[top][i]+" "); 
		         
		         top++;
		     }
		     if(dir==1){
		         for(int i=top;i<=bottom;i++)
		             System.out.print(a[i][right]+" ");
		         right--;
		     }
		     if(dir==2){
		         for(int i=right;i>=left;i--)
		             System.out.print(a[bottom][i]+" ");
		         bottom--;
		     }
		     if(dir==3){
		         for(int i=bottom;i>=top;i--)
		             System.out.print(a[i][left]+" ");
		         left++;
		     }
		     dir=(dir+1)%4;
		 }
		 
	}

	public static void main(String arg[]){
		int a[][]={{1,2},{3,4},{5,6}};
		int m=a.length;
		int n=a[0].length;
		spiralorder(a,m,n);
	}
}

