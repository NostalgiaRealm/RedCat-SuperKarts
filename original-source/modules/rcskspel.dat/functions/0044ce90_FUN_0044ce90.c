/*
 * FUN_0044ce90 at 0044ce90
 * undefined FUN_0044ce90(void)
 * Address ranges: 0044ce90-0044cf48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044ce90(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_2 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afce0(s___Animation__s_adding__state_che_004f07c4,puVar1);
  if (param_1[0x1b] != param_3) {
    puVar1 = *(undefined1 **)(param_2 + 4);
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_004d2404;
    }
    FUN_004afce0(s___Animation__s_adding__state_che_004f07e8,puVar1);
    return;
  }
  puVar1 = *(undefined1 **)(param_2 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afce0(s___Animation__s_adding__size_chec_004f0814,puVar1);
  if (param_1[0x18] != 0) {
    puVar1 = *(undefined1 **)(param_2 + 4);
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_004d2404;
    }
    FUN_004afce0(s___Animation__s_adding__size_chec_004f0838,puVar1);
    return;
  }
  puVar1 = *(undefined1 **)(param_2 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afce0(s___Animation__s_will_be_added_004f0864,puVar1);
  param_1[0x1b] = param_4;
  (**(code **)*param_1)(param_2);
  return;
}

