/*
 * FUN_00425fee at 00425fee
 * bool __cdecl FUN_00425fee(LPVOID param_1, UINT_PTR param_2)
 * Address ranges: 00425fee-00426009
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_00425fee(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}

