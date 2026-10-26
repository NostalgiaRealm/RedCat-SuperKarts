/*
 * FUN_004bdb85 at 004bdb85
 * undefined FUN_004bdb85(void)
 * Address ranges: 004bdb85-004bdbb2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004bdb85(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x50) == 0) ||
     (iVar1 = FUN_004c03bd(*(int *)(param_1 + 0x50),param_2,0,param_3 * 2), iVar1 != 0)) {
    param_1 = 0;
  }
  return param_1;
}

