/*
 * FUN_004c972c at 004c972c
 * undefined FUN_004c972c(void)
 * Address ranges: 004c972c-004c9747
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004c972c(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}

