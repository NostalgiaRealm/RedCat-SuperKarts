/*
 * FUN_0040fa50 at 0040fa50
 * undefined FUN_0040fa50(void)
 * Address ranges: 0040fa50-0040fad8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040fa50(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  char local_28 [4];
  char local_24 [4];
  char local_20 [4];
  char local_1c [4];
  undefined1 local_18 [24];
  
  local_28 = (char  [4])s_CATCHUP_DUR_d_004df5bc._0_4_;
  local_24 = (char  [4])s_CATCHUP_DUR_d_004df5bc._4_4_;
  local_20 = (char  [4])s_CATCHUP_DUR_d_004df5bc._8_4_;
  local_1c._0_2_ = s_CATCHUP_DUR_d_004df5bc._12_2_;
  iVar3 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x208);
  do {
    iVar3 = iVar3 + 1;
    FUN_004be8cb(local_18,0x16,local_28,iVar3);
    uVar1 = FUN_004b1ed0(PTR_s_RCR_GLOBAL_004df2a8,local_18);
    FUN_004afce0(s__s__d____Read_key__s____d___004df5f8,s_D__work_rcsk_Code_game_ai_rcr_se_004df5cc,
                 0x1f8,local_18,uVar1);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 5);
  return;
}

