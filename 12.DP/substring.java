public class substring{


	public static boolean[][] isPalindrom(String s){
		boolean[][] dp= new boolean[s.length()][s.length()];

		for(int gap=0;gap<s.length();gap++)
		{
			for(int si=0,ei=gap;ei<s.length();si++,ei++)
			{
				if(gap==0) dp[si][ei]=true;
				else if(s.charAt(si)==s.charAt(ei) && gap==1)  dp[si][ei]=true;
				else dp[si][ei]=s.charAt(si)==s.charAt(ei) && dp[si+1][ei-1];
			}
		}

		return dp;
	}

	public static void display(int[][] arr)
	{
		for(int [] ele:arr)
		{
			for(int i:ele)
				System.out.print(i+" ");

			System.out.println();
		}
	}
	public static int[][] longestPalindrom_substring(String s)
	{
		int[][] dp=new int[s.length()][s.length()];

		for(int gap=0;gap<s.length();gap++)
		{
			for(int i=0,j=gap;j<s.length();i++,j++)
			{
				if(gap==0) dp[i][j]=1;
				else if(gap==1 && s.charAt(i)==s.charAt(j))
					dp[i][j]=2;
				else if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]!=0)
					dp[i][j]=dp[i+1][j-1]+2;

			}
		}
		return dp;
	}

	public static int longestPalindrom_substring_memo(String s,int i,int j,int[][] dp)
	{
		if(i>j)
			return 0;

		if(i==j)
			return dp[i][j]=1;

		if(dp[i][j]!=0)  return dp[i][j];

		int ans=0;
		if(s.charAt(i)==s.charAt(j) )
		{
			ans=longestPalindrom_substring_memo(s,i+1,j-1,dp);

		}
		longestPalindrom_substring_memo(s,i+1,j,dp);
		longestPalindrom_substring_memo(s,i,j-1,dp);

		return dp[i][j]=ans==0?0:ans+2;

	}
	public static int[][] longestPalindrom_subsequence(String s)
	{
		int[][] dp=new int[s.length()][s.length()];

		for(int gap=0;gap<s.length();gap++)
		{
			for(int i=0,j=gap;j<s.length();i++,j++)
			{
				if(gap==0) dp[i][j]=1;
				else if(s.charAt(i)==s.charAt(j))  dp[i][j]=dp[i+1][j-1]+2;
				else if(s.charAt(i)!=s.charAt(j))  dp[i][j]=Math.max(dp[i][j-1],dp[i+1][j]);

			}
		}
		return dp;
	}
	public static int count_palindrom_substring(String s)
	{
		int[][] dp=new int[s.length()][s.length()];
		int count=0;
		for(int gap=0;gap<s.length();gap++)
		{
			for(int i=0,j=gap;j<s.length();i++,j++)
			{
				if(gap==0) dp[i][j]=1;
				else if(gap==1 && s.charAt(i)==s.charAt(j))
					dp[i][j]=2;
				else if(s.charAt(i)==s.charAt(j))
					dp[i][j]=dp[i+1][j-1]+2;

				count+=dp[i][j]!=0?1 : 0;

			}
		}
		return count;
	}

	public static String longestPalindromicSubsubsequence_String(String str){
		String[][] dp=new String[str.length()][str.length()];
		
		for(int gap=0;gap<str.length();gap++){
			for(int si=0,ei=gap;ei<str.length();si++,ei++){
		
				if(gap==0) dp[si][ei]=str.charAt(si)+"";  //length 1
				else if(gap==1 && str.charAt(si) == str.charAt(ei)) dp[si][ei]=str.substring(si,ei+1);
				else if(str.charAt(si) == str.charAt(ei)) dp[si][ei]=str.charAt(si) + dp[si+1][ei-1]+str.charAt(ei);
				//else dp[si][ei]=dp[si+1][ei].length()>=dp[si][ei-1].length()?dp[si+1][ei]:dp[si][ei-1];
			}
		}
		
		 for(String[] arr:dp)
         {
             for(String s:arr)
          {
//                if(ans.length()<s.length())
                    //ans=s;
                  System.out.print(s+" ");
                             
             }
          // cout<<endl;  
          System.out.println();     
         }
		return dp[0][str.length()-1];
	}
	public static void solve_palindrome()
	{	
		// longest substring
		String s="abcdacad";
		int [][] arr=new int[s.length()][s.length()];
		arr= longestPalindrom_substring(s);
		display(arr);
		System.out.println();

		//count palindrome substring
		System.out.println(count_palindrom_substring(s));

		// longest subsequence
		String s1="geeksse";
		int [][] arr1=new int[s.length()][s.length()];
		arr1= longestPalindrom_subsequence(s1);
		display(arr1);

		System.out.println();
		int[][] dp1=new int[s.length()][s.length()];
		longestPalindrom_substring_memo(s,0,s.length()-1,dp1);
		display(dp1);

		longestPalindromicSubsubsequence_String(s);

	}

	public static void main(String[] args)
	{	
		solve_palindrome();
	}



}