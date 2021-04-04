# https://blog.csdn.net/maomaona/article/details/90143587
import pandas as pd
# 读取数据
# 读数据，看行数、列数、前几行
df = pd.read_csv('../input/application_train.csv')
print('Training data shapa:',df.shape)
df.head()

# EDA
# 查看目标变量分布
# 目标变量为分类变量
df['TARGET'].value_count()
df['TARGET'].plot.hist()

查看缺失值
目标dataframe缺失数据的分布
输入：目标dataframe
输出：dataframe里所有缺失值的变量列，行缺失值的个数，和缺失值比例
def missing_values_table(df):
    # Total missing values
    mis_val = df.isnull().sum()

    # Percentage of missing values
    mis_val_percent = 100 * df.isnull().sum() / df.shape[0]

    # Make a table with the result
    mis_val_table = pd.concat([mis_val, mis_val_percent], axis=1)

    # Rename columns
    mis_val_table_re_columns = mis_val_table.rename(columns={0: 'Missing Values',
                                                             1: '% of Total Missing Values'})
    # Sort the table by percentage of missing,descending
    print('Your selected df has ' + str(df.shape[1]) + ' columns.\n',
          'There are ' + str(mis_val_table_re_columns.shape[0]) + 'columns have missing values.')
    return mis_val_table_re_columns

查看不同类型变量情况
df.dtypes.value_counts()

Category/分类变量预处理
object 类型的变量是分类变量，查看所有分类变量的取值个数
df.select_dtypes('object').apply(pd.Series.nunique, axis=0)

Label Encoder 注意要同时code train和test集
# Create a label encoder object
le = LabelEncoder()
le_count = 0

# Iterate through the columns
for col in app_train:
    if app_train[col].dtype == 'object':
        # If 2 or fewer unique categories
        if len(list(app_train[col].unique())) <= 2:
            # Train on the training data
            le.fit(app_train[col])

            # Transform both training and testing data
            app_train[col] = le.transform(app_train[col])
            app_test[col] =le.transform(app_test[col])

            # keep track of how many columns are label encoded
            le_count += 1

print('{} columns were label encoded.'.format(le_count))

OneHot Encoder
# OneHot encoding of categorical variables
app_train = pd.get_dummies(app_train)
app_test = pd.get_dummies(app_test)

注意在train和test集上，feature(column)的数量应当时相同的，但在OneHot Encoding之后，如果train和test集的特征取值范围不同，
有些train集的特征取值在test集上没有，则需要align train和test集
train_labels = app_train['TARGET']

# Align the training and testing data, keep only columns present in both dataframs
app_train, app_test = app_train.align(app_test, join='inner', axis=1)

# Add the target back in train data
app_train['TARGET'] = train_labels

print('Training Features shape: ', app_train.shape)
print('Testing Features shape: ', app_test.shape)

在OneHot Encoding之后，特征个数显著增多，如果需要，做PCA

检查异常值
检查是否有不合常理的值
检查最大和最小值
app_train['DAYS_EMPLOYED'].describe()

如果在数据里面发现异常值，，不要草率处理，如全部填零等。
safest way是首先看异常值的分布是否有特点，比如是否异常值都相同，有异常值的观测值是否对目标变量有影响(为查看这一点，可以把
观测值按是否有异常值分组，看各组的目标变量均值是否相等)
如果异常值的分布有其特点，处理方法是——另外创建一列，用来表明其对应的列是否为异常值，然后给所有异常值填充np.nan,以备后续处理
注意：任何在training set上做的处理，需要同样在test set上做

特征和目标相关性
1.  .00 - .19 'very weak'
2.  .20 - .39 'weak'
3.  .40 - .59 'moderate'
4.  .60 - .79 'strong'
5.  .80 - 1.0 'very strong'

全部特征和目标变量的相关性
# Find correlations with the target and sort
correlations = app_train.corr()['TARGET'].sort_values()

# Display correlations
print('Most Positive Correlations:\n', correlations.tail(15))
print('\nMost Negative Correlations:\n', correlations.head(15))

深入探索某个连续特征和目标变量(类别变量)的相关性
首先画histgram查看分布
# Set the style of plots
plt.style.use('fivethirtyeight')

