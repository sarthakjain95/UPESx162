
// Write a program using classes and object in java.

class ClassesAndObjects{

	public static void main(String[] args){

		DateTime gmt = new DateTime();
		DateTime ist = new DateTime();

		gmt.setTime(0, 0, 0);
		ist.setTime(5, 30, 0);

		for(int i=0; i<5; i++){
			for(int j=0; j<60; j++){ // Increment Minutes
				gmt.increment();
				ist.increment();
			}
			System.out.print("GMT: ");
			gmt.print();
			System.out.print("\t  IST: ");
			ist.print();
			System.out.print("\n");
		}

	}

}

class DateTime{

	int hour = 0;
	int minutes = 0;
	int seconds = 0;

	public void increment(){
		seconds = (seconds + 1) % 60;
		if(seconds == 0){
			minutes = (minutes + 1) % 60;
			if(minutes == 0){
				hour = (hour + 1) % 24;
			} 
		}
	}

	public void setTime(int h, int m, int s){
		hour = h;
		minutes = m;
		seconds = s;
	}

	public void print(){
		System.out.print(hour + "h" + minutes + "m" + seconds + "s");
	}

}
