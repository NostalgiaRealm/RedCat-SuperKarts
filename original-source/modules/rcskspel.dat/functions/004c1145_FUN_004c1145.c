/*
 * FUN_004c1145 at 004c1145
 * undefined FUN_004c1145(void)
 * Address ranges: 004c1145-004c11e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c1145(void)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar1 = 0x14;
  if (DAT_006b7dc0 == 0) {
    iVar1 = 0x200;
  }
  else if (0x13 < DAT_006b7dc0) goto LAB_004c1164;
  DAT_006b7dc0 = iVar1;
LAB_004c1164:
  DAT_006b6da4 = FUN_004c87f5(DAT_006b7dc0,4);
  if (DAT_006b6da4 == 0) {
    DAT_006b7dc0 = 0x14;
    DAT_006b6da4 = FUN_004c87f5(0x14,4);
    if (DAT_006b6da4 == 0) {
      __amsg_exit(0x1a);
    }
  }
  iVar1 = 0;
  ppuVar2 = &PTR_DAT_00502b00;
  do {
    *(undefined ***)(iVar1 + DAT_006b6da4) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar1 = iVar1 + 4;
  } while ((int)ppuVar2 < 0x502d80);
  uVar4 = 0;
  puVar3 = &DAT_00502b10;
  do {
    iVar1 = *(int *)((&DAT_006b6a60)[(int)uVar4 >> 5] + (uVar4 & 0x1f) * 8);
    if ((iVar1 == -1) || (iVar1 == 0)) {
      *puVar3 = 0xffffffff;
    }
    puVar3 = puVar3 + 8;
    uVar4 = uVar4 + 1;
  } while ((int)puVar3 < 0x502b70);
  return;
}

