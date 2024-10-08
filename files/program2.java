package uzair;
import java.util.Scanner;
public class program2 {
	public static void main(String[] args)
	{
		StringBuffer s=new StringBuffer();
		String str2;
		Scanner input=new Scanner(System.in);
		s.append("java programming");
		System.out.println("THE CURRENT CAPACITY OF StringBuffer"+s.capacity());
		System.out.println("INITIAL STRING WITHOUT APPEND"+s);
		System.out.println("ENTER A STRING TO APPEND");
		str2=input.nextLine();
		s.append(""+str2);
		System.out.println("INITIAL STRING AFTER APPEND"+s);
		s.reverse();
		System.out.println("INITIAL STRING AFTER REVERSING"+s);
		int i=0;
		do
		{
			s.replace(i,i+1,s.substring(i,i+1).toUpperCase());
			i=i+1;
		}
		while(i>0&&i<s.length());
		System.out.println("AFTER REVERSING"+s);
		}
		
	}
	
