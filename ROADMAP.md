- Add default precision float fmt structs
- Make an array of float-types/integer-types be castable to array of fmts (for arrfmt). This is already done for integer types:
```C
arrfmt((typeof(tsfmt(1,'x'))) nums, 10); // not intuitive enough
```

maybe something like:
```C
arrfmt((tsfmt_t(int,'x')*) nums, 10);
```
- Make `Neat__Array_Fmt` be exposed to the user, no reason why not.
- Fix integer tostr functions