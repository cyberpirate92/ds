/*
 * Insertion sort uses an incremental approach
 * The left side of the array gets sorted incrementally
 * until the entire array is sorted
 */

class InsertionSort {
    public static void main(String[] args) {
        int[] testData = {10, 50, 20, 40, 30};
        print(sort(testData));
    }

    public static int[] sort(int[] data) {
        int j;
        for(int i=1; i<data.length; i++) {
            int key = data[i];
            for(j=i-1; j>=0 && data[j] > key; j--) {
                data[j+1] = data[j];
            }
            data[j+1] = key;
        }
        return data;
    }

    public static void print(int[] a) {
        System.out.print("[ ");
        for(int i=0; i<a.length; i++) {
            System.out.print(a[i]);
            if(i != a.length-1)
                System.out.print(", ");
        }
        System.out.println(" ]");
    }
}
