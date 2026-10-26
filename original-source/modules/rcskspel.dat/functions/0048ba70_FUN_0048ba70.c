/*
 * FUN_0048ba70 at 0048ba70
 * undefined FUN_0048ba70(void)
 * Address ranges: 0048ba70-0048ba9f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048ba70(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_3;
      puVar3 = param_1;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_1 = param_1 + 8;
  }
  return;
}

