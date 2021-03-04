package balance;

public class Account{
	public String holder_name;
	float balance;
	public Account(String name){
		holder_name = name;
	}
	public void set_balance(float f){
		balance = f;
	}
	public void display_balance(){
		System.out.println(holder_name + "'s current balance is " + balance);
	}
}