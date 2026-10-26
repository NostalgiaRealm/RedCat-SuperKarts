/*
 * FUN_00411a7c at 00411a7c
 * undefined FUN_00411a7c(void)
 * Address ranges: 00411a7c-00411a8b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

DWORD FUN_00411a7c(int param_1,LPCVOID param_2,DWORD param_3)

{
  DWORD DVar1;
  
  DVar1 = FUN_00408074(*(HANDLE *)(param_1 + 4),param_2,param_3);
  if (DVar1 == 0xffffffff) {
    DVar1 = 0;
  }
  return DVar1;
}

