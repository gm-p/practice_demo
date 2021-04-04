from sklearn.datasets import fetch_20newsgroups
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer  # 导入文本特征向量化模块
from sklearn.naive_bayes import MultiinomialNB
from sklearn.metrics import classification_report


news = fetch_20newsgroups(subset='all')
print(len(news.data))

X_train, X_test, y_train, y_test = train_test_split(news.data, news.target, test_size=0.25, random_state=33)
print(X_train[0])
print(y_train[:100])

# 文本向量化
vec = CountVectorizer()
X_train = vec.fit_transform(X_train)
X_test = vec.transform(X_test)

mnb = MultinomialNB()   # 使用默认配置初始化朴素贝叶斯
mnb.fit(X_train, y_train)
y_predict = mnb.predict(X_test)

print('The Accuracy of Naive Bayes Classifier is:', mnb.score(X_test, y_test))
print(classification_report(y_test, y_predict, target_names=news.target_names))