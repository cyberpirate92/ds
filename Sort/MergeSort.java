import java.util.Scanner;
public class MergeSort {
    public static void main(String[] args) {
        int size;
        int[] array;
        Scanner input = new Scanner(System.in);
        System.out.print("How many ? ");
        size = input.nextInt();
        array = new int[size];
        System.out.println("Enter "+size+" elements ");
        for(int i=0;i<size;i++) {
            System.out.print("\n"+(i+1)+" => ");
            array[i] = input.nextInt();
        }
        mergeSort(array);
        System.out.println("Sorted Array, ");
        for(int i=0; i<array.length; i++) {
            System.out.print("\t"+array[i]);
        }
        System.out.println("\n");
    }
    static void mergeSort(int[] array) {
        if(array.length > 1) {
            int mid = array.length/2;
            int[] leftHalf, rightHalf;

            leftHalf = splitArray(array, 0, mid);
            rightHalf = splitArray(array, mid, array.length);

            mergeSort(leftHalf);
            mergeSort(rightHalf);

            int i,j,k;
            i = j = k = 0;
            while(i < leftHalf.length && j < rightHalf.length) {
                if(leftHalf[i] < rightHalf[j])
                    array[k++] = leftHalf[i++];
                else
                    array[k++] = rightHalf[j++];
            }
            // if any elements are leftover, adding them too
            while(i < leftHalf.length)
                array[k++] = leftHalf[i++];
            while(j < rightHalf.length)
                array[k++] = rightHalf[j++];
        }
    }
    static int[] splitArray(int[] array, int from, int to) {
        int[] split = new int[to-from];
        for(int i=from,j=0; i<to; i++,j++) {
            split[j] = array[i];
        }
        return split;
    }
}
