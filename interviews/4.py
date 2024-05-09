# Предложить структуру данных, поддерживающую следующие операции: добавление по значению, удаление по значению, поиск по значению и GetRandomElement() (равномерный).
# /*
# Написать структуру данных, хранящую целые числа и поддерживающую следующие операции:
# 1) добавление значения в множество
# 2) проверка есть ли значение в множестве
# 3) удаление значения из множества
# 4) получение случайного значения из множества.
# */
class Randomizer:
    nums = set()
    arr = []
    dct = dict()

    def insert(self, num: int):
        if num not in nums:
            nums.add(num)
            arr.append(num)
            dct[num] = len(nums_array) - 1
    
    def find(self, num: int) -> bool:
        return num in nums

    def remove(self, num: int):
        if num in nums:
            nums.discard(num)
            index = dct[num]
            del nums_dict[num]
            arr[index] = arr[-1]
            dct[arr.pop()] = index


    def get_random(self) -> int:
        return random.choice(arr)