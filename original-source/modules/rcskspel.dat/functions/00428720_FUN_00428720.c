/*
 * FUN_00428720 at 00428720
 * undefined FUN_00428720(void)
 * Address ranges: 00428720-004287f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00428720(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  _DAT_00534f60 = &DAT_00646464;
  _DAT_00534f80 = &DAT_00646464;
  _DAT_00534fa0 = &DAT_00646464;
  _DAT_00534fc0 = &DAT_00646464;
  DAT_00534f30 = 0;
  DAT_00534f34 = 0;
  _DAT_00534f38 = 0;
  DAT_00534f40 = 0x508484a4;
  _DAT_00534f44 = 0;
  DAT_00534f50 = 0xc0600000;
  DAT_00534f54 = 0xc0600000;
  _DAT_00534f58 = 0;
  _DAT_00534f64 = 0;
  _DAT_00534f70 = 0xc0600000;
  _DAT_00534f74 = 0x40600000;
  _DAT_00534f78 = 0;
  _DAT_00534f84 = 0;
  _DAT_00534f90 = 0x40600000;
  _DAT_00534f94 = 0x40600000;
  _DAT_00534f98 = 0;
  _DAT_00534fa4 = 0;
  _DAT_00534fb0 = 0x40600000;
  _DAT_00534fb4 = 0xc0600000;
  _DAT_00534fb8 = 0;
  _DAT_00534fc4 = 0;
  puVar2 = &DAT_00534f50;
  puVar3 = &DAT_00534fd0;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

