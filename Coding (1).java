import java.io.*;
import java.util.*;

class Codechef {

   
    // Custom input reader class for fast input
    static class In {
        BufferedReader br;
        StringTokenizer st;

        // It initializes BufferedReader and empty tokenizer
        In() {
            br = new BufferedReader(new InputStreamReader(System.in));
            st = new StringTokenizer("");
        }

        // Reads the next token (word/number) from input
        String next() throws Exception {
            while (!st.hasMoreTokens()) {
                String l = br.readLine();
                if (l == null) return null;      
                // End ofs InputStreamReader
                if (l.trim().isEmpty()) continue; 
                
                // Skip empty lines
                st = new StringTokenizer(l);      
                // Tokenize the line
            }
            return st.nextToken();
            
        }

        // Reads next integer
        int ni() throws Exception {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) throws Exception {
        In in = new In(); // Create input reader

        int T = in.ni();  // Number of test cases

        StringBuilder sb = new StringBuilder(); // Collect results for all test case
        while (T-- > 0) {

            int n = in.ni(), k = in.ni(); // Read n (length of string) and k 
            
            

            String s = in.next(); // Binary string input

            int ones = 0;
            // Count total number of '1's in the string
            for (char c : s.toCharArray()) 
                if (c == '1') ones++;

            int min = 0, odd = 0;

            // Iterate over each residue class modulo k
            for (int r = 0; r < k; r++) {
                int len = 0;

                // Count how many positions belong to this residue class
                for (int p = r; p < n; p += k) len++;

                if (len == 0) continue;

               
                min += len / 2;

                // If length is odd, flexibility 
                if ((len & 1) == 1) odd++;
            }

            // Check if total ones fall within the feasible range
            
            sb.append((ones >= min && ones <= min + odd) ? "Yes" : "No").append('\n');
        }

       
        System.out.print(sb.toString());
    }
}
