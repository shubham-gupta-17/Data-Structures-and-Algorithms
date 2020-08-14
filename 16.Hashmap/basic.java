import java.util.HashMap;
import java.util.ArrayList;

public class basic{

	public static void main(String[] args)
	{
		hashmap();
		String s="abbcdabbbbabbbacde";
		frequency_map(s);
		character_index(s);
	}

	public static void character_index(String s)
	{
		Hashmap<Character,ArrayList<Integer>> map=new Hashmap<>();
		
	}

	public static void hashmap()
	{
		HashMap<String,Integer> map=new HashMap<>();
		map.put("INIDA",1000);
		map.put("delhi",100);
		map.put("russia",10);
		map.put("usa",1);

		//print
		System.out.println(map);

		//keyset
		ArrayList<String> keys=new ArrayList<>(map.keySet());
		System.out.println(keys);

		for(String s:map.keySet())
			System.out.println(s);

		//get
		System.out.println(map.get("Usa")); // if it is not present than it will give output null hence we use getOrDefault
		System.out.println(map.getOrDefault("Usa",0));

	}

	public static void frequency_map(String s)
	{	
		HashMap<Character,Integer> map=new HashMap<>();
		for(int i=0;i<s.length();i++)
		{
			Character ch=s.charAt(i);
			map.put(ch,map.getOrDefault(ch,0)+1);
			
		}

		System.out.println(map);
		return;
	}

}