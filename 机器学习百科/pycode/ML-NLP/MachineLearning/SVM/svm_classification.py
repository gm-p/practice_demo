import sys
import os
import jieba
from libsvm import svm
from libsvm.svmutil import svm_read_problem, svm_train, svm_predict, svm_save_model, svm_load_model


news_file = 'cnews.train.txt'
test_file = 'cnews.test.txt'
output_word_file = 'cnews_dict.txt'  # 进行分词后的数
output_word_test_file = 'cnews_dict_test.txt'
feature_file = 'cnews_feature_file.txt'  # 最后生成的词向量文件
feature_test_file = 'cnews_feature_test_file.txt'
model_filename = 'cnews_model'   # 模型保存文件


with open(news_file, 'r') as f:  # 读取新闻文章
    lines = f.readlines()
    
label, content = lines[0].strip('\r\n').split('\t')
print(content)

words_iter = jieba.cut(content)   # 使用jieba进行分词操作
print('/'.join(words_iter))


def generate_word_file(input_char_file, output_word_file):   # 定义分词函数，并写入文件
    with open(input_char_file, 'r') as f:
        lines = f.readlines()
    with open(output_word_file, 'w') as f:
        for line in lines:
            label, content = line.strip('\r\n').split('\t')
            words_iter = jieba.cut(content)
            word_content = ''
            for word in words_iter:
                word = word.strip(' ')
                if word != '':
                    word_content += word + ' '
            out_line = '%s\t%s\n' % (label, word_content.strip(' '))
            f.write(out_line)
            
generate_word_file(news_file, output_word_file)
generate_word_file(test_file, output_word_test_file)
print('======================分词完成==========================')


class Category:    # 分类topic
    def __init__(self, category_file):
        self._category_to_id = {}
        with open(category_file, 'r') as f:
            lines = f.readlines()
        for line in lines:
            category, idx = line.strip('\r\n').split('\t')
            idx = int(idx)
            self._category_to_id[category] = idx
            
    def category_to_id(self, category):
        return self._category_to_id[category]
    
    def size(self):
        return len(self._category_to_id)
    
category_file = 'cnews.category.txt'
category_vocab = Category(category_file)
print(category_vocab.size())


# 对分词后的数据进行词频统计并过滤，分配词ID
def generate_feature_dict(train_file, feature_threshold=10):
    feature_dict = {}
    with open(train_file, 'r') as f:
        lines = f.readlines()
    for line in lines:
        label, content = line.strip('\r\n').split('\t')
        for word in content.split(' '):
            if not word in feature_dict:
                feature_dict.setdefault(word, 0)
            feature_dict[word] += 1
    filtered_feature_dict = {}
    for feature_name in feature_dict:
        if feature_dict[feature_name] < feature_threshold:
            continue
        if not feature_name in filtered_feature_dict:
            filtered_feature_dict[feature_name] = len(filtered_feature_dict) + 1
    return filtered_feature_dict

feature_dict = generate_feature_dict(output_word_file, feature_threshold=200)
print(len(feature_dict))


def generate_feature_line(line, feature_dict, category_vocab):  # 对每一篇文章根据词id构造词向量
    label, content = line.strip('\r\n').split('\t')
    label_id = category_vocab.category_to_id(label)
    feature_example = {}
    for word in content.split(' '):
        if not word in feature_dict:
            continue
        feature_id = feature_dict[word]
        feature_example.setdefault(feature_id, 0)
        feature_example[feature_id] += 1
    feature_line = '%d' % label_id
    sorted_feature_example = sorted(feature_example.items(), key=lambda d: d[0])
    for item in sorted_feature_example:
        feature_line += ' %d:%d' % item
    return feature_line

# 循环每一篇文章，得到所有词向量化后的文件
def convert_raw_to_feature(raw_file, feature_file, feature_dict, category_vocab):
    with open(raw_file, 'r') as f:
        lines = f.readlines()
    with open(feature_file, 'w') as f:
        for line in lines:
            feature_line = generate_feature_line(line, feature_dict, category_vocab)
            f.write('%s\n' % feature_line)
            

# 测试数据运用相同的词ID表
convert_raw_to_feature(output_word_file, feature_file, feature_dict, category_vocab)
convert_raw_to_feature(output_word_test_file, feature_test_file, feature_dict, category_vocab)
print('===========构造词向量完成==============')


# 生成SVM训练数据
train_label, train_value = svm_read_problem(feature_file)
print(train_label[0], train_value[0])
train_test_label, train_test_value = svm_read_problem(feature_test_file)


if os.path.exists(model_filename):  # 判断模型文件是否存在，存在则直接读取
    model = svm_load_model(model_filename)
else:
    model = svm_train(train_label, train_value, '-s 0 -c 5 -t 0 -g 0.5 -e 0.1')  # 模型训练
    svm_save_model(model_filename, model)
print('=============模型训练完成==============')


# 模型预测，并打印精确度
p_labs, p_acc, p_vals = svm_predict(train_test_label, train_test_value, model)
print(p_acc)