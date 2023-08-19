from cyaron import *
import numpy as np

# N, k, T = 1000, 128, 2000
N, k, T = 10, 10, 10

def dis(x, ys):
    return [sum(d) for d in (x-ys)**2]

def argmin(x):
    bi, mm = 0, 40000 * k + 1
    for d in range(len(x)):
        if x[d] < mm:
            mm = x[d]
            bi = d
    return bi

for i in range(4, 7):
    print(i)
    test_data = IO(file_prefix = "vec", data_id = i)
    test_data.input_writeln(N, k, T)
    nd, td = [], []
    for _ in range(N):
        v = Vector.random(k, [(-100, 100)], 1)
        nd.append([t[0] for t in v])
        test_data.input_writeln(v)
    for _ in range(T):
        v = Vector.random(k, [(-100, 100)], 1)
        td.append([t[0] for t in v])
        test_data.input_writeln(v)
    
    nd, td = np.array(nd), np.array(td)
    for i in td:
        d = dis(i, nd)
        index = argmin(d)
        test_data.output_writeln(list(nd[index]))