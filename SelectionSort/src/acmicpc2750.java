import java.io.*;
import java.util.*;

public class acmicpc2750 {
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String next() {
		while(st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch(IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}
	
	static void SelectionSort(int[] A) {
		int i, j, min, n, temp;
		n = A.length-1;
		for(i=1;i<n;i++) {
			min = i;
			for(j=i+1;j<=n;j++) if(A[j]<A[min]) min = j;
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
	
	public static void main(String[] args) {
		int n = Integer.parseInt(next());
		int[] array = new int[n+1];
		
		for(int u=1;u<=n;u++) array[u] = Integer.parseInt(next());
		
		SelectionSort(array);
		
		for(int u=1;u<=n;u++) out.println(array[u]);
		out.close();
		
	}
}
