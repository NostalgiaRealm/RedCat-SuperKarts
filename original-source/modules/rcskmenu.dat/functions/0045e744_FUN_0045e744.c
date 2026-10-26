/*
 * FUN_0045e744 at 0045e744
 * undefined FUN_0045e744(void)
 * Address ranges: 0045e744-0045e761
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e744(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0xb4))();
  (**(code **)(*param_1 + 0xb8))(param_1,uVar1 ^ 1);
  return;
}

