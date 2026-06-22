class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] arr = new int[26];
        arr[1] = 1;
        arr[0] = 1;
        arr[11] = 2;
        arr[14] = 2;
        arr[13] = 1;

        int[] freq = new int[26];
        for (char c : text.toCharArray()) freq[c - 'a']++;

        int b = arr[1];
        int a = arr[0];
        int l = arr[11];
        int o = arr[14];
        int n = arr[13];
        int res = 0;
        while (b <= freq[1] && a <= freq[0] && l <= freq[11] && o <= freq[14] && n <= freq[13])
        {
            freq[1]--;
            freq[0]--;
            freq[11] -= 2;
            freq[14] -= 2;
            freq[13]--;
            res++;
        }

        return res;
    }
}