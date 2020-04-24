public class cut_type{

public static void main(String[] args)
{
	int[] arr={10, 20, 30, 40, 30} ;
	int n=arr.length;
	int[][] dp=new int[n][n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			dp[i][j]=-1;
	}
	
	// using recursion
	System.out.println(find_multiplication(arr,dp,0,4));
	display(dp);


	// using dp
	System.out.println(find_multiplication_dp(arr));
}

public static void display(int[][] dp)
{
	int n=dp.length;
	for(int [] arr:dp)
	{
		for(int ele:arr)
			System.out.print(ele +" ");

		System.out.println();
	}
}

public static int find_multiplication(int[] arr,int[][] dp,int start,int end)
{
	if(start+1==end || start==end) return dp[start][end]=0;



	if(dp[start][end]!=-1  )  return dp[start][end];
	int min_cost=(int) 1e8;
	for(int cut=start+1;cut<end;cut++)
	{
		int left_cost=find_multiplication(arr,dp,start,cut);
		int right_cost=find_multiplication(arr,dp,cut,end);

		int cost= left_cost + right_cost + arr[start] * arr[cut] * arr[end];

		min_cost=Math.min(cost,min_cost);
	}

	return dp[start][end]=min_cost;
}

public static int find_multiplication_dp(int [] arr)
{
	int n= arr.length;
	int[][] dp=new int[n][n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			dp[i][j]=-1;
	}

	for(int i=n-1;i>=0;i--)
	{
		for(int j=i;j<n;j++)
		{
			if(i+1==j || i==j)
			{
				dp[i][j]=0;
				continue;
			}

			int min=(int) 1e8;
			for(int cut=i+1;cut<j;cut++)
			{
				int cost=dp[i][cut]+arr[i]*arr[cut]*arr[j] +dp[cut][j];

				min=Math.min(min,cost);
			}

			dp[i][j]=min;
		}
	}

	display(dp);

	return dp[0][n-1];

}
































}