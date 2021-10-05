import java.util.Arrays;
import java.util.Scanner;

public class FerrisWheel {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int max = sc.nextInt();
        sc.nextLine();
        int[] arr = new int[n];
        boolean[] found = new boolean[n];
        for(int i = 0 ; i < n; i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int ans = 0 ;
        int i = 0;
        int j = n - 1;
        while( i < j){

                if(arr[i] + arr[j] > max ){
                    j--;
                }
                else{
                    ans++;
                    found[i] = found[j] = true;
                    i++;
                    j--;
                }
            }
            for(boolean b : found){
                ans += (b  ? 0 : 1);
            }
            System.out.println(ans);
        }
    }
