from itertools import chain

my_list = [1, 2, 3]
my_dict = {
    "bobby1": "http://projectsedu.com",
    "bobby2": "http://www.imooc.com",
}

# yield from iterable
def my_chain(*args, **kwargs):
    for my_iterable in args:
        # for value in my_iterable:
        #     yield value
        yield from my_iterable

# for value in chain(my_list, my_dict, range(5, 10)):
for value in my_chain(my_list, my_dict, range(5, 10)):
    print(value)


def g1(iterable):
    yield iterable

def g2(iterable):
    yield from iterable

for value in g1(range(10)):
    print(value)
for value in g2(range(10)):
    print(value)
