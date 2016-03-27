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
    Permute all the characters of the string a from index begin through end
    '''
    if begin == end :                                       #all characters permutted
        print a               
    else :
        for index in range(begin, end + 1):           #permute the beginetters from index a[begin] to a[end]
            a = swap(a, index, begin)                   #swap the current element with the index-th element
            permutations(a, begin + 1, end)          #keep the current element fixed, permute the rest of the elements
            a = swap(a, index, begin)                   # [BACKTRACK] swap back the index-th element with the current element

permutations('ABC', 0, 2)

'''
Level 1:
permutations('ABC', 0, 2):
	
	index = 0
	swap 'A' with 'A'--> 'ABC'
	permutations('ABC', 1, 2)
	swap back 'A' with 'A'--> 'ABC'
	
	index = 1
	swap 'A' with 'B'-->'BAC'
	permutations('BAC', 1, 2)
	swap back 'B' with 'A'--> 'ABC'
	
	index = 2
	swap 'A' with 'C'-->'CBA'
	permutations('CBA', 1, 2)
	swap back 'C' with 'A'--> 'ABC'
	
Level 2:
permutations('ABC', 1, 2):
	
	index = 1
	swap 'B' with 'B'-->'ABC'
	permutations('ABC', 2, 2)--> print 'ABC'
	swap back 'B' with 'B'--> 'ABC'
	
	index = 2
	swap 'B' with 'C'-->'ACB'
	permutations('ACB', 1, 2)--> print 'ACB'
	swap back 'C' with 'A'--> 'ABC'
	
permutations('BAC', 1, 2):
	
	index = 1
	swap 'A' with 'A'-->'BAC'
	permutations('BAC', 2, 2)--> print 'BAC'
	swap back 'A' with 'A'--> 'BAC'
	
	index = 2
	swap 'A' with 'C'-->'BCA'
	permutations('BCA', 1, 2)--> print 'BCA'
	swap back 'C' with 'A'--> 'BCA'

permutations('CBA', 1, 2):
	
	index = 1
	swap 'B' with 'B'-->'CBA'
	permutations('CBA', 2, 2)--> print 'CBA'
	swap back 'B' with 'B'--> 'CBA'
	
	index = 2
	swap 'B' with 'A'-->'CAB'
	permutations('CAB', 1, 2)--> print 'CAB'
	swap back 'A' with 'B'--> 'CBA'
'''

'''
Time complexity :
Printing n characters in the base case [ O(n) ] * for each case (n-1)! operations [ O((n-1)!) = O(n!)]
Hence, T(n) = O(n * n!)
'''
