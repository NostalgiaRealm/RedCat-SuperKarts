/*
 * FUN_00442a30 at 00442a30
 * undefined FUN_00442a30(void)
 * Address ranges: 00442a30-00442ad4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442a30(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  FUN_004bb690();
  if (DAT_0053b9b0 == 0) {
    FUN_004afce0(s_Loading_texture_anims_for_16_bit_004eda54);
    FUN_004438a0();
  }
  else {
    FUN_004afce0(s_Loading_texture_anims_for_8_bit_m_004eda2c);
    FUN_004437c0();
  }
  pcVar4 = s_s_shadow_PCX_004ed338;
  iVar1 = (&DAT_0053a6a4)[DAT_0053b9b4 * 0x25];
  do {
    iVar2 = *(int *)(pcVar4 + 0x40);
    if (iVar2 == 3) {
      iVar2 = FUN_0049b190(pcVar4);
      *(int *)(pcVar4 + 0x44) = iVar2;
      if (iVar2 == -1) {
        FUN_004afee0(s___s___d__Texture__s_not_found__004edaa0,
                     s_D__work_rcsk_Code_game_txt_main__004eda7c,0xe1,pcVar4);
      }
    }
    else if ((iVar2 == iVar1) || (iVar2 == 2)) {
      uVar3 = FUN_004a6060(pcVar4);
      *(undefined4 *)(pcVar4 + 0x44) = uVar3;
    }
    pcVar4 = pcVar4 + 0x58;
  } while ((int)pcVar4 < 0x4ed8b8);
  return;
}

