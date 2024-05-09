#
 # Для двух массивов целых чисел длины N, для всех K от 1 до N,
 # посчитать количество общих чисел на префиксах длины K.
 # 
 # doIt([1,1,2,3], [2,1,3,1]) == [0,1,2,3]
# [1, 2] [2, 1] = 2
# [1, 1], { 1}
# [1, 2]  {1, 2}
# [1, 1]
# counter = [0, 1, 2, 3]
# { 1 1 2 3 
# { 2 1 3 1

# [1,1] {1}
# [1,1] {1}

def doIt(arr1, arr2):
    set1 = set()
    set2 = set()
    counter = 0
    result = []
    for i1, i2 in zip(arr1, arr2):
        if i1 in set1 and i1 in set2:
            counter += 0
        elif i1 in set2:
            counter += 1
        set1.add(i1)
        if i2 in set1 and i2 in set2:
            counter += 0
        elif i2 in set1:
            counter += 1
        set2.add(i2)

        result.append(counter)
    return result



# K = 1
# [1]
# [2]
#
# K = 2
# [1,1]
# [2,1]