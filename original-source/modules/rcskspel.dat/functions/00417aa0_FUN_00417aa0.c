/*
 * FUN_00417aa0 at 00417aa0
 * undefined FUN_00417aa0(void)
 * Address ranges: 00417aa0-00417ad7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417aa0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar2 = DAT_0053beb8;
  iVar1 = DAT_00508610;
  iVar4 = 0;
  if (0 < DAT_00508610) {
    puVar3 = &DAT_005081b0;
    uVar5 = uVar2;
    if (DAT_00508610 < 1) goto LAB_00417acb;
    do {
      uVar5 = uVar2;
      if (0x5081af < (int)puVar3) {
        uVar5 = puVar3[0x16];
      }
LAB_00417acb:
      *puVar3 = uVar5;
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0x1c;
    } while (iVar4 < iVar1);
  }
  return;
}

