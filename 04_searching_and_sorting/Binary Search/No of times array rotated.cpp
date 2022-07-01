public static void main(String[] args) {
        int[] arr = {11,12,15,18,21,25,5,6,8};

        int ans = findPivot(arr);
        System.out.println(ans);

    }

    static int findPivot(int[] arr){
        int start = 0;
        int end = arr.length - 1;


        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid + 1]){
                return mid + 1;
            }

            if(arr[mid] <= arr[start]){
                end = mid - 1;
            }else{
                start = mid+1;
            }
        }
            return -1;

    }