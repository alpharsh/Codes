// wap if the no is special or not if the sepcial no is the factorial of the digits in the number is equal to the number itself 
import java.util.Scanner;

class spcl{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number to check if it is special or not: ");
        int num = sc.nextInt();
        int originalNum = num;
        int sum = 0;

        while (num > 0) {
            int digit = num % 10;
            sum += factorial(digit);
            num /= 10;
        }

        if (sum == originalNum) {
            System.out.println(originalNum + " is a special number.");
        } else {
            System.out.println(originalNum + " is not a special number.");
        }
    }

    static int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
}