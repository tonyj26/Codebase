import sys


class editDist():

    def dist(self, str1, str2):
        n = len(str1)
        m = len(str2)

        # creates the matrix to store the value differentials
        dp = [[0 for x in range(m+1)] for x in range(n+1)]

        for i in range(n+1):
            for j in range(m+1):
                if i == 0:
                    # first string is empty
                    dp[i][j] = j

                elif j == 0:
                    # second string is empty
                    dp[i][j] = i

                elif str1[i-1] == str2[j-1]:
                    # last character is the same, ignore it
                    dp[i][j] = dp[i-1][j-1]

                else:
                    # this is where the magic happens
                    dp[i][j] = 1 + min(
                            dp[i][j-1],     # insert
                            dp[i-1][j],     # remove
                            dp[i-1][j-1])   # replace

        strTop = ""
        strMid = ""
        strBot = ""

        # This backtracks to align the text
        # writes the string starting from the end of it
        # goes right to left
        while(n > 0 and m > 0):
            # sets a tracker on the matrix to see whether
            # what character to insert into the string
            diag = dp[n-1][m-1]
            left = dp[n-1][m]
            top = dp[n][m-1]

            # end of string 1
            if(n == 0):
                # appends to beginning of string
                strTop = "-" + strTop
                strBot = str2[m-1] + strBot
                m -= 1
                # end of string 2
            elif(m == 0):
                strTop = str1[n-1] + strTop
                strMid = " " + strMid
                strBot = "-" + strBot

            else:
                # last characters are the same, align them and add
                # both to string
                if (str1[n-1] == str2[m-1]):
                    strTop = str1[n-1] + strTop
                    strMid = "|" + strMid
                    strBot = str2[m-1] + strBot
                    n -= 1
                    m -= 1

                elif(diag <= left and diag <= top):
                    # this runs if it's best to replace the character
                    strTop = str1[n-1] + strTop
                    strMid = " " + strMid
                    strBot = str2[m-1] + strBot
                    n -= 1
                    m -= 1

                elif(top < left):
                    # insert or remove character from top string
                    strTop = "-" + strTop
                    strMid = " " + strMid
                    strBot = str2[m-1] + strBot
                    m -= 1

                elif(top >= left):
                    # insert or remove character from bottom string
                    strTop = str1[n-1] + strTop
                    strMid = " " + strMid
                    strBot = "-" + strBot
                    n -= 1

        print("optimal alignment: ")

        while (len(strTop) > 60):
            print('\n' + strTop[0:60] + '\n' + strMid[0:60] +
                  '\n' + strBot[0:60])
            strTop = strTop[60:]
            strMid = strMid[60:]
            strBot = strBot[60:]

        # formats the output and prints it
        print('\n' + strTop + "\n" + strMid + "\n" + strBot + '\n')
        print("edit distance = " + str(dp[len(str1)][len(str2)]))
        print('\n')


str1 = ""
str2 = ""

with open(sys.argv[1], 'r') as myFile:
    str1 = myFile.read().replace('\n', ' ')

with open(sys.argv[2], 'r') as myFile:
    str2 = myFile.read().replace('\n', ' ')

foo = editDist()

foo.dist(str1, str2)
