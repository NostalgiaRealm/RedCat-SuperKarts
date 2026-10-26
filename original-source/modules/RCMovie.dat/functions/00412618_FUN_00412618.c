/*
 * FUN_00412618 at 00412618
 * undefined __cdecl FUN_00412618(int param_1, byte * param_2, int param_3, int param_4, int param_5, int param_6)
 * Address ranges: 00412618-00412686
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00412618(int param_1,byte *param_2,int param_3,int param_4,int param_5,int param_6)

{
  if (param_3 == 0) {
    FUN_00412173(param_1,(LPCSTR)param_2,param_4,param_6);
  }
  else if (param_3 == 1) {
    FUN_004122f5(param_1,param_2,param_5,param_6);
  }
  else {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__inv_00434530);
  }
  return;
}

