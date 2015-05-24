//http://www.codechef.com/JULY14/problems/CSUB
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();		sc.nextLine();
		while(test-- > 0){
			int length = sc.nextInt();		sc.nextLine();
			
			String input = sc.nextLine();
										
			long count = 0;
			
			for(int i=0; i<length; i++){
				if(input.charAt(i)=='1')
					count++;
			}
									
			count = ((count+1)*count)/2;
			System.out.println(count);
		}
	}
}
