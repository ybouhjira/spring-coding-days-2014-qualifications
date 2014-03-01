import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Problem1 {

    public static void main(String arg[]) throws FileNotFoundException, IOException {

        if (isDivisbleBy11("8123456")) {
            System.out.println("ok");
        } else {
            System.out.println("no");
        }

        Scanner scn = new Scanner(new File("smartphone.in"));

        FileWriter writer = new FileWriter("smartphone.out");

        int line  = 1;
        String number = "a";
        while (!"0".equals(number)) {
            number = scn.nextLine();
            if ("0".equals(number)) {
                break;
            } else {
                String result = getResult(number);
                BigInteger value = new BigInteger(result);
                if (String.valueOf(value.divide(new BigInteger("11"))).length() != number.length() || result.equals("impossible")) {
                    writer.write((line++) + ". impossible\n");
                } else {
                    writer.write((line++) + ". "+ String.valueOf(value.divide(new BigInteger("11"))) + "\n");
                }

            }
        }

        writer.close();
    }

    public static String getResult(String number) {
        if (number.length() >= 1000) {
            return isDivisbleBy11(number) ? number : "impossible";
        } else {
            if (!isDivisbleBy11(number)) {
                ArrayList<Integer> list = new ArrayList<Integer>();
                for (int i = 1; i <= 9; i++) {
                    if (isDivisbleBy11(i + number)) {
                        return i + number;
                    }
                    list.add(i);
                }

                while (list.size() != 0) {
                    int i = list.remove(0);
                    String result = getResult(i + number);
                    if (result != "impossible") {
                        return result;
                    }
                }
                return "impossible";
            } else {
                return number;
            }
        }
    }

    public static boolean isDivisbleBy11(String number) {
        if (number.length() > 2) {
            int sum = 0;
            boolean negative = false;
            for (int i = number.length() - 1; i >= 0; i--) {
                sum += Integer.parseInt(String.valueOf(number.charAt(i)))
                        * ((negative) ? -1 : 1);
                negative = !negative;
            }
            return sum % 11 == 0;
        } else {
            return Integer.parseInt(number) % 11 == 0;
        }
    }
}
