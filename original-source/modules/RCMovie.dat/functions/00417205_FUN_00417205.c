/*
 * FUN_00417205 at 00417205
 * undefined __cdecl FUN_00417205(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7)
 * Address ranges: 00417205-0041729b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_00417205(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  if ((&DAT_0043db90)[param_1 * 0x1c] == '\0') {
    (&DAT_0043db90)[param_1 * 0x1c] = 1;
    *(undefined4 *)(&DAT_0043db94 + param_1 * 0x1c) = param_2;
    *(undefined4 *)(&DAT_0043db98 + param_1 * 0x1c) = param_3;
    *(undefined4 *)(&DAT_0043db9c + param_1 * 0x1c) = param_4;
    *(undefined4 *)(&DAT_0043dba0 + param_1 * 0x1c) = param_5;
    *(undefined4 *)(&DAT_0043dba4 + param_1 * 0x1c) = param_6;
    *(undefined4 *)(&DAT_0043dba8 + param_1 * 0x1c) = param_7;
  }
  else {
    FUN_0040187a((byte *)s__s__d_____add_control_to_list__c_004357d8);
  }
  return;
}

