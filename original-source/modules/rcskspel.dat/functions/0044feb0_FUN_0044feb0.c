/*
 * FUN_0044feb0 at 0044feb0
 * undefined FUN_0044feb0(void)
 * Address ranges: 0044feb0-0044fef6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044feb0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004afee0(s___s_Bonus_already_inited_at_line_004f104c,
                 s_D__work_rcsk_Code_game_Bon_Bonus_004f1020,0x49);
  }
  if (param_2 != -1) {
    FUN_004502d0(param_2);
    FUN_0044ff10(1);
    return;
  }
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

