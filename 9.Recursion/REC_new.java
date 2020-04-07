import java.util.ArrayList;
public class REC_new{


		public static ArrayList<String> subseq(String s)
		{	
			if(s.length()==0)
			{
				ArrayList<String> ans=new ArrayList<>();
				ans.add(" ");
				return ans;

			}
			char ch=s.charAt(0);
			String nstr=s.substring(1);

			ArrayList<String> smallans=subseq(nstr);
			ArrayList<String> myans= new ArrayList<>();

			//myans.addAll(smallans); // not add that char addAll just copies all the string in myans

			for(String st:smallans)   //foreach loop it is a forward loop and will traverse complete array
			{  
				myans.add(st);   // here it has same meaning as above ( we are not adding it)
				myans.add(ch+st); // adding that char
			}

			return myans;
		}

		public static int subseq_void_type(String s,String ans)
		{
			if(s.length()==0)
			{
				System.out.println(ans);
				return 1;
			}
			int count=0;
			count+=subseq_void_type(s.substring(1),ans);
			count+=subseq_void_type(s.substring(1),ans+s.charAt(0));
			return count;
		}

		public static ArrayList<String> permutation_withduplicates(String s)
		{
			if(s.length()==1)
			{
				ArrayList<String> base=new ArrayList<>();
				base.add(s);
				return base;
			}

			char ch=s.charAt(0);
			ArrayList<String> ans=permutation_withduplicates(s.substring(1));
			ArrayList<String> myans=new ArrayList<>();

			for(String str:ans)
			{
				for(int i=0;i<=str.length();i++)
				{
					myans.add(str.substring(0,i)+ch+str.substring(i));
				}
			}
			return myans;

		}

		public static int permutation_withduplicates(String s,String ans)
		{
			if(s.length()==0)
			{
				System.out.print(ans);
				return 1;
			}


			int count=0;
			for(int i=0;i<s.length();i++)
			{
				String nstr=s.substring(0,i)+s.substring(i+1);
				count+=permutation_withduplicates(nstr,ans+s.charAt(i));
			}
			return count;
		}

		public static int permutation_withoutduplicates(String s,String ans)
		{
			if(s.length()==0)
			{
				System.out.print(ans);
				return 1;
			}


			int count=0;
			boolean[] vis=new boolean[26];
			for(int i=0;i<s.length();i++)
			{	
				if(vis[s.charAt(i)-'a']==false){
					vis[s.charAt(i)-'a']=true;
				String nstr=s.substring(0,i)+s.substring(i+1);
				count+=permutation_withoutduplicates(nstr,ans+s.charAt(i));

			}
			}
			return count;
		}
	public static void main(String [] args)
	{
		ArrayList<String> ans2=subseq("abc");
		System.out.println(ans2);
		System.out.println(subseq_void_type("abc"," "));

		System.out.println(permutation_withduplicates("abc"));

		System.out.println(permutation_withduplicates("abc"," "));

		System.out.println(permutation_withoutduplicates("aba"," "));






	}
}