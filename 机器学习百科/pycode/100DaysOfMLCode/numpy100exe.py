# -*- coding: utf-8 -*-
"""
Created on Sun Mar  3 22:05:28 2019

@author: guangming.pan
"""

import numpy as np

print(np.__version__)
np.show_config()

Z = np.zeros(10)
print(Z)

Z = np.zeros((10, 10))
print("%d bytes" % (Z.size * Z.itemsize))

# %run 'python -c "import numpy; numpy.info(numpy.add)"'

Z = np.zeros(10)
Z[4] = 1
print(Z)

Z = np.arange(10, 50)
print(Z)

Z = np.arange(50); print(Z)
Z = Z[::-1]; print(Z)

Z = np.arange(9).reshape(3, 3)
print(Z)

nz = np.nonzero([1, 2, 0, 0, 4, 0])
print(nz)

Z = np.eye(3)
print(Z)

Z = np.random.random((10, 10))
Zmin, Zmax = Z.min(), Z.max()
print(Zmin, Zmax)

Z = np.random.random(30)
m = Z.mean()
print(m)

Z = np.ones((10, 10))
Z[1:-1, 1:-1] = 0
print(Z)

Z = np.ones((5, 5))
Z = np.pad(Z, pad_width=1, mode='constant', constant_values=0)
print(Z)

print(0 * np.nan)
print(np.nan == np.nan)
print(np.inf > np.nan)
print(np.nan - np.nan)
print(np.nan in set([np.nan]))
print(0.3 == 3*0.1)

Z = np.diag(1+np.arange(4), k=-1)
print(Z)

Z = np.zeros((8, 8), dtype=int)
Z[1::2, ::2] = 1
Z[::2, 1::2] = 1
print(Z)

print(np.unravel_index(99, (6, 7, 8)))

Z = np.tile(np.array([[0, 1], [1, 0]]), (4, 4))
print(Z)

color = np.dtype([("r", np.ubyte, 1),
                  ("g", np.ubyte, 1),
                  ("b", np.ubyte, 1),
                  ("a", np.ubyte, 1)])

Z = np.dot(np.ones((5, 3)), np.ones((3, 2)))
print(Z)

# Alternative solution, in Python 3.5 and above
Z = np.ones((5, 3)) @ np.ones((3, 2))
print(Z)

Z = np.arange(11)
Z[(3 < Z) & (Z <= 8)] *= -1
print(Z)
'''
print(sum(range(5), -1))
from numpy import *
print(sum(range(5), -1))'''

# Z**Z 非法
2 << Z >> 2
Z <- Z
1j*Z
Z/1/1
# Z<Z>Z 非法

