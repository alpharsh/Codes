import java.util.*;
class Matrix{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int mat[][] = new int[100][100];
        int Size = sc.nextInt();
        for(int i=0;i<Size;i++)
        for(int j=0;j<Size;j++){
            System.out.println("Enter the element at "+i+" "+j);
            mat[i][j] = sc.nextInt();
        }

        
System.out.println("Unsorted matrix");
        for(int i=0;i<Size;i++) {
            for(int j=0;j<Size;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }

        for(int i=0;i<Size;i++)
        {
            int min = mat[i][0];
                System.out.print(min+ "(1)   ");
            for (int j = i + 1; j < Size; j++) {
                if (min > mat[i][j]) {
                    int temp = mat[i][j];
                    mat[i][j] = min;
                    min = temp;
                }
                System.out.print(min+ "(2)   ");
            }
        }

System.out.println("Sorted matrix");
        for(int i=0;i<Size;i++){
        for(int j=0;j<Size;j++){
            System.out.print(mat[i][j]+" ");
            
        }System.out.println();}


    int new1[] = new int[Size*Size];
    int c =0;
    for(int i=0;i<Size;i++){
        for(int j=0;j<Size;j++){
            new1[c]= mat[i][j];
            c++;
        }
    }
    Arrays.sort(new1);
        System.out.println();
        int l =0;
        for (int num : new1) {
            System.out.print(num + " ");l++;
            if(l%Size==0 && l!=0) System.out.println();
            
        }
    }
}

