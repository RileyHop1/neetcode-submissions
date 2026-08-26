class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        groups = dict(list())

        for word in strs:
            st = "".join(sorted(word))

            if st in groups:
                #print(word)
                groups[st].append(word)
                continue
            groups[st] = [word]

        #print(groups)

        returned = list()

        for i in groups:
            print(groups[i])
            returned.append(groups[i])

        print(returned)

        return returned