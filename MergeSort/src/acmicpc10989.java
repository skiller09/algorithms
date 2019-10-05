import java.util.*;

public class acmicpc10989 {

	static void MergeSort(int[] array, int p, int r) {
		if(p<r) {
			int q = (p+r)/2;
			MergeSort(array,p,q);
			MergeSort(array,q+1,r);
			Merge(array,p,q,r);
		}
	}
	
	static void Merge(int[] array, int p, int q, int r) {
		int i, j, k;
		int[] L = new int[q-p+3];
		int[] R = new int[r-q+2];
		
		for(i=1;i<=q-p+1;i++) L[i] = array[p+i-1];
		for(j=1;j<=r-q;j++) R[j] = array[q+j];
		//L[q-p+2] = 10000; : 27,28번째 줄 사용 안할 때 필요
		//R[r-q+1] = 10000;
		i=1;
		j=1;

		for(k=p;k<=r;k++) {
			if(i>q-p+1) while(k<=r) array[k++] = R[j++];
			else if(j>r-q) while(k<=r) array[k++] = L[i++];
			else if(L[i]<=R[j]) array[k] = L[i++];
			else array[k]= R[j++];
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner keyboard = new Scanner(System.in);
		int n = keyboard.nextInt();
		int[] array = new int[n+1];
		
		for(int u=1;u<=n;u++) array[u] = keyboard.nextInt();
		
		MergeSort(array,1,n);
		
		for(int u=1;u<=n;u++) System.out.println(array[u]);
		keyboard.close();

	}

}
