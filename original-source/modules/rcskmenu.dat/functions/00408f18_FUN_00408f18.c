/*
 * FUN_00408f18 at 00408f18
 * int __register FUN_00408f18(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 00408f18-00408f3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00408f18(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 local_c;
  int local_8;
  
  FUN_00408ba4(&local_c,param_2,param_3,(double)CONCAT44(param_5,param_4));
  return local_8 % 7 + 1;
}

