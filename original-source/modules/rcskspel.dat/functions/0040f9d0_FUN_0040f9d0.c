/*
 * FUN_0040f9d0 at 0040f9d0
 * undefined FUN_0040f9d0(void)
 * Address ranges: 0040f9d0-0040fa4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040f9d0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  char local_20 [4];
  char local_1c [4];
  char local_18 [4];
  undefined1 local_14 [20];
  
  local_20 = (char  [4])s_CATCHUP_d_004df564._0_4_;
  local_1c = (char  [4])s_CATCHUP_d_004df564._4_4_;
  local_18._0_2_ = s_CATCHUP_d_004df564._8_2_;
  iVar3 = 0;
  puVar2 = (undefined4 *)(param_1 + 500);
  do {
    iVar3 = iVar3 + 1;
    FUN_004be8cb(local_14,0x12,local_20,iVar3);
    uVar1 = FUN_004b1ed0(PTR_s_RCR_GLOBAL_004df2a8,local_14);
    FUN_004afce0(s__s__d____Read_key__s____d___004df59c,s_D__work_rcsk_Code_game_ai_rcr_se_004df570,
                 0x1d6,local_14,uVar1);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 5);
  return;
}

