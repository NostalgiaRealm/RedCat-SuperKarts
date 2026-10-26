/*
 * FUN_00406d7c at 00406d7c
 * undefined4 __cdecl FUN_00406d7c(int param_1)
 * Address ranges: 00406d7c-00406e0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00406d7c(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0xd;
  while( true ) {
    if (local_8 < 1) {
      return 0;
    }
    iVar1 = FUN_00406e0e(param_1,local_8);
    if (iVar1 == 0x2af9) break;
    if (iVar1 != 0x2afa) {
      FUN_004015a6((byte *)s_Sound_mode_used___d___freq__d__b_0042f79c);
      return 1;
    }
    local_8 = local_8 + -1;
  }
  return 0;
}

