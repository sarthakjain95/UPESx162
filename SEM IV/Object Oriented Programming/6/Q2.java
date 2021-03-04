import balance.Account;

public class Q2{
	public static void main(String args[]){
		Account a1 = new Account("Ravi");
		Account a2 = new Account("Priya");
		a1.set_balance(234.234f);
		a2.set_balance(543.332f);
		a1.display_balance();
		a2.display_balance();
	}
}