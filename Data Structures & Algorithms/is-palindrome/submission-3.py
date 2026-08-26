class Solution:
    def isPalindrome(self, s: str) -> bool:
        word = s.replace(" ", "").lower()
        length = len(word)
        half = int(length/2)

        i = 0
        j = length -1

        while i < j:

            if not word[i].isalpha() and not word[i].isdigit():
                i += 1
                continue
            if not word[j].isalpha() and not word[j].isdigit():
                j -= 1 
                continue

            if word[i] != word[j]:
                return False

            i += 1
            j -= 1
        return True            



