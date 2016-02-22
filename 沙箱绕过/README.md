sandbox.c 编译

```
gcc sandbox.c -fPIC -ldl -shared -lseccomp -o sandbox.so
```

然后运行

```
LD_PERLOAD=YOUR_SANDBOX_SO_ABSOLUTE_PATH /bin/ls
```

参考了 https://github.com/quark-zju/lrun/blob/master/utils/libexecwhitelist/Makefile

custom_libc_start_main.c 编译

```
gcc custom_libc_start_main.c -ldl -o custom_libc_start_main
```

然后运行

```
LD_PERLOAD=YOUR_SANDBOX_SO_ABSOLUTE_PATH ./custom_libc_start_main
```

cover_function.c 编译

```
gcc cover_function.c sandbox.c -ldl -lseccomp -o cover_function
```