# Plot the distribution of ages in years
plt.hist(app_train['DAYS_BIRTH'] / 365, edgecolor='k', bins=25)
plt.title('Age of Client')
plt.xlabel('Age(years')
plt.ylabel('Count')

然后做KDE图，看目标变量取值不同时，特征的分布情况
# KDE plot of loans that were repaid on time
sns.kdeplot(app_train.loc[app_train['TARGET'] == 0, 'DAYS_BIRTH'] / 365, label='target==0')

# KDE plot of loans that were not repaid on time
sns.kdeplot(app_train.loc[app_train['TARGET'] == 1, 'DAYS_BIRTH'] / 365, label='target==1')

尝试将连续特征转换成离散特征，探索其和目标变量的关系
# Age data saved in another dataframe
age_data = app_train[['TARGET', 'DAYS_BIRTH']]
age_data['YEARS_BIRTH'] = age_data['DAYS_BIRTH'] / 365

# BIn the age data
age_data['YEARS_BINNED'] = pd.cut(age_data['YEARS_BIRTH'], bins=np.linspace(20, 70, num=11))
age_data.head(10)

np.linspace(start, end, num)  在[start, end]返回num个均匀的样本
pd.cut(array-like x, bins)  返回一个array-like对象，按照bins分箱

做bar plot
# Draw a bar plot for the age bins
plt.bar(age_groups.index.astype(str), 100 * age_groups['TARGET'])

# Plot labeling
plt.xticks(rotation=75)
plt.xlabel('Age Group (years)')
plt.ylabel('Failure to Repay (%)')
plt.title('Failure to Repay by Group')

同时探索几个相关连续特征对目标变量(类别变量)的影响
查看特征间关系，机器与目标变量间的关系，热力图，KDE图
ext_data = app_train[['EXT_SOURCE_1', 'EXT_SOURCE_2', 'EXT_SOURCE_3', 'TARGET', 'DAYS_BIRTH']]
corr_ext = ext_data.corr()
corr_ext

sns.heatmap(corr_ext, cmap=plt.cm.RdYlBu_r, vmin=-0.25, annot=True, vmax=0.6)
plt.title('Correlation Heatmap')

特征工程
Polynomial Features(多项式特征)
生成多项式特征，调用sklearn包中的PolynomialFeatures
# Import Polynomial features tool
from sklearn.preprocessing import PolynomialFeatures

poly_transformer = PolynomialFeatures(degree=3)

# Train the polynommial features
poly_transformer.fit(poly_features)

# Transform the features
poly_features = poly_transformer.transform(poly_features)
poly_features_test = poly_transformer.transform(poly_features_test)

print('Polynomial features shape: ', poly_features.shape)

注意PolynomialFeatures的transform方法输出的是一个numpy array，需要特别转换成DataFrame，并且用get_feature_names方法
得到新的特征名。得到的特征，需要添加primary key，然后merge回原本的train和test集，注意这点与get_dummies()方法不同
# Create a dataframe of the features
poly_features = pd.DataFrame(poly_features,
                             columns=poly_transformer.get_feature_names(['EXT_SOURCE_1', 'EXT_SOURCE_2', 'EXT_SOURCE_3', 'DAYS_BIRTH']))

# Put test features into dataframe
poly_features_test = pd.DataFrame(poly_features_test, columns=poly_transformer.get_feature_names(['EXT_SOURCE_1', 'EXT_SOURCE_2', 'EXT_SOURCE_3', 'DAYS_BIRTH']))

# Merge polynomial features into training dataframe
poly_features['SK_ID_CURR'] = app_train['SK_ID_CURR']
app_train_poly = app_train.merge(poly_features, on='SK_ID_CURR', how='left')

# Merge polynomial features into testing dataframe
poly_features_test['SK_ID_CURR'] = app_test['SK_ID_CURR']
app_test_poly = app_test.merge(poly_features_test, on='SK_ID_CURR', how='left')

# Align the dataframes
app_train_poly, app_test_poly = app_train_poly.align(app_test_poly, join='inner', axis=1)

# Print out the new shapes
print('Training data with polynomial features shape: ', app_train_poly.shape)
print('Testing data with polynomial features shape: ', app_test_poly.shape)