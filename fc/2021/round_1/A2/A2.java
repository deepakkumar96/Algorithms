import java.io.*;
import java.util.StringTokenizer;
public class A2 {
  final static long MOD = 1000000007;
  public static void main(String[] args) throws Exception {
    FastScanner sc = new FastScanner(1);
    int totalTestCases = sc.nextInt();
    for (int testCase = 1; testCase <= totalTestCases; testCase++) {
      int N = sc.nextInt();
      String str = sc.next();
      System.out.println("Case #" + testCase + ": " + solve(str));
    }
  }
  private static long solve(String s) {
    long count = 0;
    int currLastCharIdx = -1;
    char currLastChar = '.';
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) != 'F') {
        if (currLastCharIdx == -1) {
          currLastChar = s.charAt(i);
          currLastCharIdx = i;
        } else if (s.charAt(i) == currLastChar) {
          currLastCharIdx = i;
        } else {
          count = (count + (((currLastCharIdx + 1) * (s.length() - i)) % MOD)) % MOD;
          currLastChar = s.charAt(i);
          currLastCharIdx = i;
        }
      }
    }
    return count;
  }
  static class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    FastScanner() throws FileNotFoundException {
      br = new BufferedReader(new InputStreamReader(System.in));
    }
    FastScanner(int a) throws FileNotFoundException {
      br = new BufferedReader(new FileReader("/home/deepak/Documents/open_source/My/Algorithms/fc/2021/round_1/A2/input.txt"));
    }
    String next() throws IOException {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }
    int nextInt() throws IOException {
      return Integer.parseInt(next());
    }
    long nextLong() throws IOException {
      return Long.parseLong(next());
    }
    double nextDouble() throws IOException {
      return Double.parseDouble(next());
    }
    String nextLine() throws IOException {
      String str = "";
      try {
        str = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return str;
    }
  }
}
