/*
 * FUN_0040e96f at 0040e96f
 * undefined4 __thiscall FUN_0040e96f(void * this, undefined4 param_1, int param_2, int param_3)
 * Address ranges: 0040e96f-0040ea4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040e96f(void *this,undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (DAT_0043d768 == 0) {
    if (DAT_0043d764 == 0) {
      FUN_0040187a((byte *)s__s__d____palette_was_not_initial_00432978);
    }
    if (param_2 < 0) {
      FUN_0040187a((byte *)s__s__d____illegal_palette_base_en_004329a8);
    }
    if ((param_2 + param_3 < 0) || (0x100 < param_2 + param_3)) {
      FUN_0040187a((byte *)s__s__d____trying_to_reference_an_i_004329dc);
    }
    iVar1 = (**(code **)(*DAT_0043d75c + 0x18))(DAT_0043d75c,0,param_2,param_3,param_1,this);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_set_entries___s__00432a24);
    }
  }
  return 0;
}

