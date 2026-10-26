/*
 * FUN_0044f390 at 0044f390
 * undefined FUN_0044f390(void)
 * Address ranges: 0044f390-0044f438
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044f390(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  FUN_004afce0(s___s_Adding_animation__d_at_line___004f0ea0,
               s_D__work_rcsk_Code_game_msh_mshAn_004f0e74,param_2,0xa5);
  if (*(int *)(param_1 + 0x60) == 0) {
LAB_0044f3e4:
    FUN_004398f0();
    puVar1 = *(undefined4 **)(param_1 + 0x50);
    *(undefined4 **)(param_1 + 0x50) = puVar1 + 1;
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 0x50);
    if (puVar1 == *(undefined4 **)(param_1 + 0x4c)) goto LAB_0044f3e4;
    *(undefined4 **)(param_1 + 0x50) = puVar1 + 1;
    if (puVar1 + 1 == *(undefined4 **)(param_1 + 0x4c)) {
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = param_2;
      }
      FUN_004398f0();
      goto LAB_0044f3fa;
    }
  }
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
LAB_0044f3fa:
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  *(undefined4 *)(param_1 + 100) = 0;
  if (*(int *)(param_1 + 0x60) != 0) {
    FUN_0044f500();
    FUN_0044eb90();
  }
  FUN_004afce0(s_SUCCEEDED_004f0ec4);
  return;
}

