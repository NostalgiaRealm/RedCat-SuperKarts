/*
 * FUN_004012c0 at 004012c0
 * undefined4 __cdecl FUN_004012c0(int param_1)
 * Address ranges: 004012c0-004013ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004012c0(int param_1)

{
  FILE *pFVar1;
  int iVar2;
  char *pcVar3;
  char local_184 [128];
  CHAR local_104 [260];
  
  if (param_1 == 0) {
    pcVar3 = local_184;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
  }
  else {
    _strncpy(local_184,s__FIRST_004081f4,0x80);
    FUN_004019af(local_104,0x104,(byte *)s__sRTTMENU_SHELLTRO_AVI_004081dc);
    pFVar1 = (FILE *)FUN_00401766(local_104,&DAT_00408030);
    if (pFVar1 == (FILE *)0x0) {
      FUN_004019af(local_104,0x104,(byte *)s__sRTTMENU_SHELLTRO_MOV_004081c4);
    }
    else {
      FUN_004019af(local_104,0x104,(byte *)s__sRTTMENU_SHELLTRO_AVI_004081dc);
      FUN_004016f0(pFVar1);
    }
  }
LAB_00401371:
  iVar2 = FUN_00401140((uint *)s_rcskmenu_dat_004081b4,local_184);
  switch(iVar2) {
  case 0x28:
  case 0x29:
    break;
  default:
    return 0;
  case 0x2d:
    FUN_004012a0();
    return 0;
  case 0xff:
    FUN_00401140((uint *)s_RCMovie_dat_00408198,local_104);
    return 0;
  }
  iVar2 = FUN_00401140((uint *)s_rcskspel_dat_004081a4,&DAT_00408c00);
  if (iVar2 == 0xff) {
    return 1;
  }
  goto LAB_00401371;
}

