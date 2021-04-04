import pandas as pd
import json

pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)
# mast = pd.read_excel('仓库塔.xlsx')   # 默认读取第一个sheet
# print(mast.head())


# 第一个sheet
# natasha = pd.read_excel('仓库塔.xlsx', sheet_name='natasha')
# print(natasha.head())
# print(natasha.shape)


# 第二个sheet
stark = pd.read_excel('仓库塔.xlsx', sheet_name='stark', names=['mastId', 'dataOceanId', 'latitude', 'longitude', 'altitude'])
print(stark.head())
print(stark.shape)
stark_list = json.loads(stark.to_json(orient='records', force_ascii=False))
print(len(stark_list))
print(type(stark_list))
print(stark_list[:5])

# 第三个sheet
# product = pd.read_excel('仓库塔.xlsx', sheet_name='product')
# print(product.head())
# print(product.shape)