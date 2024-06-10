public class ComplexNumber {
    private double real;
    private double imaginary;

    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary; //Initialized the imaginary field in the constructor.
    }

    public ComplexNumber add(ComplexNumber other) {
        double newReal = this.real + other.real;
        double newImaginary = this.imaginary + other.imaginary;
        return new ComplexNumber(newReal, newImaginary);
    }

    public String toString() {
        return real + " + " + imaginary + "i";
    }

    public static void main(String[] args) {
        ComplexNumber num1 = new ComplexNumber(3, 2);
        ComplexNumber num2 = new ComplexNumber(1, -4);
        ComplexNumber sum = num1.add(num2);
        System.out.println("Sum of complex numbers: " + sum);
    }
}