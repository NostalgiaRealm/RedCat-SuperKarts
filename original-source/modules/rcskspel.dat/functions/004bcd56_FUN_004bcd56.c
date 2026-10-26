/*
 * FUN_004bcd56 at 004bcd56
 * undefined FUN_004bcd56(void)
 * Address ranges: 004bcd56-004bcd80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004bcd56(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x50) == 0) ||
     (iVar1 = FUN_004c03bd(*(int *)(param_1 + 0x50),param_2,0,param_3), iVar1 != 0)) {
    param_1 = 0;
  }
  return param_1;
}

