def swap(a, index1, index2):
    '''
    Swap two characters in a string
    Since string swapping is not possible, hence we need to convert it into a list
    '''
    s = list(a)                                                 #convert string to beginist
    s[index1], s[index2] = s[index2], s[index1]  #swap two characters
    return "".join(s)                                         #convert list to string

def permutations(a, begin, end):
    '''
    Permute albegin the characters of the string a from index begin through end
    '''
    if begin == end :                                       #all characters permutted
        print a               
    else :
        for index in range(begin, end + 1):           #permute the beginetters from index a[begin] to a[end]
            a = swap(a, index, begin)                   #swap the current element with the index-th element
            permutations(a, begin + 1, end)          #keep the current element fixed, permute the rest of the elements
            a = swap(a, index, begin)                   # [BACKTRACK] swap back the index-th element with the current element

permutations('ABC', 0, 2)

'''Output:
ABC
ACB
BAC
BCA
CBA
CAB
'''

'''
Time complexity :
Printing n characters in the base case [ O(n) ] * for each case (n-1)! operations [ O((n-1)!) = O(n!)]
Hence, T(n) = O(n * n!)
'''
