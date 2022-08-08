class System:
    __names = []
    __genders = []
    __student_nums = []

    def __init__(self, school_name):
        self.school_name = school_name

    def check(self, name):
        if name in self.__names:
            __Indexes = self.__names.index(name)
            print(f'name:{name}\ngender:{self.__genders[__Indexes]}\nstudent number:{self.__student_nums[__Indexes]}')
        else:
            print('姓名输入错误')

    def check_all(self):
        for i in range(len(self.__names)):
            print(f'姓名：{self.__names[i]}\t性别：{self.__genders[i]}\t学号：{self.__student_nums[i]}')

    def add(self, name, gender, num):
        if type(num) == int\
                and (gender == '男' or gender == '女')\
                and len(str(num)) == 12\
                and name not in self.__names\
                and num not in self.__student_nums:
            self.__names.append(name)
            self.__genders.append(gender)
            self.__student_nums.append(num)
            print('信息已成功添加')
        else:
            print('请检查输入并重试')

    def modify(self, name):
        self.check(name)
        __Indexes = self.__names.index(name)
        input1 = input('是否修改姓名（y/n）\n')
        if input1 == 'y':
            input_i = input('姓名修改为：')
            self.__names[__Indexes] = input_i
            print(f'已成功修改{name}为{input_i}')
        else:
            print('未修改姓名')
        input2 = input('是否修改性别（y/n）\n')
        if input2 == 'y':
            if self.__genders[__Indexes] == '男':
                self.__genders[__Indexes] = '女'
            else:
                self.__genders[__Indexes] = '男'
            print('性别已更改')
        else:
            print('未修改性别')
        input3 = input('是否修改学号（y/n）\n')
        if input3 == 'y':
            input_i = int(input('请输入新学号：'))
            self.__student_nums[__Indexes] = input_i
            print('学号已修改')
        else:
            print('未修改学号')

    def function(self):
        print('你已进入学生信息管理系统')
        input1 = eval(input('请选择你要使用的功能：1，查看学员信息 2，添加学员信息 3，修改学员信息 4，查看所有学员信息\n'))
        if input1 == 1:
            input_i = input('请输入学员姓名：')
            self.check(input_i)
        elif input1 == 2:
            input_1 = input('请输入姓名：')
            input_2 = input('请输入性别：')
            input_3 = int(input('请输入学号：'))
            self.add(input_1, input_2, input_3)
        elif input1 == 3:
            input_i = input('请输入要修改的学生姓名：')
            self.modify(input_i)
        elif input1 == 4:
            self.check_all()
        else:
            print('输入错误')
        input2 = input('是否退出系统（y/n)')
        if input2 == 'y':
            print('已退出系统')
            pass
        else:
            self.function()


my_school = System('SWPU')

my_school.function()
