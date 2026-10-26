/*
 * FUN_0041f900 at 0041f900
 * undefined FUN_0041f900(void)
 * Address ranges: 0041f900-0041f9a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041f900(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00429050();
  if (iVar1 != 0) {
    if (DAT_005086a0 == 1) {
      iVar1 = FUN_004be6c9();
      uVar2 = *(undefined4 *)(&DAT_004e30b0 + (iVar1 % 6) * 0x44);
    }
    else if (DAT_005086a0 == 2) {
      iVar1 = FUN_004be6c9();
      uVar2 = *(undefined4 *)(&DAT_004e3248 + (iVar1 % 5) * 0x44);
    }
    else {
      if (DAT_005086a0 != 3) {
        FUN_004afee0(s__s___d__Illegal_value_for_g_time_004e39b0,
                     s_D__work_rcsk_Code_game_ev_cops_c_004e398c,0xf8,DAT_005086a0);
        return;
      }
      iVar1 = FUN_004be6c9();
      uVar2 = *(undefined4 *)(&DAT_004e33a0 + (iVar1 % 5) * 0x44);
    }
    uVar3 = 0;
    FUN_0049dd20(uVar2);
    FUN_0049d780(uVar3);
  }
  return;
}

