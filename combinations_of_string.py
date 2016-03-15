from sys import stdout                              #for printing characters without space

def combinations(a):
    '''
    Calculate the various combinations of a string (order does not matter)
    '''
    powersetlen = 1 << len(a)                       #length of power set[2 ^ length of set]
    setlen = len(a)
    for bitcount in range(1, powersetlen):       #find bitcount
        for index in range(setlen):
            if (1 << index) & bitcount:               #if index-th bit is set in bitcount
                stdout.write(a[index])                 #print index-th element for this subset - without a space
        print "\n"                                           #print separator for subsets

combinations("ABC")

'''
a = "ABC"
powersetlen = 1 << 3 = 8
Bitcount : 000 to 111

Bitcount            Subset

000(0)                Empty set
001(1)                A
010(2)                B
011(3)                AB
100(4)                C
101(5)                AC
110(6)                BC
111(7)                ABC
'''

'''
Time complexity :
Loop : bitcount - O(2 ^ n)
Loop : index - O(n)
Hence, T(n) = O(n * 2 ^ n)
'''
