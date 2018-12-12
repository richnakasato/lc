class Solution:
    def helper(self, moves, steps, curr, end, path, results):
        if steps == 0 and end == 0:
            results.append(path)
        elif curr < len(moves) and steps and end:
            new_path = path[:] + [moves[curr]]
            new_end = end - moves[curr]
            new_steps = steps - 1
            for new_move in range(curr+1, len(moves)+1):
                self.helper(moves, new_steps, new_move, new_end, new_path, results)

    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        moves = [x for x in range(1, 10)]
        steps = k
        end = n
        new_path = list()
        results = list()
        for start in range(len(moves)):
            self.helper(moves, steps, start, end, new_path, results)
        return list(set([tuple(l) for l in results]))


def main():
    pass

if __name__ == "__main__":
    main()

