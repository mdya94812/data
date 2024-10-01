package myJavaLab;
import java.util.Scanner;

public class stuInfo1 {
	
	public String name;
	public String vtuNo;
	public int sem;
	public String branchCode;
	public String address;
	
	public stuInfo1(){
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("enter your name :"); /* not println as it break the line */
		name=scanner.nextLine();
		
		System.out.print("enter your vtuNo :"); 
		vtuNo=scanner.nextLine();
		
		System.out.print("enter your branchCode :"); 
		branchCode=scanner.nextLine();
		
		System.out.print("enter your address :"); 
		address=scanner.nextLine();
		
		System.out.print("enter your sem :"); 
		sem=scanner.nextInt();
	}
	
	public void show() {
		System.out.println("your name is :"+name);
		System.out.println("your vtuNo is :"+vtuNo);
		System.out.println("your sem is :"+sem);
		System.out.println("your branchCode is :"+branchCode);
		System.out.println("your address is :"+address);	
	}
	
public static void main(String[] args) {
	stuInfo1 stu1 =new stuInfo1();
	stu1.show();
}
}


