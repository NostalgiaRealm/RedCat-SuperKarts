/*
 * FUN_0042600a at 0042600a
 * bool __cdecl FUN_0042600a(FARPROC param_1)
 * Address ranges: 0042600a-00426021
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_0042600a(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}

