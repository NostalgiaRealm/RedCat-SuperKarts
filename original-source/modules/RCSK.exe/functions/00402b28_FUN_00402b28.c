/*
 * FUN_00402b28 at 00402b28
 * uint __cdecl FUN_00402b28(int param_1)
 * Address ranges: 00402b28-00402b52
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_00402b28(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_0040a018;
  while( true ) {
    if (DAT_0040a018 + DAT_0040a014 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}

