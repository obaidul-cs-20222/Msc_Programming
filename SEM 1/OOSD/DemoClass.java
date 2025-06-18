
/*
 * Create a file that contains a set of random numbers - one number per line.
 * Create a class named RandomNumber that stores a subset of these random
 * numbers in an ArrayList.
 * Now write a class that maintains a pool of RandomNumber objects where the
 * random numbers of the file are distributed.
 * Your implementation should be capable of changing the pool size dynamically.
 * Create DemoClass to demonstrate your implementation.
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class DemoClass {
    public static void main(String[] args) throws FileNotFoundException {
        RandomNumberPool pool = new RandomNumberPool("random_numbers.txt", 5);
        System.out.println("Initial pool size: " + pool.pool.size());
        System.out.println("Random numbers: " + pool.getRandomNumbers(10));
        pool.setPoolSize(3, "random_numbers.txt");
        System.out.println("New pool size: " + pool.pool.size());
        System.out.println("Random numbers: " + pool.getRandomNumbers(10));
    }
}

class RandomNumber {
    private List<Integer> numbers;

    public RandomNumber(String fileName) throws FileNotFoundException {
        numbers = new ArrayList<>();
        Scanner scanner = new Scanner(new File(fileName));
        while (scanner.hasNextInt()) {
            numbers.add(scanner.nextInt());
        }
        scanner.close();
    }

    public List<Integer> getSubset(int size) {
        List<Integer> subset = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            subset.add(numbers.get(random.nextInt(numbers.size())));
        }
        return subset;
    }
}

class RandomNumberPool {
    List<RandomNumber> pool;

    public RandomNumberPool(String fileName, int poolSize) throws FileNotFoundException {
        pool = new ArrayList<>();
        for (int i = 0; i < poolSize; i++) {
            pool.add(new RandomNumber(fileName));
        }
    }

    public List<Integer> getRandomNumbers(int size) {
        List<Integer> numbers = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            RandomNumber randomNumber = pool.get(random.nextInt(pool.size()));
            numbers.add(randomNumber.getSubset(1).get(0));
        }
        return numbers;
    }

    public void setPoolSize(int poolSize, String fileName) throws FileNotFoundException {
        if (poolSize < 1) {
            throw new IllegalArgumentException("Pool size must be at least 1");
        }
        pool.clear();
        for (int i = 0; i < poolSize; i++) {
            pool.add(new RandomNumber(fileName));
        }
    }
}
