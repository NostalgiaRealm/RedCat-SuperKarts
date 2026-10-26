/*
 * FUN_00402a47 at 00402a47
 * undefined __cdecl FUN_00402a47(uint param_1)
 * Address ranges: 00402a47-00402aad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00402a47(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_00408c08 = param_1;
  puVar1 = &DAT_00408250;
  do {
    if (param_1 == *puVar1) {
      DAT_00408c04 = *(undefined4 *)(iVar2 * 8 + 0x408254);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x4083b8);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    DAT_00408c04 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (DAT_00408c04 = 8, 0xca < param_1)) {
    DAT_00408c04 = 0x16;
  }
  return;
}

