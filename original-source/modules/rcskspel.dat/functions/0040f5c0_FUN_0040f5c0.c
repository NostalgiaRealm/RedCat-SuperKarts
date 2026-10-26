/*
 * FUN_0040f5c0 at 0040f5c0
 * undefined FUN_0040f5c0(void)
 * Address ranges: 0040f5c0-0040f6bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040f5c0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_64 [3];
  char local_58 [4];
  char local_54 [4];
  char local_50 [4];
  char local_4c;
  undefined1 local_48 [20];
  undefined1 local_34 [52];
  
  local_58 = (char  [4])s_BONUS_PREF_d_004df398._0_4_;
  local_54 = (char  [4])s_BONUS_PREF_d_004df398._4_4_;
  local_50 = (char  [4])s_BONUS_PREF_d_004df398._8_4_;
  local_4c = s_BONUS_PREF_d_004df398[0xc];
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004be8cb(local_48,0x12,local_58,iVar1);
    local_34[0] = 0;
    FUN_004b1f10(PTR_s_RCR_GLOBAL_004df2a8,local_48,local_34,0x32);
    FUN_004afce0(s__s__d____Read_key__s____s___004df3d4,s_D__work_rcsk_Code_game_ai_rcr_se_004df3a8,
                 0xb5,local_48,local_34);
    iVar2 = FUN_004b1f60(local_34,&DAT_004df3f4);
    iVar5 = 0;
    puVar4 = param_1;
    if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
      do {
        if (iVar2 == 0) {
          local_64[0] = CONCAT31(local_64[0]._1_3_,0x72);
        }
        else {
          FUN_004b2110(iVar5,local_64,10);
          iVar2 = iVar2 + -1;
        }
        uVar3 = FUN_0040f410(local_64[0]);
        *puVar4 = uVar3;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar5 < DAT_00508610 + 1);
    }
    param_1 = param_1 + 10;
  } while (iVar1 < 5);
  return;
}

