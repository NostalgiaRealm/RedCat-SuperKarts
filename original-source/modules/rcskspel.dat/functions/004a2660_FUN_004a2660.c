/*
 * FUN_004a2660 at 004a2660
 * undefined FUN_004a2660(void)
 * Address ranges: 004a2660-004a26a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2660(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 local_40 [16];
  
  puVar2 = local_40;
  iVar5 = 4;
  do {
    iVar4 = 4;
    puVar3 = param_2;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 4;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    param_2 = param_2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar2 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

