/*
 * FUN_004424f0 at 004424f0
 * undefined FUN_004424f0(void)
 * Address ranges: 004424f0-0044256e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004424f0(void)

{
  int iVar1;
  
  iVar1 = FUN_0042a4d0(0);
  if (DAT_0053ba0c == 0xfffffff) {
    _DAT_0053d328 = 0;
    (&DAT_0053d2d8)[DAT_0053d32c] = iVar1;
    DAT_0053d32c = DAT_0053d32c + 1;
    return;
  }
  if ((DAT_0053d32c < 0) || (9 < DAT_0053d32c)) {
    FUN_004afee0(s__s___d__Index_current_time_check_004ed1e8,
                 s_D__work_rcsk_Code_game_tr_tchk_c_004ed1c4,0x46,DAT_0053d32c);
  }
  (&DAT_0053d2d8)[DAT_0053d32c] = iVar1;
  _DAT_0053d328 = iVar1 - (&DAT_0053d300)[DAT_0053d32c];
  DAT_0053d32c = DAT_0053d32c + 1;
  return;
}

