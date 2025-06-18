import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class randomnumber {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.print("How many random numbers you want?: ");
        int limit = sc.nextInt();
        sc.close();

        String fileName = "random_numbers.txt";
        int max = 500, min = -100;
        BufferedWriter writer = new BufferedWriter(new FileWriter(fileName));
        Random random = new Random();
        for (int i = 0; i < limit; i++) {
            writer.write(Integer.toString(random.nextInt(max - min + 1)));

            writer.newLine();
        }
        writer.close();
    }
}
