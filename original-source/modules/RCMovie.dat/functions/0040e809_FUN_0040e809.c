/*
 * FUN_0040e809 at 0040e809
 * undefined __cdecl FUN_0040e809(int param_1)
 * Address ranges: 0040e809-0040e96e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040e809(int param_1)

{
  int iVar1;
  
  if (DAT_0043d768 == 0) {
    if (DAT_0043d764 == 0) {
      FUN_0040187a((byte *)s__s__d____palette_was_not_initial_00432880);
    }
    if (param_1 == 0) {
      FUN_004028c2(DAT_00438434);
      iVar1 = (**(code **)(*DAT_00438434 + 0x7c))(DAT_00438434,DAT_0043d75c);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_set_the_palet_004328b0);
      }
    }
    else if (param_1 == 1) {
      FUN_004028c2(DAT_00438438);
      iVar1 = (**(code **)(*DAT_00438438 + 0x7c))(DAT_00438438,DAT_0043d75c);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_set_the_palet_004328e4);
      }
    }
    else if (param_1 == 2) {
      FUN_004028c2(DAT_00438418);
      iVar1 = (**(code **)(*DAT_00438418 + 0x7c))(DAT_00438418,DAT_0043d75c);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_set_the_palet_00432918);
      }
    }
    else {
      FUN_0040187a((byte *)s__s__d____unknown_focus_defined_0043294c);
    }
  }
  return;
}

