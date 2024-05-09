// Java program to check Adam Number 
import java.util.Scanner;

public class adamnumber { 
	// To reverse Digits of numbers 
	static int reverseDigits(int num) 
	{ 
		int rev = 0; 
		while (num > 0) 
		{ 
			rev = rev * 10 + num % 10; 
			num /= 10; 
		} 
		return rev; 
	} 

	// To square number 
	static int square(int num) 
	{ 
		return (num * num); 
	} 

	// To check Adam Number 
	static boolean checkAdamNumber(int num) 
	{ 
		int a = square(num); 
		int b = square(reverseDigits(num)); 
		
		if (a == reverseDigits(b)) 
		return true; 
		return false;		 
	} 

	// Driver program to test above functions 
	public static void main(String[] args) 
	{ 
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter a no to check if it is an Adam Number: ");
		int num = scanner.nextInt();
		
		if (checkAdamNumber(num)) 
		System.out.println("Adam Number"); 
		else
		System.out.println("Not a Adam Number");	 
	} 

} 
