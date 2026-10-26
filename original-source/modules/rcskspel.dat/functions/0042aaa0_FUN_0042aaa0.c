/*
 * FUN_0042aaa0 at 0042aaa0
 * undefined FUN_0042aaa0(void)
 * Address ranges: 0042aaa0-0042aadb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0042aaa0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != param_2) {
    uVar1 = *param_2;
    param_1[1] = 1;
    *param_1 = uVar1;
    param_1[2] = param_2[2];
    *(undefined1 *)(param_1 + 5) = *(undefined1 *)(param_2 + 5);
    *(undefined1 *)((int)param_1 + 0x15) = *(undefined1 *)((int)param_2 + 0x15);
    *(undefined1 *)((int)param_1 + 0x16) = *(undefined1 *)((int)param_2 + 0x16);
    *(undefined1 *)((int)param_1 + 0x17) = *(undefined1 *)((int)param_2 + 0x17);
    *(undefined1 *)(param_1 + 6) = *(undefined1 *)(param_2 + 6);
  }
  return;
}

