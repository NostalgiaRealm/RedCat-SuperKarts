/*
 * FUN_0040472a at 0040472a
 * undefined FUN_0040472a(void)
 * Address ranges: 0040472a-004047ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040472a(void)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar1 = 0x14;
  if (DAT_0040a000 == 0) {
    iVar1 = 0x200;
  }
  else if (0x13 < DAT_0040a000) goto LAB_00404749;
  DAT_0040a000 = iVar1;
LAB_00404749:
  DAT_00408fe8 = FUN_004055c9(DAT_0040a000,4);
  if (DAT_00408fe8 == (int *)0x0) {
    DAT_0040a000 = 0x14;
    DAT_00408fe8 = FUN_004055c9(0x14,4);
    if (DAT_00408fe8 == (int *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  iVar1 = 0;
  ppuVar2 = &PTR_DAT_004084f0;
  do {
    *(undefined ***)(iVar1 + (int)DAT_00408fe8) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar1 = iVar1 + 4;
  } while ((int)ppuVar2 < 0x408770);
  uVar4 = 0;
  puVar3 = &DAT_00408500;
  do {
    iVar1 = *(int *)((&DAT_0040a020)[(int)uVar4 >> 5] + (uVar4 & 0x1f) * 8);
    if ((iVar1 == -1) || (iVar1 == 0)) {
      *puVar3 = 0xffffffff;
    }
    puVar3 = puVar3 + 8;
    uVar4 = uVar4 + 1;
  } while ((int)puVar3 < 0x408560);
  return;
}

