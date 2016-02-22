judger: https://github.com/QingdaoU/Judger
lorun: https://github.com/lodevil/Lo-runner
版本都是2016年1月22号的

运行在Ubuntu 14.04虚拟机中，虚拟化单核，主机：MacBookPro11 Intel Core i5 2.6 GHz

seccomp.py without sandbox

```
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python seccomp.py 
DEBUG [2016-02-22 19:25:10] [runner.c:75] exit status: 0
{'cpu_time': 13288, 'exit_status': 0, 'signal': 0, 'flag': 0, 'memory': 3530752, 'real_time': 13379}
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python seccomp.py 
DEBUG [2016-02-22 19:25:27] [runner.c:75] exit status: 0
{'cpu_time': 13164, 'exit_status': 0, 'signal': 0, 'flag': 0, 'memory': 3534848, 'real_time': 13256}
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python seccomp.py 
DEBUG [2016-02-22 19:25:43] [runner.c:75] exit status: 0
{'cpu_time': 12776, 'exit_status': 0, 'signal': 0, 'flag': 0, 'memory': 3502080, 'real_time': 12855}
```

seccomp.py with sandbox

```
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ sudo python seccomp.py 
DEBUG [2016-02-22 19:28:13] [runner.c:75] exit status: 0
{'cpu_time': 13288, 'exit_status': 0, 'signal': 0, 'flag': 0, 'memory': 3796992, 'real_time': 13363}
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ sudo python seccomp.py 
DEBUG [2016-02-22 19:28:30] [runner.c:75] exit status: 0
{'cpu_time': 13644, 'exit_status': 0, 'signal': 0, 'flag': 0, 'memory': 3731456, 'real_time': 13723}
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ sudo python seccomp.py 
DEBUG [2016-02-22 19:28:45] [runner.c:75] exit status: 0
{'cpu_time': 13356, 'exit_status': 0, 'signal': 0, 'flag': 0, 'memory': 3792896, 'real_time': 13427}

```

ptrace.py with sandbox 耗时明显增加

```
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python ptrace.py 
{'memoryused': 7264L, 'timeused': 35252L, 'result': 0L}
70.8774569035
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python ptrace.py 
{'memoryused': 7316L, 'timeused': 37256L, 'result': 0L}
77.7578999996
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python ptrace.py 
{'memoryused': 7216L, 'timeused': 39712L, 'result': 0L}
79.3390719891

```

ptrace.py without sandbox

```
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python ptrace.py 
{'memoryused': 7360L, 'timeused': 13088L, 'result': 0L}
13.3504879475
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python ptrace.py 
{'memoryused': 7268L, 'timeused': 13384L, 'result': 0L}
13.6887350082
virusdefender@vm:~/Desktop/paper_res/seccomp和ptrace性能对比$ python ptrace.py 
{'memoryused': 7312L, 'timeused': 13056L, 'result': 0L}
13.3044669628

```
