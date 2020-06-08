import java.util.*;
public class dp2{

	 public static  int longestcommonsubstring_dp(String s1,String s2)
   {
        int len=0;
        int n1=s1.length();
        int n2=s2.length();
        int[][] dp=new int[n1][n2];
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(i==n1-1 || j==n2-1){
                 dp[i][j]=(s1.charAt(i)==s2.charAt(j))?1:0;
                 continue;
                }
                if(s1.charAt(i)==s2.charAt(j))
                    dp[i][j]=dp[i+1][j+1]+1;
                len=Math.max(len,dp[i][j]);
            }
        }
        return len;
   }
	public static  void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0)
		{
		    int n=sc.nextInt();
		    int m=sc.nextInt();
		    String s1=sc.nextLine();
		    String s2=sc.nextLine();
		    System.out.println(longestcommonsubstring_dp(s1,s2));
		}
	}




}