/*
 * FUN_00425fd2 at 00425fd2
 * bool __cdecl FUN_00425fd2(void * param_1, UINT_PTR param_2)
 * Address ranges: 00425fd2-00425fed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_00425fd2(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}

