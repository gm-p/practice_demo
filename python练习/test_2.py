def save_file(boy, girl ,count):
    boy_file_name = 'boy_' + str(count) + '.txt'
    girl_file_name = 'girl_' + str(count) + '.txt'

    boy_file = open(boy_file_name, 'w')
    girl_file = open(girl_file_name, 'w')

    boy_file.writelines(boy)
    girl_file.writelines(girl)

    boy_file.close()
    girl_file.close()

    
def split_file(filename):
    f = open(filename)

    boy = []
    girl = []
    count = 1

    for each_line in f:
        if each_line[:6] != '======':  #我们这里进行字符串分割操作
            (role, line_spoken) = each_line.split(':',1)
            if role == '小甲鱼':
                boy.append(line_spoken)
            if role == '小客服':
                girl.append(line_spoken)

        else:
            save_file(boy,girl,count)

            boy = []
            girl = []
            count += 1

    save_file(boy,girl,count)

    f.close()

split_file('record.txt')
