/*
 * FUN_00402850 at 00402850
 * undefined FUN_00402850(void)
 * Address ranges: 00402850-004028bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402850(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < DAT_00508610) {
    FUN_004afee0(s_Illegal_cop__this_is_a_racer___s_004dda10,
                 s_D__work_rcsk_Code_game_ai_fsm_cp_004dd9ec,0x21e);
    return;
  }
  iVar2 = 0;
  iVar1 = (&DAT_00503ef0)[param_1 * 0x47];
  do {
    if ((&DAT_00505af0)[iVar2] == iVar1) {
      (&DAT_00505af0)[iVar2] = 0xffffffff;
      iVar2 = 0x14;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  (&DAT_00503ef0)[param_1 * 0x47] = 0xffffffff;
  FUN_004023a0(0xffffffff,param_1);
  return;
}

