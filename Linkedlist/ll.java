public class ll{
 
 public static class linkedlist{
   public   class  Node{
   	int  data;
   	Node next=null;

      public Node(int data)
   	{
   		this.data=data;
   	}
   }


       Node head=null;
       Node tail=null;
       int size=0;
       public int size()
       {
         return this.size;
       }

       public boolean IsEmpty()
       {
         return size==0;
       }

       @Override
       public String toString()
       {
           return ("HI");
       }
   
   }

   public static void main(String[] args)
   {
      linkedlist ll=new linkedlist();
      System.out.println(ll);       // this will print the address of the object after overriding it will print what i want to print on console
   }

}
