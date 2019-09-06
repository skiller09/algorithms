import java.util.*;

public class acmicpc2750 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//initialize
		int input=0;
		int i, j, key;
		Scanner inputStream = new Scanner(System.in);
		
		//how many numbers do you want to sort?
		input = inputStream.nextInt();
		int[] array = new int[input];
		
		//get numbers and save
		for(i=0;i<input;i++)
			array[i]=inputStream.nextInt();
		
		//insertion sort
		for(i=1;i<input;i++) {
			key = array[i];
			j = i-1;
			
			//reverse version: array[j]<key
			while(j>=0&&array[j]>key) {
				array[j+1] = array[j];
				j--;
			}
			
			array[j+1] = key;
		}
		
		//print the sorted list
		for(i=0;i<input;i++)
			System.out.println(array[i]);
	}

}
