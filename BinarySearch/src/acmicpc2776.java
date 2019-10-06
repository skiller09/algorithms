import java.util.*;
import java.io.*;

public class acmicpc2776 {
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

	static int BinarySearch(int[] A, int r, int X) {
		int i, q;
		for(i=0;i<=r;) {
			q = (i+r)/2;
			if(A[q]==X) return 1;
			else if(A[q]>X) r = q-1;
			else i = q+1;
		}
		return 0;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Integer> A = new ArrayList<Integer>();
		int t,n, m, i, j, r;
		t = Integer.parseInt(next());
		while(t-->0) {
			n = Integer.parseInt(next());
			int[] array = new int[n];
			for(i=0;i<n;i++) array[i] = Integer.parseInt(next());
			m = Integer.parseInt(next());
			int[] check = new int[m];
			for(j=0;j<m;j++) check[j] = Integer.parseInt(next());
			
			Arrays.sort(array);
			r = array.length-1;
			int ans;
			for(j=0;j<m;j++) {
				ans = BinarySearch(array,r,check[j]);
				A.add(ans);
			}
		}
		int size = A.size();
		for(int u=0;u<size;u++) out.println(A.get(u));
		out.close();
	}

}