print(np.array(0) / np.array(0))
print(np.array(0) // np.array(0))
print(np.array([np.nan]).astype(int).astype(float))

Z = np.random.uniform(-10, +10, 10); print(Z)
print(np.copysign(np.ceil(np.abs(Z)), Z))

Z1 = np.random.randint(0, 10, 10); print(Z1)
Z2 = np.random.randint(0, 10, 10); print(Z2)
print(np.intersect1d(Z1, Z2))

# Suicide mode on
defaults = np.seterr(all="ignore")
Z = np.ones(1) / 0

# Back to sanity
_ = np.seterr(**defaults)

with np.errstate(divide='ignore'):
    Z = np.ones(1) / 0
    
print(np.sqrt(-1) == np.emath.sqrt(-1))

yesterday = np.datetime64('today', 'D') - np.timedelta64(1, 'D'); print(yesterday)
today = np.datetime64('today', 'D');  print(today)
tomorrow = np.datetime64('today', 'D') + np.timedelta64(1, 'D'); print(tomorrow)

Z = np.arange('2016-07', '2016-08', dtype='datetime64[D]')
print(Z)

A = np.ones(3)*1; print(A)
B = np.ones(3)*2; print(B)
C = np.ones(3)*3; print(C)
np.add(A, B, out=B); print(B)
np.divide(A, 2, out=A); print(A)
np.negative(A, out=A); print(A)
np.multiply(A, B, out=A); print(A)

Z = np.random.uniform(0, 10, 10)
print(Z - Z%1)
print(np.floor(Z))
print(np.ceil(Z) - 1)
print(Z.astype(int))
print(np.trunc(Z))

Z = np.zeros((5, 5))
Z += np.arange(5)
print(Z)

def generate():
    for x in range(10):
        yield x
        
Z = np.fromiter(generate(), dtype=float, count=-1)
print(Z)

Z = np.linspace(0, 1, 11, endpoint=False)[1:]
print(Z)

Z = np.random.random(10)
Z.sort()
print(Z)

Z = np.arange(10)
print(np.add.reduce(Z))

A = np.random.randint(0, 2, 5)
B = np.random.randint(0, 2, 5)
# Assuming identical shape of the arrays and tolerance for the comparison of values
equals = np.allclose(A, B)
print(equals)
# Checking both the shape and the element values, no tolerance (values have to be exactly equal)
equal = np.array_equal(A, B)
print(equal)

Z = np.zeros(10)
Z.flags.writeable = False
#Z[0] = 1

Z = np.random.random((10, 2))
X, Y = Z[:, 0], Z[:, 1]
R = np.sqrt(X**2 + Y**2)
T = np.arctan2(Y, X)
print(R)
print(T)

Z = np.random.random(10)
Z[Z.argmax()] = 0
print(Z)

Z = np.zeros((5, 5), [('x', float), ('y', float)])
Z['x'], Z['y'] = np.meshgrid(np.linspace(0, 1, 5), np.linspace(0, 1, 5))
print(Z)

X = np.arange(8)
Y = X + 0.5
C = 1.0 / np.subtract.outer(X, Y)
print(np.linalg.det(C))

for dtype in [np.int8, np.int32, np.int64]:
    print(np.iinfo(dtype).min)
    print(np.iinfo(dtype).max)
for dtype in [np.float32, np.float64]:
    print(np.finfo(dtype).min)
    print(np.finfo(dtype).max)
    print(np.finfo(dtype).eps)
    
np.set_printoptions(threshold=np.nan)
Z = np.zeros((16, 16))
print(Z)

Z = np.arange(100)
v = np.random.uniform(0, 100)
index = (np.abs(Z - v)).argmin()
print(Z[index])

Z = np.zeros(10, [('position', [('x', float, 1),
                               ('y', float, 1)]),
                  ('color', [('r', float, 1),
                             ('g', float, 1),
                             ('b', float, 1)])])
print(Z)

Z = np.random.random((10, 2))
X, Y = np.atleast_2d(Z[:, 0], Z[:, 1])
D = np.sqrt((X - X.T)**2 + (Y - Y.T)**2)
print(D)

# Much faster with scipy
import scipy
import scipy.spatial
Z = np.random.random((10, 2))
D = scipy.spatial.distance.cdist(Z, Z)
print(D)

Z = np.arange(10, dtype=np.float32)
Z = Z.astype(np.int32, copy=False)
print(Z)

from io import StringIO
# Fake file
s = StringIO("""1, 2, 3, 4, 5\n
                6,  ,  , 7, 8\n
                 ,  , 9,10,11\n""")
Z = np.genfromtxt(s, delimiter=",", dtype=np.int)
print(Z)

Z = np.arange(9).reshape(3, 3)
for index, value in np.ndenumerate(Z):
    print(index, value)
for index in np.ndindex(Z.shape):
    print(index, Z[index])
    
X, Y = np.meshgrid(np.linspace(-1, 1, 10), np.linspace(-1, 1, 10))
D = np.sqrt(X*X + Y*Y)
sigma, mu = 1.0, 0.0
G = np.exp(-(D - mu)**2 / (2.0 * sigma**2))
print(G)

n = 10
p = 3
Z = np.zeros((n, n))
np.put(Z, np.random.choice(range(n*n), p, replace=False), 1)
print(Z)

X = np.random.rand(5, 10)
# recent versions of numpy
Y = X - X.mean(axis=1, keepdims=True)
# old versions of numpy
Y = X - X.mean(axis=1).reshape(-1, 1)
print(Y)

Z = np.random.randint(0, 10, (3, 3))
print(Z)
print(Z[Z[:, 1].argsort()])

Z = np.random.randint(0, 3,(3, 10))
print((~Z.any(axis=0)).any())

Z = np.random.uniform(0, 1, 10)
z = 0.5
m = Z.flat[np.abs(Z - z).argmin()]
print(m)

A = np.arange(3).reshape(3, 1)
B = np.arange(3).reshape(1, 3)
it = np.nditer([A, B, None])
for x, y, z in it:
    z[...] = x + y
print(it.operands[2])

class NamedArray(np.ndarray):
    def __new__(cls, array, name="no name"):
        obj = np.asarray(array).view(cls)
        obj.name = name
        return obj
    def __array_finalize__(self, obj):
        if obj is None:
            return
        self.info = getattr(obj, 'name', "no name")
        
Z = NamedArray(np.arange(10), "range_10")
print(Z.name)

Z = np.ones(10)
I = np.random.randint(0, len(Z), 20)
Z += np.bincount(I, minlength=len(Z))
print(Z)

np.add.at(Z, I, 1)
print(Z)

X = [1, 2, 3, 4, 5, 6]
I = [1, 3, 9, 3, 4, 1]
F = np.bincount(I, X)
print(F)

w, h = 16, 16
I = np.random.randint(0, 2, (h, w, 3)).astype(np.ubyte)
F = I[..., 0]*256*256 + I[..., 1]*256 + I[..., 2]
n = len(np.unique(F))
print(np.unique(I))

A = np.random.randint(0, 10, (3, 4, 3, 4))
# solution by passing a tuple of axes (introduced in numpy 1.7.0)
sum = A.sum(axis=(-2, -1))
print(sum)
# solution by flattening the last two dimensions into one
# (useful for functions that don't accept tuples for axis argument)
sum = A.reshape(A.shape[:-2] + (-1,)).sum(axis=-1)
print(sum)

D = np.random.uniform(0, 1, 100)
S = np.random.randint(0, 10, 100)
D_sums = np.bincount(S, weights=D)
D_counts = np.bincount(S)
D_means = D_sums / D_counts
print(D_means)

import pandas as pd
print(pd.Series(D).groupby(S).mean())

A = np.random.uniform(0, 1, (5, 5)); print(A)
B = np.random.uniform(0, 1, (5, 5)); print(B)
# slow version
print(np.diag(np.dot(A, B)))
# Fast version
print(np.sum(A * B.T, axis=1))
# Faster version
print(np.einsum("ij, ji->i", A, B))

Z = np.array([1, 2, 3, 4, 5])
nz = 3
Z0 = np.zeros(len(Z) + (len(Z) - 1) * (nz))
Z0[::nz+1] = Z
print(Z0)

A = np.ones((5, 5, 3)); print(A)
B = 2 * np.ones((5, 5)); print(B)
print(A * B[:, :, None])

A = np.arange(25).reshape(5, 5)
A[[0, 1]] = A[[1, 0]]
print(A)

faces = np.random.randint(0, 100, (10, 3))
F = np.roll(faces.repeat(2, axis=1), -1, axis=1)
F = F.reshape(len(F)*3, 2)
F = np.sort(F,axis=1)
G = F.view(dtype=[('p0', F.dtype), ('p1', F.dtype)])
G = np.unique(G)
print(G)

C = np.bincount([1, 1, 2, 3, 4, 4, 6])
A = np.repeat(np.arange(len(C)), C)
print(A)

def moving_average(a, n=3):
    ret = np.cumsum(a, dtype=float)
    ret[n:] = ret[n:] - ret[:-n]
    return ret[n-1:] / n
Z = np.arange(20)
print(moving_average(Z, n=3))

from numpy.lib import stride_tricks
def rolling(a, window):
    shape = (a.size - window + 1, window)
    strides = (a.itemsize, a.itemsize)
    return stride_tricks.as_strided(a, shape=shape, strides=strides)
Z = rolling(np.arange(10), 3)
print(Z)

Z = np.random.randint(0, 2, 100); print(Z)
np.logical_not(Z, out=Z); print(Z)
Z = np.random.uniform(-1.0, 1.0, 100); print(Z)
np.negative(Z, out=Z); print(Z)

def distance(P0, P1, p):
    T = P1 - P0
    L = (T**2).sum(axis=1)
    U = -((P0[:, 0] - p[..., 0]) * T[:, 0] + (P0[:, 1] - p[...,1]) * T[:, 1]) / L
    U = U.reshape(len(U), 1)
    D = P0 + U*T - p
    return np.sqrt((D**2).sum(axis=1))

P0 = np.random.uniform(-10, 10, (10, 2))
P1 = np.random.uniform(-10, 10, (10, 2))
p = np.random.uniform(-10, 10, (1, 2))
print(distance(P0, P1, p))

P0 = np.random.uniform(-10, 10, (10, 2))
P1 = np.random.uniform(-10, 10, (10, 2))
p = np.random.uniform(-10, 10, (10, 2))
print(np.array([distance(P0, P1, p_i) for p_i in p]))

Z = np.random.randint(0, 10, (10, 10))
shape = (5, 5)
fill = 0
position = (1, 1)
R = np.ones(shape, dtype=Z.dtype) * fill
P = np.array(list(position)).astype(int)
Rs = np.array(list(R.shape)).astype(int)
Zs = np.array(list(Z.shape)).astype(int)
R_start = np.zeros((len(shape),)).astype(int)
R_stop = np.array(list(shape)).astype(int)
Z_start = (P - Rs//2)
Z_stop = (P + Rs//2) + Rs%2
R_start = (R_start - np.minimum(Z_start, 0)).tolist()
Z_start = (np.maximum(Z_start, 0)).tolist()
R_stop = np.maximum(R_start, (R_stop - np.maximum(Z_stop-Zs, 0))).tolist()
Z_stop = (np.minimum(Z_stop, Zs)).tolist()
r = [slice(start, stop) for start, stop in zip(R_start, R_stop)]
z = [slice(start, stop) for start, stop in zip(Z_start, Z_stop)]
R[r] = Z[z]
print(Z)
print(R)

Z = np.arange(1, 15, dtype=np.uint32)
R = stride_tricks.as_strided(Z, (11, 4), (4, 4))
print(R)

Z = np.random.uniform(0, 1, (10, 10))
U, S, V = np.linalg.svd(Z)  # singular value decomposition
rank = np.sum(S > 1e-10)
print(rank)

Z = np.random.randint(0, 10, 50)
print(np.bincount(Z).argmax())

Z = np.random.randint(0, 5, (10, 10))
n = 3
i = 1 + (Z.shape[0] - 3)
j = 1 + (Z.shape[1] - 3)
C = stride_tricks.as_strided(Z, shape=(i, j, n, n), strides=Z.strides+Z.strides)
print(C)

class Symetric(np.ndarray):
    def __setitem__(self, index, value):
        i, j = index
        super(Symetric, self).__setitem__((i, j), value)
        super(Symetric, self).__setitem__((j, i), value)
        
def symetric(Z):
    return np.asarray(Z + Z.T - np.diag(Z.diagonal())).view(Symetric)
S = symetric(np.random.randint(0, 10, (5, 5)))
S[2, 3] = 42
print(S)

p, n = 10, 20
M = np.ones((p, n, n))
V = np.ones((p, n, 1))
S = np.tensordot(M, V, axes=[[0, 2], [0, 1]])
print(S)

Z = np.ones((16, 16))
k = 4
S = np.add.reduceat(np.add.reduceat(Z, np.arange(0, Z.shape[0], k), axis=0),
                                     np.arange(0, Z.shape[1], k), axis=1)
print(S)

def iterate(Z):
    N = (Z[0:-2, 0:-2] + Z[0:-2, 1:-1] + Z[0:-2, 2:] +
         Z[1:-1, 0:-2]                 + Z[1:-1, 2:] +
         Z[2:  , 0:-2] + Z[2:  , 1:-1] + Z[2:  , 2:])
    birth = (N == 3) & (Z[1:-1, 1:-1] == 0)
    survive = ((N==2) | (N==3)) &(Z[1:-1, 1:-1]==1)
    Z[...] = 0
    Z[1:-1, 1:-1][birth | survive] = 1
    return Z
Z = np.random.randint(0, 2, (50, 50))
for i in range(100):
    Z = iterate(Z)
print(Z)

Z = np.arange(10000)
np.random.shuffle(Z)
n = 5
# slow
print(Z[np.argsort(Z)[-n:]])
# fast
print(Z[np.argpartition(-Z, n)[:n]])

def cartesian(arrays):
    arrays = [np.asarray(a) for a in arrays]
    shape = (len(x) for x in arrays)
    ix = np.indices(shape, dtype=int)
    ix = ix.reshape(len(arrays), -1).T
    for n, arr in enumerate(arrays):
        ix[:, n] = arrays[n][ix[:, n]]
    return ix
print(cartesian(([1, 2, 3], [4, 5], [6, 7])))

Z = np.array([("Hello", 2.5, 3),
              ("World", 3.6, 2)])
R = np.core.records.fromarrays(Z.T, names='col1, col2, col3', formats='S8, f8, i8')
print(R)

import timeit
x = np.random.rand(int(5e7))
# %timeit np.power(x, 3)
# %timeit x*x*x
# %timeit np.einsum('i, i, i->i', x, x, x)  # 有bug

A = np.random.randint(0, 5, (8, 3)) 
B = np.random.randint(0, 5, (2, 2))
C = (A[..., np.newaxis, np.newaxis] == B)
rows = np.where(C.any((3, 1)).all(1))[0]
print(rows)

Z = np.random.randint(0, 5, (10, 3))
print(Z)
E = np.all(Z[:, 1:] == Z[:, :-1], axis=1)
U = Z[~E]
print(U)
U = Z[Z.max(axis=1) != Z.min(axis=1), :]
print(U)

I = np.array([0, 1, 2, 3, 15, 16, 32, 64, 128])
B = ((I.reshape(-1, 1) & (2**np.arange(8))) != 0).astype(int)
print(B[:, ::-1])
I = np.array([0, 1, 2, 3, 15, 16, 32, 64, 128], dtype=np.uint8)
print(np.unpackbits(I[:, np.newaxis], axis=1))

Z = np.random.randint(0, 2, (6, 3))
T = np.ascontiguousarray(Z).view(np.dtype((np.void, Z.dtype.itemsize*Z.shape[1])))
_, idx = np.unique(T, return_index=True)
uZ = Z[idx]
print(uZ)
uZ = np.unique(Z, axis=0)
print(uZ)

A = np.random.uniform(0, 1, 10)
B = np.random.uniform(0, 1, 10)
np.einsum('i->', A)  # np.sum(A)
np.einsum('i, i->i', A, B) # A * B
np.einsum('i, j->ij', A, B) # np.outer(A, B)

phi = np.arange(0, 10*np.pi, 0.1)
a = 1
x = a * phi * np.cos(phi)
y = a * phi * np.sin(phi)
dr = (np.diff(x)**2 + np.diff(y)**2)**.5   # segment length
r = np.zeros_like(x)
r[1:] = np.cumsum(dr)  # integrate path
r_int = np.linspace(0, r.max(), 200) # regular spaced path
x_int = np.interp(r_int, r, x)  # integrate path
y_int = np.interp(r_int, r, y)

X = np.asarray([[1.0, 0.0, 3.0, 8.0],
                [2.0, 0.0, 1.0, 1.0],
                [1.5, 2.5, 1.0, 0.0]])
n = 4
M = np.logical_and.reduce(np.mod(X, 1)==0, axis=-1)
M &= (X.sum(axis=-1) == n)
print(X[M])

X = np.random.randn(100)  # random 1D array
N = 1000  # number of bootstrap samples
idx = np.random.randint(0, X.size, (N, X.size))
means = X[idx].mean(axis=1)
confint = np.percentile(means, [2.5, 97.5])
print(confint)
