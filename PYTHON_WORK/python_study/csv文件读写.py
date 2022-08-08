import csv
"""CSV 表示“Comma-Separated Values（逗号分隔的值）”
CSV文件是简化的电子表格，保存为纯文本文件。"""
'''CSV 文件中的每行代表电子表格中的一行，逗号分割了该行中的单元格。'''

'''读'''

file = open('GBvideos.csv', encoding='utf-8')
file_reader = csv.reader(file)  # 传入文件对象， 创建一可迭代的reader对象
# Reader 对象只能循环遍历一次。要再次读取CSV 文件，必须调用csv.reader，创建一个对象。
print(file_reader.line_num)  # 0
for row in file_reader:
    print(file_reader.line_num)  # reader对象的line_num属性值随遍历的进行而改变
print(file_reader.line_num)  # 1601
file.close()


'''写'''

file = open('demo_csv.csv', 'w', encoding='utf-8', newline='')  # 如果你在open()中忘记了newline=''关键字参数，CSV 文件将有两倍行距
file_writer = csv.writer(file, delimiter='\t', lineterminator='\n\n')
# delimiter指定csv文件的分隔符， 默认为逗号','
# lineterminator每一行的分隔符，默认为'\n'

file_writer.writerow(['name', 'number', 'gender'])
file_writer.writerow((['syp', '218575', 'nan']))
file.close()
