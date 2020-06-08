public class iterative_traversal{

    public static  class Node{
        int data;
        Node left=null;
        Node right=null;

        Node(int data)
        {
            this.data=data;
        }
    }

    public  static class tpair{
        Node node=null;
        boolean selfdone=false;
        boolean leftdone=false;
        boolean rightdone=false;

        tpair(Node node,boolean sd,boolean ld,boolean rd)
        {
            this.node=node;
            this.selfdone=sd;
            this.leftdone=ld;
            this.rightdone=rd;
        }
    }

    static int i=0;
    public static Node create_tree(int[]arr)
    {
        if(arr[i]==-1 || i==arr.length){
        i++;
        return null;
        }

        Node node=new Node(arr[i]);
        i++;
        node.left=create_tree(arr);
        node.right=create_tree(arr);
        return node;
    }

    public static void inorder(Node node)
    {
        if(node ==null) return ;
        System.out.print(node.data+"-> ");
        inorder(node.left);
        inorder(node.right);
        return;
    }

    public static void inorder_traversal(Node node)
    {
        return;
    }
    public static void tree_traversal()
    {   
        int[] arr={0,1,2,-1,-1,3,-1,-1,4,5,-1,-1,6,-1,-1};
        Node node=create_tree(arr);
        inorder(node);
        inorder_traversal(node);
        return;
    }

    public static void main(String[] args)
    {
        tree_traversal();
        return ;

    }
}