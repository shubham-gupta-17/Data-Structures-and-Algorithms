public class TrieBasic{

  public class Node{
    int word_end=0;
    Node[] childs;
    String word="";
    Node(){
      this.childs=new Node[26];

    }
  }

  Node root=null;
  public static  void insert(String word){
    Node current=root;
    int n=word.length();
    for(int i=0;i<n;i++)
    {
      int idx=word.charAt(i)-'a';
      if(current.childs[idx]==null) current.childs[idx]=new Node();
      current=current.childs[idx];
    }
    current.word_end++;
  }

  //leetcode 208
  public static boolean search(String word){
    Node current=root;
    int n=word.length();
    for(int i=0;i<n;i++)
    {
      int idx=word.charAt(i)-'a';
      if(current.childs[idx]==null) return false;
      current=current.childs[idx];
    }

    return current.word_end>0;
  }

// this function searches whether any prefix is present or not
  public static boolean startwith(String prefix){
    Node current=root;
    int n=prefix.length();
    for(int i=0;i<n;i++)
    {
      int idx=prefix.charAt(i)-'a';
      if(current.childs[idx]==null) return false;
      current=current.childs[idx];
    }

    return true;
  }

  public static void main(String[] args){
    root=new Node();
  }

}
