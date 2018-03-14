def calculateString(self):
        self.strN=""
        self.strMID = ""
        self.strM = ""
        counterN = len(self.n)
        counterM = len(self.m)
        self.editCount = 0


        while(counterN >= 1 or counterM >= 1):

            diag = self.alignPt[counterN-1][counterM-1]
            left = self.alignPt[counterN-1][counterM]
            top = self.alignPt[counterN][counterM-1]

            if(counterN < 0):
                self.strN = ("-") + self.strN
                self.strM = (self.m[counterM-1]) + self.strM
                self.editCount += 1
                counterM -= 1
            elif(counterM < 0):
                self.strN = (self.n[counterN-1]) + self.strN
                self.strMID = (" ") + self.strMID
                self.strM = ("-") + self.strM
                self.editCount += 1
                counterN -= 1
            else:
                #found matching characters
                if(self.n[counterN-1] == self.m[counterM-1]):
                    self.strN=(self.n[counterN-1]) + self.strN
                    self.strMID = ("|") + self.strMID
                    self.strM = (self.m[counterM-1]) + self.strM
                    counterM -= 1
                    counterN -= 1
                #if diag is the smallest or equal to the other possibilities
                elif(diag <= left and diag <= top):
                    self.strN=(self.n[counterN-1]) + self.strN
                    self.strMID = (" ") + self.strMID
                    self.strM = (self.m[counterM-1]) + self.strM
                    self.editCount += 1
                    counterM -= 1
                    counterN -= 1
                elif (top < left):
                    self.strN = ("-") + self.strN
                    self.strMID = (" ") + self.strMID
                    self.strM = (self.m[counterM-1]) + self.strM
                    print (self.n[counterN-1],"<",self.m[counterM-1])
                    self.editCount += 1
                    counterM -= 1
                elif(top >= left):
                    self.strN=(self.n[counterN-1]) + self.strN
                    self.strMID = (" ") + self.strMID
                    self.strM = ("-") + self.strM
                    self.editCount += 1
                    print (self.n[counterN-1],">",self.m[counterM-1])
                    counterN -= 1

        self.editString = self.strN + "\n" + self.strMID + "\n" + self.strM