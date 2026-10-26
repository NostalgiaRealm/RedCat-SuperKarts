/*
 * FUN_00426aa0 at 00426aa0
 * undefined FUN_00426aa0(void)
 * Address ranges: 00426aa0-00426b83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426aa0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_0053ba2c != 0) && (DAT_004e0d14 != '\0')) {
    if (3 < param_2) {
      if (DAT_0052d4f0 < 4) {
        iVar1 = FUN_004265a0();
        if (iVar1 == -1) {
          DAT_0052d4f0 = 3;
          return;
        }
        FUN_00426900(iVar1,param_1,param_2);
        DAT_0052d4f0 = param_2;
        DAT_004e763c = iVar1;
        return;
      }
      if (DAT_004e763c == -1) {
        FUN_004afee0(s__s___d__No_current_skidmark__004e7714,
                     s_D__work_rcsk_Code_game_gfx_skid__004e76f0,0x1ad);
      }
      iVar1 = FUN_00426540(DAT_004e763c);
      if (*(int *)(&DAT_0050f8b4 + iVar1 * 0x1910) == 0) {
        DAT_004e763c = 0xffffffff;
        DAT_0052d4f0 = 3;
        return;
      }
      FUN_004269e0(DAT_004e763c,param_1,param_2);
    }
    DAT_0052d4f0 = param_2;
  }
  return;
}

