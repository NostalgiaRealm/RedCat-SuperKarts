/*
 * FUN_00411a6c at 00411a6c
 * undefined FUN_00411a6c(void)
 * Address ranges: 00411a6c-00411a7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

DWORD FUN_00411a6c(int param_1,LPVOID param_2,DWORD param_3)

{
  DWORD DVar1;
  
  DVar1 = FUN_00408048(*(HANDLE *)(param_1 + 4),param_2,param_3);
  if (DVar1 == 0xffffffff) {
    DVar1 = 0;
  }
  return DVar1;
}

