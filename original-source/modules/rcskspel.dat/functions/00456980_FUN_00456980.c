/*
 * FUN_00456980 at 00456980
 * undefined FUN_00456980(void)
 * Address ranges: 00456980-004569d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00456980(float param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0.1) {
    uVar1 = __ftol(s_D__work_rcsk_Code_game_Bon_shotb_004f222c,0x358);
    uVar1 = __ftol(uVar1);
    uVar1 = __ftol(uVar1);
    FUN_00430dd0(uVar1);
    _DAT_00544a80 = param_1;
    return;
  }
  _DAT_00544a80 = param_1;
  return;
}

