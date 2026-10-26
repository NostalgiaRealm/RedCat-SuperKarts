/*
 * FUN_0040a83c at 0040a83c
 * undefined __cdecl FUN_0040a83c(int param_1, undefined4 param_2)
 * Address ranges: 0040a83c-0040a8b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040a83c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_smacker_key__Unkno_00431664);
  }
  else {
    iVar1 = FUN_0040a7d5();
    if (iVar1 == -1) {
      FUN_0040187a((byte *)s__s__d_____set_smacker_key__No_fr_00431618);
    }
    else {
      *(undefined4 *)(&DAT_0043d470 + iVar1 * 8) = param_2;
      *(int *)(&DAT_0043d474 + iVar1 * 8) = param_1;
    }
  }
  return;
}

