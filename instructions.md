## 0 Indexable Set Class Template (3.TESTAT)

**Hand-in time is Monday 20. Dec 2021, 11:59 (PM) (CET)**

Create a class template `indexableSet<typename T, typename COMPARE=std::less<T>>` that **inherits** from `std::set<T,COMPARE>` and allows indexing its content like you could do with a `std::vector<T>`. Negative indices should index from the "end" of the set. Provide also member functions `front()` and `back()` that correspond to those of vector.

Write Test cases and implementation code for `indexableSet` for the following aspects:
*  All constructors available for `std::set` have to work identically for `indexableSet`
*  Index access (with `operator[]` and `at()`) should reveal the stored values in sorted order
*  Negative indices should index the set from the end, so that `s[-1]` is the last available (the greatest) element in the set and `s[-s.size()] == s[0] `
*  Provide member functions `front()` and `back()`
*  All of your operations that might result in undefined behavior, because an index is out of range, or no elements exist should throw a corresponding standard exception (`std::out_of_range`).
*  Allow instantiating `indexableSet` with a different compare functor. Demonstrate that with a test case with your own `caselessCompare` functor for `std::string`. (`indexableSet<std::string, caselessCompare>`)

**Note:**
*  Implement the template class `indexableSet` as header-only (`indexableSet.h`) within your CUTE test project.
*  Remember the rules for class templates inheriting from a class that also depends on a template parameter! Otherwise interesting effects for name lookup might happen. Omitting that will cause you to fail!
*  When inheriting constructors from a base class, you will not inherit the deduction guides. Therefore, you will not be able to omit the class template arguments when using `indexableSet` in your tests.
*  We have added the possibility to submit your `indexableSet` implementation to [ALF](https://alf-uploader.sifs0005.infs.ch/)
  *  You are expected to upload a file named `indexableSet.h` that contains your template, defined in the global namespace.
  *  We extended the checking automation to catch segmentation faults (program crashes due to illegal memory access) which are likely for this exercise. If your program compiles successfully but the test results print something similiar to what you see below, you should probably check your index acesses:
```
*** Segmentation fault
Register dump:

 RAX: 0000000000000000   RBX: 0000000000000001   RCX: 0000000000aaf540
 RDX: 0000000000000000   RSI: ffffffffffffffff   RDI: 00007ffea1cb7098
 RBP: 00007ffea1cb6fa0   R8 : 0000000000aaecd0   R9 : 00007fb41f637600
 R10: 00000000000003b3   R11: 00007fb41f406ee0   R12: 0000000000aafa40
 R13: 00007ffea1cb7fb0   R14: 0000000000000000   R15: 0000000000000000
 RSP: 00007ffea1cb6f88
```



---

Required Files
Please only submit the following files:
- indexableSet.h
- Test.cpp (Tests for indexableSet)

Do NOT submit binaries (like executables, libraries, object files), a Cevelop project, or test results.

Teamwork
If you solve the testat in a team of more than one student, please add an additional file (team.txt/README.md/...) listing the members of your team. Only one of the team needs to hand-in the submission. The others will get credit as well. It is acceptable if you collaborate closely with others to elaborate your solution, but please specify this as well.
