/*
 * FUN_0042aa50 at 0042aa50
 * undefined FUN_0042aa50(void)
 * Address ranges: 0042aa50-0042aa98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall
FUN_0042aa50(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5
            ,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  FUN_0042aae0(param_2);
  *(undefined4 *)(param_1 + 4) = 1;
  FUN_0042ab00(param_3);
  *(undefined1 *)(param_1 + 0x15) = param_5;
  *(undefined1 *)(param_1 + 0x14) = param_4;
  *(undefined1 *)(param_1 + 0x18) = param_8;
  *(undefined1 *)(param_1 + 0x16) = param_6;
  *(undefined1 *)(param_1 + 0x17) = param_7;
  return param_1;
}

