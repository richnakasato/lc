class Solution:
    def helper(self, graph, pos, end, cur_path, paths):
        new_path = cur_path[:] + [pos]
        if pos == end:
            paths.append(new_path)
        else:
            moves = graph[pos]
            for move in moves:
                self.helper(graph, move, end, new_path, paths)

    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        if not graph or len(graph) < 2:
            return [[0]]
        else:
            start = 0
            end = len(graph)-1
            cur_path = list()
            paths = list()
            self.helper(graph, start, end, cur_path, paths)
            return paths

def main():
    pass

if __name__ == "__main__":
    main()

