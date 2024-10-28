package day1st;

public class ThisDay {
//name of the file should be the class name which is public or class containing main function
	//the order of modifiers is not important
	static public void main(String args[]) {
		
		System.out.println("from String args[]");
		//System is inbuilt class and out is the static member of System class
		System.out.println(Static_X.name);
		
		Static_X obj1=new Static_X(1);
		Static_X obj2=new Static_X(2);
		System.out.println(obj1.x);
		System.out.println(obj2.x);
		
		child ch=new child();
		ch.show();
		
	}
	
	//overloading of main function is acceptable
	static public void main(int args[]) {
		System.out.println("from int args[]");
	}
}

class Static_X{
	static String name="mohammedYahya";//it is for class (static)
	int x;//this is for every object
	
	Static_X(int x){
		this.x=x;
	}
}

class parent{
	public static void main() {
		System.out.println("hi");
	}
	void show() {
		System.out.println("i am now showing");
	}
}

class child extends parent{
	void show() {
		System.out.println("i am now showing from child");
	}
}
