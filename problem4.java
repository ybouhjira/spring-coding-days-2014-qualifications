import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author ybouhjira
 */
public class Table_addition {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scn = new Scanner(new File("add.in"));
        FileWriter writer = new FileWriter("add.out");
        int matrixCount = scn.nextInt();

        int lineNumber = 1;

        for (int i = 0; i < matrixCount; i++) {
            int matrixSize = scn.nextInt();

            ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();
            ArrayList<Integer> resRow = new ArrayList<>();

            // read lines
            boolean oui = true;

            for (int j = 0; j < matrixSize; j++) {
                ArrayList<Integer> row = new ArrayList<>();
                matrix.add(row);
                for (int k = 0; k < matrixSize; k++) {
                    row.add(scn.nextInt());
                }

                for (int k = 0; k < row.size(); k++) {
                    if (k == 0) { // first time
                        for (int l = 0; l < row.size() - 1; l++) {
                            resRow.add(row.get(l) - row.get(l + 1));
                        }
                    } else {
                        for (int l = 0; l < row.size() - 1; l++) {
                            if (resRow.get(l) != row.get(l) - row.get(l + 1)) {
                                oui = false;
                                break;
                            }
                        }
                    }
                }
            }
            writer.write(String.valueOf(lineNumber) + ". " + (oui ? "OUI" : "NON") + '\n');
            lineNumber++;
        }
        writer.close();
    }
}
