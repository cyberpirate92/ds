/*
 *
 * Find smallest element in sub-array, swap with current index
 * increment index, follow previous step until n-1
 */

class SelectionSort {
    public static void main(String[] args) {
        int[] testData = {10, 50, 20, 40, 30};
        print(sort(testData));
    }

    public static int[] sort(int[] a) {
        int minIndex, minVal;
        for(int i=0; i<a.length-1; i++) {
            minVal = a[i];
            minIndex = i;
            for(int j=i+1; j<a.length; j++) {
                if(minVal > a[j]) {
                    minIndex = j;
                    minVal = a[j];
                }
            }
            if(minIndex != i) {
                a[minIndex] = a[i];
                a[i] = minVal;
            }
        }
        return a;
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
