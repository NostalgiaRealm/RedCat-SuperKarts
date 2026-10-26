/*
 * FUN_004055c4 at 004055c4
 * undefined FUN_004055c4(void)
 * Address ranges: 004055c4-004055db
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004055c4(undefined4 *param_1)

{
  BOOL BVar1;
  
  param_1[1] = 0xd7b0;
  BVar1 = CloseHandle((HANDLE)*param_1);
  if (BVar1 == 1) {
    return;
  }
  GetLastError();
  return;
}

