/*
 * FUN_0042ab80 at 0042ab80
 * undefined FUN_0042ab80(void)
 * Address ranges: 0042ab80-0042abb4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0042ab80(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 3)) {
    *(int *)(param_1 + 0x1c) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  FUN_004afce0(s__s__d____ERROR___Invalid_Physics_004e8cc0,
               s_D__work_rcsk_Code_game_Gm_ini_cp_004e8c9c,0x9e,param_2);
  return;
}

