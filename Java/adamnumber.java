import java.util.*;

class adamnumber{
    public static void main(String args[]){
        int adam;
        System.out.println("Enter any no to check weather it is an adam no or not: ");
        Scanner sc = new Scanner(System.in);
        adam = sc.nextInt();
        int numSq = adam * adam;
        int n= adam;
        int rev=0;
        int sqrev=adam*adam;
        while(n!=0){
            int d= n%10;
            rev=(rev*10)+d;
            n=n/10;
        }
        n= rev*rev;
        while(n!=0){
            int d= n%10;
            sqrev= (sqrev*10)+d;
            n=n/10;
        }
        if(sqrev==numSq)
        System.out.println("The entered no is not an Adam number: "+ adam);
        else
        System.out.println("Entered amount is  an Adam no");
    }
}