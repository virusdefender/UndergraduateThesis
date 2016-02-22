import lorun
import time
a = time.time()
fin = file('1.in')
fout = file('ptrace.out', "w")
runcfg = {
    'args': ['./demo'],
    'fd_in': fin.fileno(),
    'fd_out': fout.fileno(),
    'timelimit': 5000000, #in MS
    'memorylimit': 2000000, #in KB
    'trace': True,
    'calls': [0 ,1 ,2 ,3 ,5 ,9 ,10 ,11 ,12 ,21 ,158 ,231],
    'files': {'/lib/x86_64-linux-gnu/libc.so.6': 524288, '/lib/x86_64-linux-gnu/libm.so.6': 524288, '/etc/ld.so.cache': 524288, '/usr/lib/x86_64-linux-gnu/libstdc++.so.6': 524288, '/lib/x86_64-linux-gnu/libgcc_s.so.1': 524288}
}
print lorun.run(runcfg)
fin.close()
fout.close()
print time.time() - a
