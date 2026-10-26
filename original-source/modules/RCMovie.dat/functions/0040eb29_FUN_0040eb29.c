/*
 * FUN_0040eb29 at 0040eb29
 * undefined __cdecl FUN_0040eb29(void * param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 0040eb29-0040ec2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040eb29(void *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int local_8;
  
  if (DAT_0043d768 == 0) {
    if (DAT_0043d764 == 0) {
      FUN_0040187a((byte *)s__s__d____palette_was_not_initial_00432b28);
    }
    if (param_2 < 0) {
      FUN_0040187a((byte *)s__s__d____illegal_palette_base_en_00432b58);
    }
    if ((param_2 + param_3 < 0) || (0x100 < param_2 + param_3)) {
      FUN_0040187a((byte *)s__s__d____trying_to_reference_an_i_00432b8c);
    }
    if (((param_4 != 0) && (param_4 != 0x40)) && (param_4 != 0x80)) {
      FUN_0040187a((byte *)s__s__d____illegal_flag_value__d_00432bd4);
    }
    for (local_8 = param_2; local_8 < param_2 + param_3; local_8 = local_8 + 1) {
      *(undefined1 *)((int)param_1 + local_8 * 4 + 3) = (undefined1)param_4;
    }
    if (param_5 != 0) {
      FUN_0040e96f(param_1,param_1,param_2,param_3);
    }
  }
  return;
}

