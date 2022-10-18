class longestSubstring_3 {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> substring_char = new HashMap<Character, Integer>();
        int start_idx = 0;
        int end_idx = 0;
        int max_length = 0;

        while(end_idx < s.length()) {
            if(substring_char.containsKey(s.charAt(end_idx))) {
                int last_appear_idx = substring_char.get(s.charAt(end_idx));
                start_idx =Math.max(last_appear_idx + 1, start_idx);
            }
            substring_char.put(s.charAt(end_idx), end_idx);
            max_length = Math.max(end_idx - start_idx + 1, max_length);
            end_idx++;
        }
        return max_length;
    }
}
