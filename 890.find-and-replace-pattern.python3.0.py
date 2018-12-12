class Solution:
    def pattern_finder(word):
        pattern_map = dict()
        counter = 0
        out = list()
        for char in word:
            if char not in pattern_map:
                pattern_map[char] = counter
                counter += 1
            out.append(pattern_map[char])
        return out

    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        out = list()
        template_pattern = Solution.pattern_finder(pattern)
        for word in words:
            if template_pattern == Solution.pattern_finder(word):
                out.append(word)
        return out
