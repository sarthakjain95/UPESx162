
class Q2{

	public static void main(String args[]){

		HockeyPlayer p1 = new HockeyPlayer("Ramesh", 232342, 15);
		FootballPlayer p2 = new FootballPlayer("Gaurav", 565669, 18);
		CricketPlayer p3 = new CricketPlayer("Priya", 901234, 16);

		p1.display_info();
		p2.display_info();
		p3.display_info();

	}

}

class Player{

	String name;
	int id;
	int age;

	Player(String name_, int id_, int age_){
		name = name_;
		id = id_;
		age = age_;
	}

	public void display_info(){
		System.out.println("\nNAME:"+name);
		System.out.println("ID:"+id+" \t AGE:"+age);
	}

}

class CricketPlayer extends Player{
	
	CricketPlayer(String name_, int id_, int age_){
		super(name_, id_, age_);
	}
	
	public void display_info(){
		super.display_info();
		System.out.println("Tournament: Cricket \t Location: Delhi");
	}

}

class HockeyPlayer extends Player{

	HockeyPlayer(String name_, int id_, int age_){
		super(name_, id_, age_);
	}

	public void display_info(){
		super.display_info();
		System.out.println("Tournament: Hockey \t Location: Mumbai");
	}

}

class FootballPlayer extends Player{
	
	FootballPlayer(String name_, int id_, int age_){
		super(name_, id_, age_);
	}

	public void display_info(){
		super.display_info();
		System.out.println("Tournament: Football \t Location: Jaipur");
	}

}



