/*
 * FUN_004c9748 at 004c9748
 * undefined FUN_004c9748(void)
 * Address ranges: 004c9748-004c9763
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004c9748(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}

