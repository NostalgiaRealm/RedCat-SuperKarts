/*
 * FUN_004b44b0 at 004b44b0
 * undefined FUN_004b44b0(void)
 * Address ranges: 004b44b0-004b4508
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b44b0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0xd;
  while( true ) {
    iVar1 = FUN_004b4510(param_1,iVar2);
    if (iVar1 == 0x2af9) {
      return 0;
    }
    if (iVar1 != 0x2afa) break;
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) {
      return 0;
    }
  }
  iVar1 = iVar2 * 0x10;
  FUN_004afce0(s_Sound_mode_used___d___freq__d__b_00500628,iVar2,
               *(undefined4 *)(&DAT_00500080 + iVar1),*(undefined4 *)(&DAT_00500084 + iVar1),
               *(undefined4 *)(&DAT_00500088 + iVar1));
  return 1;
}

