import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

class MainArrayList {
    ArrayList<String> arr = new ArrayList<String>();
}

class Slices {
    int l, u, a;
    int range;
    String eachSliceArr[];
    ArrayList<String> arr = new ArrayList<String>();

    public Slices(int l, int u, ArrayList<String> arr) {
        this.l = l;
        this.u = u;
        this.arr = arr;

        range = u - l + 1;
        eachSliceArr = new String[range];
        a = 0;
        for (int i = l; i <= u && i < arr.size(); i++) {
            eachSliceArr[a++] = arr.get(i);

        }
    }

    void printSlice() {
        System.out.println("The slice is:");
        for (int i = 0; i < range; i++) {
            System.out.print(eachSliceArr[i] + " ");
        }
        System.out.println();
    }
}

class OtherTasks extends MainArrayList {
    int flag = 0;
    String data;

    public void ReadFile() {
        try {
            File fileObj = new File("random_numbers.txt");
            Scanner f = new Scanner(fileObj);
            while (f.hasNextLine()) {
                data = f.nextLine();
                arr.add(data);
            }
            f.close();
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found!");
            e.printStackTrace();
        }
    }

    public void CreateArrayOfObjects(int l, int u) {
        ArrayList<Slices> slc = new ArrayList<Slices>();
        if (slc.isEmpty()) {
            slc.add(new Slices(l, u, arr));
            slc.get(slc.size() - 1).printSlice();
        } else {
            for (int i = 0; i < slc.size(); i++) {
                if (slc.get(i).u == u && slc.get(i).l == l) {
                    flag = 1;
                    slc.get(i).printSlice();
                }
            }
            if (flag == 0) {
                slc.add(new Slices(l, u, arr));
                slc.get(slc.size() - 1).printSlice();
            }
        }
        // Reset flag after each iteration
        flag = 0;
    }
}

public class RNumber {
    public static void main(String args[]) {
        int l, u;
        OtherTasks OTObj = new OtherTasks();
        OTObj.ReadFile();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter lower and upper range of the slice: ");
        l = sc.nextInt();
        u = sc.nextInt();
        OTObj.CreateArrayOfObjects(l, u);
        sc.close();
    }
}