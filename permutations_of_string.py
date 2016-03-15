def swap(a, i, j):
    '''
    Swap two characters in a string
    Since string swapping is not possible, hence we need to convert it into a list
    '''
    s = list(a)               #convert string to list
    s[i], s[j] = s[j], s[i]  #swap two characters
    return "".join(s)       #convert list to string

def permute(a, l, r):
    '''
    Permute all the characters of the string a from index l through r
    '''
    if l == r :                #all characters permutted
        print a               
    else :
        for i in range(l, r + 1):   #permute the letters from index a[l] to a[r]
            a = swap(a, i, l)       #swap the current element with the ith element
            permute(a, l + 1, r)   #keep the current element fixed, permute the rest of the elements
            a = swap(a, i, l)       # [BACKTRACK] swap back the ith element with the current element


'''
Time complexity :
Printing n characters in the base case [ O(n) ] * for each case (n-1)! operations [ O((n-1)!) = O(n!)]
Hence, T(n) = O(n * n!)
'''

permute('ABC', 0, 2)

'''Output:
ABC
ACB
BAC
BCA
CBA
CAB
'''
