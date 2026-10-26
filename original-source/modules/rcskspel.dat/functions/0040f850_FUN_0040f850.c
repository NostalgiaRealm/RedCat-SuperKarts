/*
 * FUN_0040f850 at 0040f850
 * undefined FUN_0040f850(void)
 * Address ranges: 0040f850-0040f8d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040f850(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  char local_1c [4];
  char local_18 [4];
  char local_14 [2];
  char local_12;
  undefined1 local_10 [16];
  
  local_1c = (char  [4])s_REACTION_d_004df4b8._0_4_;
  local_18 = (char  [4])s_REACTION_d_004df4b8._4_4_;
  local_14 = (char  [2])s_REACTION_d_004df4b8._8_2_;
  local_12 = s_REACTION_d_004df4b8[10];
  iVar3 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x1a4);
  do {
    iVar3 = iVar3 + 1;
    FUN_004be8cb(local_10,0x10,local_1c,iVar3);
    uVar1 = FUN_004b1ed0(PTR_s_RCR_GLOBAL_004df2a8,local_10);
    FUN_004afce0(s__s__d____Read_key__s____d___004df4f0,s_D__work_rcsk_Code_game_ai_rcr_se_004df4c4,
                 0x14c,local_10,uVar1);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 5);
  return;
}

