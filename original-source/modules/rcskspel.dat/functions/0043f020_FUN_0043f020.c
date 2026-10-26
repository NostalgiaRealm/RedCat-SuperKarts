/*
 * FUN_0043f020 at 0043f020
 * undefined FUN_0043f020(void)
 * Address ranges: 0043f020-0043f1a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f020(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 local_158 [32];
  char local_138 [52];
  char local_104 [260];
  
  FUN_004afce0(s_Adding_object_with_sample_type___004ecad0,param_2);
  if (param_2 == -1) {
    return;
  }
  FUN_004be8cb(local_158,0x1d,s_etappe_d_ini_004ecaf4,DAT_0053b9b4);
  FUN_004b1d60(local_158);
  iVar2 = FUN_004b1ed0(s_sounds_004ecb0c,s_count_004ecb04);
  if (iVar2 < 1) {
    return;
  }
  FUN_004be8cb(local_158,0x1d,&DAT_004ecb14,param_2);
  FUN_004b1f10(s_sounds_004ecb18,local_158,local_104,0x103);
  iVar2 = -1;
  pcVar4 = local_104;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    return;
  }
  iVar2 = FUN_004b1f60(local_104,&DAT_004ecb20);
  if (1 < iVar2) {
    FUN_004b2110(1,local_138,0x31);
    FUN_004bfcb1(local_138);
    if ((((DAT_0053b9b4 != 1) || (iVar2 = __strcmpi(local_138,s_KAKTUS_004ecb24), iVar2 != 0)) &&
        (iVar2 = FUN_0043b5b0(local_138), iVar2 != -1)) && (iVar2 != 0xff)) {
      uVar3 = FUN_0049dec0(iVar2);
      *(undefined4 *)(param_1 * 0xd0 + 0x18 + DAT_0067ee20) = uVar3;
      *(undefined4 *)(param_1 * 0xd0 + 0x50 + DAT_0067ee20) = 1;
      FUN_004afce0(s__s__d____Source_name___s___index_004ecb9c,
                   s_D__work_rcsk_Code_game_tob_main__004ecb78,0x284,local_138,uVar3);
      return;
    }
    FUN_004afce0(s__s__d____Error_finding_for_sourc_004ecb50,
                 s_D__work_rcsk_Code_game_tob_main__004ecb2c,0x27b);
    return;
  }
  return;
}

