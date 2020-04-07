public class ll{
 
   public  static class  Node{
   	int  data;
   	Node next=null;

   	public Node(int data)
   	{
   		this.data=data;
   	}

   	public String tostring()
   	{
   		return (this.data + " ->");
   	}
   }


   public static void solve(){
   	Node node=new Node(10);
   	System.out.print(node);
   }

   public static void main(String[] args)
   {
   	solve();
   }


}