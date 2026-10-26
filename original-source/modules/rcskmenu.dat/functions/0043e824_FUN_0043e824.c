/*
 * FUN_0043e824 at 0043e824
 * undefined FUN_0043e824(void)
 * Address ranges: 0043e824-0043e84e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e824(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_1 + 8))();
  if (cVar2 != '\0') {
    iVar1 = param_1[6];
    *(undefined4 *)(iVar1 + 0x108) = param_4;
    *(undefined4 *)(iVar1 + 0x10c) = param_5;
  }
  return;
}

