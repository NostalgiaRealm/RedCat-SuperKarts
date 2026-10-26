/*
 * FUN_00424389 at 00424389
 * undefined FUN_00424389(void)
 * Address ranges: 00424389-0042442d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424389(void)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar1 = 0x14;
  if (DAT_0043f800 == 0) {
    iVar1 = 0x200;
  }
  else if (0x13 < DAT_0043f800) goto LAB_004243a8;
  DAT_0043f800 = iVar1;
LAB_004243a8:
  DAT_0043e7e8 = FUN_004260cb(DAT_0043f800,4);
  if (DAT_0043e7e8 == (int *)0x0) {
    DAT_0043f800 = 0x14;
    DAT_0043e7e8 = FUN_004260cb(0x14,4);
    if (DAT_0043e7e8 == (int *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  iVar1 = 0;
  ppuVar2 = &PTR_DAT_00437610;
  do {
    *(undefined ***)(iVar1 + (int)DAT_0043e7e8) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar1 = iVar1 + 4;
  } while ((int)ppuVar2 < 0x437890);
  uVar4 = 0;
  puVar3 = &DAT_00437620;
  do {
    iVar1 = *(int *)((&DAT_0043f820)[(int)uVar4 >> 5] + (uVar4 & 0x1f) * 8);
    if ((iVar1 == -1) || (iVar1 == 0)) {
      *puVar3 = 0xffffffff;
    }
    puVar3 = puVar3 + 8;
    uVar4 = uVar4 + 1;
  } while ((int)puVar3 < 0x437680);
  return;
}

