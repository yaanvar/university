from collections import OrderedDict
import re


def main(table):
    table = [[i for i in row if i is not None] for row in table]
    ans = []
    for i in range(len(table)):
        table[i] = list(OrderedDict.fromkeys(table[i]))
        if table[i] == []:
            continue
        for j in range(len(table[i]) + 1):
            if table[i][j][0] == '0':
                table[i][j] = str(round(float(table[i][j]) * 100)) + '%'
            elif ':' in table[i][j]:
                res = table[i][j].split(':')
                table[i][j] = re.sub(r'\)|\(|(\+7)|\-', '', res[0])
                table[i].insert(2, 'Y' if res[-1] == 'Выполнено' else 'N')
        res = table[i][1].split()
        table[i][1] = res[-1][:2] + ' ' + res[0]

        ans.append(table[i])
    return ans


print(main(([['+7(948)305-24-65:Выполнено', 'Зотафман М.А.', '0.6772', None, None, '0.6772'], ['+7(934)409-03-93:Не выполнено', 'Вацяк А.Ш.', '0.3079', None, None, '0.3079'], ['+7(495)052-59-75:Выполнено', 'Миширов В.А.', '0.7068', None, None, '0.7068'], [None, None, None, None, None, None], ['+7(753)087-34-16:Не выполнено', 'Васберг М.Ф.', '0.5044', None, None, '0.5044']])))