/*
 * FUN_00424108 at 00424108
 * undefined __cdecl FUN_00424108(uint param_1)
 * Address ranges: 00424108-0042416e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00424108(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_0043e2c4 = param_1;
  puVar1 = &DAT_004374a8;
  do {
    if (param_1 == *puVar1) {
      _DAT_0043e2c0 = *(undefined4 *)(iVar2 * 8 + 0x4374ac);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x437610);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_0043e2c0 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (_DAT_0043e2c0 = 8, 0xca < param_1)) {
    _DAT_0043e2c0 = 0x16;
  }
  return;
}

