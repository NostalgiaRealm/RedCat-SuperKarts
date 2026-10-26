/*
 * FUN_0040fbe0 at 0040fbe0
 * undefined FUN_0040fbe0(void)
 * Address ranges: 0040fbe0-0040fc8e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040fbe0(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((0 < param_2) && (param_2 < 6)) {
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (DAT_00508610 < param_3) {
      param_3 = DAT_00508610;
    }
    return *(undefined4 *)(param_1 + (param_3 + (param_2 * 5 + 0x14) * 2) * 4);
  }
  FUN_004afce0(s_Position_PL___d__004df668,DAT_0053be60);
  iVar3 = 0;
  if (0 < DAT_00508610) {
    do {
      cVar1 = FUN_00417e90(0);
      uVar2 = DAT_0053be60;
      if (cVar1 == '\0') {
        uVar2 = DAT_005081b8;
      }
      FUN_004afce0(s_Position_racer__d____d_004df67c,iVar3,uVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00508610);
  }
  FUN_004afee0(s__s__d____Setting__d_should_be_in_004df6c0,
               s_D__work_rcsk_Code_game_ai_rcr_se_004df694,0x27d,param_2,1,5,param_3,0,DAT_00508610)
  ;
  return 0;
}

