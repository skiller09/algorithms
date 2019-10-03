import java.util.*;

public class acmicpc10814 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			class Member{
				int age;
				String name;
			}
			
			int input, i, j;
			Member key;
			Scanner keyboard = new Scanner(System.in);
			input = keyboard.nextInt();
			Member[] club = new Member[input];
			for(i=0;i<input;i++) {
				club[i] = new Member();
				club[i].age = keyboard.nextInt();
				club[i].name = keyboard.nextLine();
			}
			
			for(i=1;i<input;i++) {
				key = club[i];
				j = i-1;
				while(j>=0 && club[j].age > key.age) {
					club[j+1] = club[j];
					j--;
				}
				club[j+1] = key;
			}
			
			for(i=0;i<input;i++) {
				System.out.println(club[i].age+" "+club[i].name);
			}
			
			keyboard.close();
	}

}
