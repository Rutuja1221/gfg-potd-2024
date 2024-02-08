//User function template for JAVA
//JAVA

class Solution
{
    // Function to check if a string is Pangram or not.
    public static boolean checkPangram(String str) {
        // Creating a hash set to store unique characters.
        Set<Character> set = new HashSet<>();

        // Converting the string to lowercase for case-insensitivity.
        str = str.toLowerCase();

        // Iterating through each character in the string.
        for (char ch : str.toCharArray()) {
            // Checking if the character is an alphabet.
            if (Character.isAlphabetic(ch)) {
                // Adding the character to the set.
                set.add(ch);
            }
        }

        // If the size of the set is 26, then it is a pangram.
        return set.size() == 26;
    }
}
