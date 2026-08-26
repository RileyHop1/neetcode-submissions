class Solution:
    def isValid(self, s: str) -> bool:
        pars = {
            '}': '{',
            ')': '(',
            ']': '[',
        }

        stack = list()
        
        for i in s:
            print(stack)
            if i not in pars.keys():
                stack.append(i)
            else:
                if not stack or pars.get(i) != stack.pop():
                    return False

        if  not stack:
            return True
        else:
            return False 


