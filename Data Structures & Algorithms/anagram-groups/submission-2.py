class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        groups = dict(list())
        returned = list()

        for word in strs:
            st = "".join(sorted(word))

            if st in groups:
                groups[st].append(word)
                continue
            groups[st] = [word]


        for i in groups:
            print(groups[i])
            returned.append(groups[i])


        return returned