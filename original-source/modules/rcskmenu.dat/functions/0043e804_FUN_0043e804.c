/*
 * FUN_0043e804 at 0043e804
 * undefined FUN_0043e804(void)
 * Address ranges: 0043e804-0043e821
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e804(int *param_1,uint param_2)

{
  char cVar1;
  undefined4 extraout_ECX;
  
  cVar1 = (**(code **)(*param_1 + 0x3c))();
  if (cVar1 != '\0') {
    FUN_0043f564((int *)param_1[6],param_2,extraout_ECX);
  }
  return;
}

