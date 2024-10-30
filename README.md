# ATM Controller
> This is a repository for LJM's Bear Robotics coding test
* 이정민 (Jungmin Lee), <jmin2821@gmail.com>
---

## 1. How to build

### If you have CMake installed
```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
```


### If Not
```shell
$ g++ -o BearCodingTest *.cpp
```

---

## 2. To test the code
```shell
$ ./BearCodingTest
```

This code uses main.cpp for test and testset.hpp for test data.

---

## 3. About the code

This code is a simple ATM controller code.

First, the initial flow of insertion of card, matching PIN, and selecting account will be done.

Then, the test program will lead to the function selection of checking the balance, deposit, or withdraw.


