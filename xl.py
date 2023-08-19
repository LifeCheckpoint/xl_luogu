from cyaron import *

N, k, T = 500, 1024, 1500

for i in range(1, 4):
    test_data = IO(file_prefix = "vec", data_id = i, disable_output = True)
    test_data.input_writeln(N, k, T)
    for _ in range(N):
        test_data.input_writeln(Vector.random(k, [(-100, 100)], 1))
    for _ in range(T):
        test_data.input_writeln(Vector.random(k, [(-100, 100)], 1))