class Solution:
    def isValid(self, s: str) -> bool:
        lis = []

        for ch in s:
            if ch in "({[":
                lis.append(ch)
            else:
                if not lis:
                    return False

                if ((lis[-1] == "(" and ch == ")") or
                    (lis[-1] == "{" and ch == "}") or
                    (lis[-1] == "[" and ch == "]")):
                    lis.pop()
                else:
                    return False

        return len(lis) == 0