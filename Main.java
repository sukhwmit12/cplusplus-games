/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package a3;
import java.util.Scanner;
/**
 *
 * @author SSKAHLON
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {


        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if(n%2==0){
        if(2<=n&&n<=5)
        System.out.println("Not Weird");
        if(6<=n&&n<=20)
        System.out.println("Weird");
        if(21<=n)
        System.out.println("Not Weird");}
        if(n%2!=0)
        System.out.println("Weird");

}

        
    

}
