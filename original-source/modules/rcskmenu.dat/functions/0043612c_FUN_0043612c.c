/*
 * FUN_0043612c at 0043612c
 * undefined FUN_0043612c(void)
 * Address ranges: 0043612c-00436156
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043612c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_1 + 8))();
  if (cVar2 != '\0') {
    iVar1 = param_1[6];
    *(undefined4 *)(iVar1 + 0x80) = param_4;
    *(undefined4 *)(iVar1 + 0x84) = param_5;
  }
  return;
}

