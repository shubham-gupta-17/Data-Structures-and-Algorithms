public class bitonic{


	public static void main(String[] args)
	{
		solve();
	}

	public static void solve()
	{
		int[] arr={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15,4};
		int[] LIS=new int[arr.length];
		int[] LDS=new int[arr.length];
		// find longest increasing subsequence
		int max_lis=find_LIS(arr,LIS);
		System.out.println(max_lis);
		display(LIS);

		// find longest decreasing subsequence
		int max_lds=find_LDS(arr,LDS);
		System.out.println(max_lds);
		display(LDS);
		System.out.println();

		// find bitonic array:
		int bitonic=0;
		int len=0;
		for(int i=0;i<arr.length;i++)
		{
			bitonic=LIS[i]+LDS[i]-1;
			len=Math.max(bitonic,len);
		}
		System.out.println(len);

		//find maximum sum of incereasing subsequence
		max_sum_increasing_subsequence(arr);

		// reverse LIS from right to left
		int n= arr.length;
		int [] LIS_rev=new int[n];
		int min_lis=find_reverse_lis(arr,LIS_rev);
		System.out.println(min_lis);
		display(LIS_rev);

		// reverse LDS from left to right
		int [] LDS_rev=new int[n];
		int min_lds=find_reverse_lds(arr,LDS_rev);
		System.out.println(min_lds);
		display(LDS_rev);
	}

	public static int find_LIS(int[] arr,int[] lis)
	{
		lis[0]=1;
		int len=0;
		for(int i=1;i<arr.length;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[i]>arr[j])
				{
					lis[i]=Math.max(lis[i],lis[j]);
				}

			}
			lis[i]++;
			len=Math.max(len,lis[i]);

		}

		return len;
	}
	public static int find_LDS(int[] arr,int[] lid)
	{	
		int n=arr.length;
		lid[n-1]=1;
		int len=0;
		for(int i=n-2;i>=0;i--)
		{
			for(int j=n-1;j>i;j--)
			{
				if(arr[i]>arr[j])
				{
					lid[i]=Math.max(lid[i],lid[j]);
				}
			}
			lid[i]++;
			len=Math.max(len,lid[i]);
		}
		return len;
	}

	public static void max_sum_increasing_subsequence(int[] arr)
	{
		int n=arr.length;
		int[] dp=new int[n];

		int max_sum=0;
		for(int i=0;i<n;i++)
		{	
			dp[i]=arr[i];
			for(int j=0;j<i;j++)
			{
				if(arr[i]>arr[j])
				{
					dp[i]=Math.max(dp[i],dp[j]+arr[i]);
				}
			}
			max_sum=Math.max(max_sum,dp[i]);
		}

		System.out.println(max_sum);
	}

	// minimum no of deletion to make array sorted
	public static int min_deletion(int[] arr)
	{
		lis[0]=1;
		int len=0;
		for(int i=1;i<arr.length;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[i]>=arr[j])
				{
					lis[i]=Math.max(lis[i],lis[j]);
				}

			}
			lis[i]++;
			len=Math.max(len,lis[i]);

		}

		return n-len;
	}

	public static int find_reverse_lis(int[] arr,int[] dp)
	{
		int n=arr.length;
		dp[n-1]=1;
		int len=0;
		for(int i=n-2;i>=0;i--)
		{
			for(int j=i+1;j<n;j++)
			{
				if(arr[i]<arr[j])
				{
					dp[i]=Math.max(dp[j],dp[i]);
				}
			}
			dp[i]++;
			len=Math.max(dp[i],len);
		}

		return len;
	}

	public static int find_reverse_lds(int[] arr,int[] dp)
	{

		int n=arr.length;
		dp[0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[j]>arr[i])
				{
					dp[i]=Math.max(dp[i],dp[j]);
				}
			}

			dp[i]++;
			len=Math.max(dp[i],len);
		}
		return len;
	}



	public static void display(int[] arr)
	{	
		System.out.println();
		for(int i=0;i<arr.length;i++){
			System.out.print(arr[i] + " ");
		}
	}
}