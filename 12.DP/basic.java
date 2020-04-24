public class basic{

	
//==================================================================
	public static void solve()
	{
		fib_solve();
		
		//maze_path();

		dice();
	}

	public static void main(String[] args)
	{
		solve();
	}

	public static int fib_rec(int n,int[] dp)// memoisation
	{	//if(n<0) return 0;
		if(n==1 || n==0) return 1;

		if(dp[n]!=0)  return dp[n]; // check if you have seen this structure of tree also called memoisation and bottom up approach

		int ans=fib_rec(n-1,dp) + fib_rec(n-2,dp);
		if(dp[n]==0) dp[n]=ans;
		return ans;
	}

	public static int fib_tab(int n,int[] dp)// tabulation
	{
		for(int i=1;i<=n;i++)
		{				
			if(i<=1){
				dp[i]=i;	//base
				continue;
			}

			int ans=dp[i-1] + dp[i-2];
			dp[i]=ans;
		}
		return dp[n];
	}

	public static int[][] fib3_multiply(int[][] a, int[][] b)
	{	int[][] ans=new int[2][2];
		int a0=a[0][0]*b[0][0] +a[0][1]*b[1][0];
		int a1=a[0][0]*b[0][1] + a[0][1]*b[1][1];
		int a2=a[1][0]*b[0][0] +a[1][1]*b[1][0];
		int a3=a[1][0]*b[0][1] +a[1][1]*b[1][1];
		ans[0][0]=a0;
		ans[0][1]=a1;
		ans[1][0]=a2;
		ans[1][1]=a3;

		return ans;
	}

	public static int[][] fiblogn(int[][] a,int n)
	{
		if(n==1)
			return a;
		int [][] rec_ans=fiblogn(a,n/2);
		rec_ans=fib3_multiply(rec_ans,rec_ans);

		return n%2!=0?fib3_multiply(rec_ans,a):rec_ans;
	}
	public static void fib_solve()
	{	
		int n=7;
		int[] dp=new int[n+1];

		// int ans=fib_rec(n,dp);  //memoization
		// display(dp);
		// System.out.println(ans);

		// int[] dp1= new int[n+1];
		// System.out.println();
		// System.out.println(fib_tab(n,dp1)); //tabulation


		int[][] a={{1,1},{1,0}};
		int[][] ans=fiblogn(a,n);
		display2D(ans);
	}

	public static void display2D(int[][] arr)
	{
		for(int[] ar:arr)
		{
			for(int ele:ar)
				System.out.print(ele+" ");

			System.out.println();
		}
	}

	public static void display(int[] arr)
	{
		for(int ele:arr)
			System.out.println(ele+" ");
	}


	static int[][] dir={{0,1},{1,0},{1,1}};
	public static int maze_path_rec(int sr,int sc,int er,int ec,int[][] dp)
	{
		if(sr==er && sc==ec){
			dp[sr][sc]=1;
			return 1;
		}

		if(dp[sr][sc]!=0 )  return dp[sr][sc];
		int count=0;
		for(int i=0;i<3;i++)
		{
			int r=sr+dir[i][0];
			int c=sc+dir[i][1];
			if(r<=er && c<=ec){
			count+=maze_path_rec(r,c,er,ec,dp);
		}
		}

		return dp[sr][sc]=dp[sc][sr]=count; // this condition is possible only if it is a square matrix
	}
	public static int maze_path_tabu(int[][] dp,int er,int ec)
	{
		for(int sr=er;sr>=0;sr--)
		{
			for(int sc=ec;sc>=0;sc--)
			{
				if(sr==er && sc==ec)
				{
					dp[sr][sc]=1;
					continue;
				}

				int count=0;
		for(int i=0;i<3;i++)
		{
			int r=sr+dir[i][0];
			int c=sc+dir[i][1];
			if(r<=er && c<=ec){
			count+=dp[r][c];
		}
		}

		dp[sr][sc]=count;
			}
		}

		return dp[0][0];
	}
	public static int maze_path_rec_multimove(int sr,int sc,int er,int ec,int[][] dp)
	{
		if(sr==er && sc==ec){
			dp[sr][sc]=1;
			return 1;
		}

		if(dp[sr][sc]!=0 )  return dp[sr][sc];
		int count=0;
		
		
		for(int jump=1;jump<=er+1;jump++)
		{	for(int i=0;i<3;i++){
			int r=sr+jump*dir[i][0];
			int c=sc+jump*dir[i][1];
			if(r<=er && c<=ec){
			count+=maze_path_rec_multimove(r,c,er,ec,dp);
		}
		}
	}

		return dp[sr][sc]=dp[sc][sr]=count; // this condition is possible only if it is a square matrix
	}
	public static void maze_path()
	{	//single move or jump=1
		int row=4;
		int col=4;
		int[][]dp=new int[row][col];
		System.out.println(maze_path_rec(0,0,row-1,col-1,dp));
		display2D(dp);

		System.out.println(maze_path_tabu(dp,row-1,col-1));
		display2D(dp);


		//jump=size;
		int[][]dp1=new int[row][col];
		System.out.println(maze_path_rec_multimove(0,0,row-1,col-1,dp1));
		display2D(dp1);

	}
	

	public static int dice_memo(int start,int end,int[] arr,int n,int[] dp)
{		if(start>end)
		return 0;

		if(start==end){
			return dp[start]=1;
		}

		if(dp[start]!=0)  return dp[start]; 
		int count=0;
		for(int i=0;i<n;i++)
		{	if(start+i<=end)
			count+=dice_memo(start+arr[i],end,arr,n,dp);
		}

		if(dp[start]==0) dp[start]=count;
		return count;

}

	public static int dice_tab(int start,int end,int[] arr,int[] dp)
	{
		for(int i=end;i>=start;i--)
		{
			if(i==end)
			{
				dp[i]=1;
				continue;
			}

			int count=0;
			for(int j=0;j<6;j++){
				if(i+arr[j]<=end)
				count+=dp[i+arr[j]];
			}

			dp[i]=count;
			
		}
		return dp[0];
	}

	public static int dice_tab_step(int start,int end,int[] steps,int[] dp)
	{
		for(int i=end;i>=start;i--)
		{
			if(i==end)
			{
				dp[i]=1;
				continue;
			}

			int count=0;
			for(int j=0;j<steps.length;j++)
			{
				if(i+steps[j]<=end)
					count+=dp[i-steps[j]];

			}

			dp[i]=count;
		}

		dp[0];
	}
	public static void dice()
	{	int start=0;
		int end=10;
		int[] arr={1,2,3,4,5,6};
		int [] steps={3,5,7};
		int[] dp=new int[end+1];

		// for(int i=10;i>=0;i--)
		// System.out.println(dice_memo(i,end,arr,6,dp));
		//System.out.println(dice(start,end,ar,3,dp));
		
		System.out.println(dice_tab(start,end,arr,dp));
		System.out.println(dice_tab_step(start,end,steps,dp));
	}


}