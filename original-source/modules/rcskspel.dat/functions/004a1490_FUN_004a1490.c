/*
 * FUN_004a1490 at 004a1490
 * undefined FUN_004a1490(void)
 * Address ranges: 004a1490-004a14d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a1490(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_40 [16];
  
  iVar3 = 4;
  puVar1 = local_40;
  puVar2 = local_40;
  do {
    *puVar1 = 0;
    iVar3 = iVar3 + -1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar2 = 0x3f800000;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 5;
  } while (iVar3 != 0);
  puVar1 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

