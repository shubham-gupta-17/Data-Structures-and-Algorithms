public class coin{

	public static void main(String[] args)
	{
		solve();
	}
	static int count=0;
	public static void solve()
	{	int[] coin={2,3,5,7};
		int target=10;
		System.out.println(permutation_infinite(coin,target));
		//System.out.println(combination_infinite(coin,target));
		int [] dp=new int [target+1];
		System.out.println(permutation_infinite_rec(coin,target,dp));
		System.out.println(count);
	}
	
	public static int permutation_infinite(int[] coin,int target)
	{
		int[] tar=new int[target+1];
		tar[0]=1;
		for(int i=1;i<=target;i++)
		{
			for(int coins:coin)
			{
				if(i-coins>=0)
					tar[i]+=tar[i-coins];
			}
		}
		return tar[target];
	}

	public static int permutation_infinite_rec(int[] coins,int target,int [] dp)
	{
		if(target==0){
			count++;
			return dp[0]=1;

		}

		int ans=0;
		for(int i=0;i<coins.length;i++)
		{
			if(target-coins[i]>=0)
			{
				ans+=permutation_infinite_rec(coins,target-coins[i],dp);
			}
		}
		return ans;
	}



































}