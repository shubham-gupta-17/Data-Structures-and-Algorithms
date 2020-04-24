public class goldmine{

	public static void main(String[] ans)
	{
		int[][] mat={{1, 3, 1, 5},
                {2, 2, 4, 1},
                {5, 0, 2, 3},
                {0, 6, 1, 2}};
		int n=mat.length;
		int m=mat[0].length;
		int[][]dp= new int[n][m];

		// memoization
		int maxAns=0;
		for(int i=0;i<n;i++)
		{
			maxAns=Math.max(maxAns,gold_memo(mat,i,0,n,m,dp));
		}

	    System.out.print(maxAns);

	    // tabulation
	    int ansTab=0;
	    int[][]dp1= new int[n][m];
		gold_tab(mat,0,0,n,m,dp1);
	    for(int i=0;i<n;i++)
		{
			ansTab=Math.max(ansTab,dp[i][0]);
		}

	}
	static int[][] dir={{0,1},{1,1},{-1,1}};
	public static int gold _memo(int[][] mat,int sr,int sc,int n,int m,int[][] dp)
	{
		if(sc==m-1)
		{
			return dp[sr][sc]=mat[sr][sc];
		}

		if(dp[sr][sc]!=0) return dp[sr][sc];

		int ans=0;
		for(int i=0;i<3;i++)
		{
			int r=sr+dir[i][0];
			int c=sc+dir[i][1];

			if(r>=0 && r<n && c>=0 && c<m )
				ans=Math.max(ans,gold_memo(mat,r,c,n,m,dp));

		}

		return dp[sr][sc]=ans+mat[sr][sc];
	}

	public static int gold_tab(int[][]mat,int sr,int sc,int n,int m,int[][] dp)
	{
		for(int j=m-1;j>=0;j--)
		{
			for(int i=n-1;i>=0;i--)
			{

				if(j==m-1)
				{
					dp[i][j]=mat[i][j];
					continue;

				}

				for(int i=0;i<3;i++)
				{
					int 
				}


			}
		}
	}
}