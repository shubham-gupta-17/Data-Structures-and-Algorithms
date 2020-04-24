public class dice{
// given a start and end you are given an array of jumps which you can make to reach end find no of ways in which you can reach end
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

public static void solve()
{	int start=0;
	int end=10;
	int[] arr={1,2,3,4,5,6};
	int [] ar={3,5,7};
	int[] dp=new int[end+1];

	// for(int i=10;i>=0;i--)
	// System.out.println(dice_memo(i,end,arr,6,dp));
	//System.out.println(dice(start,end,ar,3,dp));
	
	System.out.println(dice_tab(start,end,arr,dp));
}

public static void main(String[] args)
{
	solve();
	
	
}





}