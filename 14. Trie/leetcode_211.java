public class leetcode_211{

      public class Node{
      int word_end=0;
      Node[] childs;
      String word="";
      Node(){
        this.childs=new Node[26];

      }
    }

    Node root=null;
      public static void  WordDictionary() {
          root=new Node();
      }

      public static void addWord(String word){
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

    public static boolean serc(String word,Node curr,int i)
    {
       if(i==word.length() && curr.word_end>0) return true;
       if(i>=word.length() || curr==null) return false;
       char ch=word.charAt(i);

           if(ch=='.'){
               boolean ans=false;
               for(int j=0;j<26;j++){
                   if(curr.childs[j]!=null)
                   ans=ans||serc(word,curr.childs[j],i+1);
               }
               return ans;
           }
       int idx=ch-'a';
       if(curr.childs[idx]==null) return false;


       return serc(word,curr.childs[idx],i+1);

    }
    public static   boolean search(String word){
       return serc(word,root,0);
    }




    public static void main(String[] args){
      WordDictionary();
    }


















    }
