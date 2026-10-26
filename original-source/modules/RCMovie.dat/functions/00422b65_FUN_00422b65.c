/*
 * FUN_00422b65 at 00422b65
 * uint __cdecl FUN_00422b65(int param_1)
 * Address ranges: 00422b65-00422b8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_00422b65(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_0043f818;
  while( true ) {
    if (DAT_0043f818 + DAT_0043f814 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}

