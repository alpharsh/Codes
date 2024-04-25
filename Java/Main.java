import java.util.Scanner;

class Person {
    String name;
    int age;

    // Constructor
    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Name: ");
        String name = scanner.nextLine();

        System.out.println("Enter Age: ");
        int age = scanner.nextInt();

        Person xperson = new Person(name, age);

        System.out.println(xperson.name);  
        System.out.println(xperson.age);
    }
}