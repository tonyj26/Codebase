

class MaxSub():
    def __init__(self, A):
        self.arr = A

    def max(self):
        M = [0]

        for t in range(1,len(A)-1):
            if(M[t-1] + A[t]
