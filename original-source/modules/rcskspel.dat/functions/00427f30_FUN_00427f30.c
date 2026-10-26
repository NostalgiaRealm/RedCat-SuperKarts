/*
 * FUN_00427f30 at 00427f30
 * undefined FUN_00427f30(void)
 * Address ranges: 00427f30-00427fda
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00427f30(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar2 = FUN_00427ed0(param_1);
  iVar2 = *(int *)(&DAT_0053513c + iVar2 * 300) % 5;
  if (2 < iVar2) {
    iVar2 = 4 - iVar2;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (2 < iVar2) {
    iVar2 = 2;
  }
  iVar4 = 0;
  puVar5 = &DAT_004e799c + iVar2 * 0xc;
  do {
    iVar2 = FUN_00427ed0(param_1);
    iVar3 = FUN_00427f00(iVar4);
    *(undefined4 *)(&DAT_00535078 + iVar2 * 300 + iVar3 * 0x20) = puVar5[-1];
    iVar2 = FUN_00427ed0(param_1);
    iVar3 = FUN_00427f00(iVar4);
    uVar1 = *puVar5;
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 2;
    *(undefined4 *)(&DAT_0053507c + iVar2 * 300 + iVar3 * 0x20) = uVar1;
  } while (iVar4 < 6);
  return;
}

