import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        int numero = 0;
        
        while(input.hasNext()){

            numero = input.nextInt();
            if(numero == 0){
                System.out.println("vai ter copa!");
            }else if(numero > 0){
                System.out.println("vai ter duas!");  
            }
            
        }
        
    }
    
}
