/*
 * FUN_00420850 at 00420850
 * undefined FUN_00420850(void)
 * Address ranges: 00420850-0042094a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00420850(void)

{
  int iVar1;
  DWORD DVar2;
  
  if (0x62 < DAT_0053be30) {
    FUN_00420490();
  }
  iVar1 = (DAT_004fc8f8 & DAT_00508aec) * 4;
  FUN_00498ad0(*(float *)(iVar1 + DAT_006a5cd0) * _DAT_00508ae4,DAT_00508af8,
               *(float *)(iVar1 + DAT_006a5c88) * _DAT_00508ae4);
  DAT_00508aec = DAT_00508aec + DAT_00508af0;
  if (DAT_004e3b14 == 0xffffffff) {
    DAT_004e3b14 = GetTickCount();
  }
  DVar2 = GetTickCount();
  if (DVar2 - DAT_004e3b14 < 1000) {
    return 0;
  }
  iVar1 = FUN_004b3830(0x1b);
  if (iVar1 == 0) {
    iVar1 = FUN_004b3830(0xd);
    if (iVar1 == 0) {
      iVar1 = FUN_004b3830(0x20);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

