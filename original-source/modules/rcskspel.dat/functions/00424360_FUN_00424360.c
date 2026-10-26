/*
 * FUN_00424360 at 00424360
 * undefined FUN_00424360(void)
 * Address ranges: 00424360-004244ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424360(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uStack_44;
  undefined1 auStack_40 [64];
  
  iVar1 = param_2;
  if ((param_2 < 0) || (0x1d < param_2)) {
    FUN_004afee0(s__s___d__Incorrect_pcx_index___d_004e6ba8,
                 s_D__work_rcsk_Code_game_gfx_main__004e6b84,0x15d,param_2);
  }
  if ((DAT_0053b9ac < 0) || (3 < DAT_0053b9ac)) {
    FUN_004afee0(s__s___d__Illegal_value_for_game_i_004e6bec,
                 s_D__work_rcsk_Code_game_gfx_main__004e6bc8,0x164,DAT_0053b9ac);
  }
  if (DAT_0053b9b0 != 0) {
    FUN_004afce0(s_Loading_wait_screen_for_8_bit_mo_004e6c1c);
    if (DAT_0053b9ac == 0) {
      iVar2 = FUN_0042abc0();
      pcVar5 = s_e0_d__c_lo_pcx_004e6c50;
    }
    else {
      iVar2 = FUN_0042abc0();
      pcVar5 = s_e0_d__c_hi_pcx_004e6c40;
    }
    FUN_004bea92(auStack_40,pcVar5,iVar1,iVar2 + 0x41);
    FUN_004b2870(param_1,auStack_40,0x19);
    return;
  }
  FUN_004afce0(s_Loading_wait_screen_for_16_bit_m_004e6c60);
  iVar2 = FUN_0042abc0();
  FUN_004bea92(auStack_40,s_e0_d__c_hi_tga_004e6c88,iVar1,iVar2 + 0x41);
  piVar3 = (int *)FUN_004ac010(auStack_40,&uStack_44,&param_2,0x800,&DAT_006ab7c8);
  uVar4 = FUN_004242b0(param_1);
  FUN_004b6ec0(piVar3,uVar4,0,0,uStack_44,param_2,0,0,DAT_004fe930,DAT_004fe934,0);
  (**(code **)(*piVar3 + 8))(piVar3);
  return;
}

