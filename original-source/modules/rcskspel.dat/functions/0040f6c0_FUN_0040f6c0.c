/*
 * FUN_0040f6c0 at 0040f6c0
 * undefined FUN_0040f6c0(void)
 * Address ranges: 0040f6c0-0040f7b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040f6c0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  char local_60 [4];
  char local_5c [4];
  char local_58 [4];
  char local_54 [4];
  char local_50;
  undefined1 local_4c [24];
  undefined1 local_34 [52];
  
  local_60 = (char  [4])s_MAX_BONUS_DIST_d_004df3f8._0_4_;
  local_58 = (char  [4])s_MAX_BONUS_DIST_d_004df3f8._8_4_;
  local_5c = (char  [4])s_MAX_BONUS_DIST_d_004df3f8._4_4_;
  puVar4 = (undefined4 *)(param_1 + 200);
  local_50 = s_MAX_BONUS_DIST_d_004df3f8[0x10];
  local_54 = (char  [4])s_MAX_BONUS_DIST_d_004df3f8._12_4_;
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004be8cb(local_4c,0x16,local_60,iVar1);
    local_34[0] = 0;
    FUN_004b1f10(PTR_s_RCR_GLOBAL_004df2a8,local_4c,local_34,0x32);
    FUN_004afce0(s__s__d____Read_key__s____s___004df438,s_D__work_rcsk_Code_game_ai_rcr_se_004df40c,
                 0xf2,local_4c,local_34);
    iVar2 = FUN_004b1f60(local_34,&DAT_004df458);
    iVar6 = 0;
    puVar5 = puVar4;
    if (0 < DAT_00508610 + 1) {
      do {
        if (iVar2 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_004b20c0(iVar6);
          iVar2 = iVar2 + -1;
        }
        *puVar5 = uVar3;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar6 < DAT_00508610 + 1);
    }
    puVar4 = puVar4 + 10;
  } while (iVar1 < 5);
  return;
}

