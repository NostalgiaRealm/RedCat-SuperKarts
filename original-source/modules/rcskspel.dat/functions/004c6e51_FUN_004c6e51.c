/*
 * FUN_004c6e51 at 004c6e51
 * undefined FUN_004c6e51(void)
 * Address ranges: 004c6e51-004c6eb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c6e51(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_006b66ec = param_1;
  puVar1 = &DAT_005031e8;
  do {
    if (param_1 == *puVar1) {
      _DAT_006b66e8 = *(undefined4 *)(iVar2 * 8 + 0x5031ec);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x503350);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_006b66e8 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (_DAT_006b66e8 = 8, 0xca < param_1)) {
    _DAT_006b66e8 = 0x16;
  }
  return;
}

