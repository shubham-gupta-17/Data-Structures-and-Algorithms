import java.util.Arraylist

public class pairPeople{

	public static void main(String[] args)
	{	
		int n=5;
		int *dp=new int [n];
		System.out.print(pair(n,dp));

	}

	public static int pair(int n,int[] dp)
	{
		 if(n<=1) return 1;
		 if(dp[n]!=0) return dp[n];

		 int ans=pair(n-1) +pair(n-2)*(n-1);

		 return dp[n]=ans;
	}




}