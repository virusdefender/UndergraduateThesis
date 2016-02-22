# coding=utf-8
import os
import judger
import time
base_path = os.path.dirname(os.path.abspath(__file__))


def run(use_sandbox):
    path = os.path.join(base_path, "demo")
    return judger.run(path=path,
                      in_file=os.path.join(base_path, "1.in"),
                      out_file=os.path.join(base_path, "seccomp.out"),
                      # ms
                      max_cpu_time=2000000,
                      # Byte
                      max_memory=200000000,
                      # default is True
                      use_sandbox=use_sandbox)

print run(use_sandbox=False)

