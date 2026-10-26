/*
 * FUN_00424f70 at 00424f70
 * undefined FUN_00424f70(void)
 * Address ranges: 00424f70-004251e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424f70(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_18;
  undefined1 local_14 [20];
  
  FUN_004afce0(s__s__d____Game_etappe_id_before_d_004e70d4,
               s_D__work_rcsk_Code_game_gfx_pbar__004e70b0,0x13d,DAT_0053b9b4);
  FUN_004afce0(s__s__d____Resolution_before_draw__004e712c,
               s_D__work_rcsk_Code_game_gfx_pbar__004e7108,0x142,DAT_0053b9ac);
  FUN_00424360(1,DAT_0053b9b4);
  FUN_004afce0(s__s__d____Game_etappe_id_after_dr_004e7180,
               s_D__work_rcsk_Code_game_gfx_pbar__004e715c,0x14a,DAT_0053b9b4);
  iVar4 = (param_1 * 7) / 100 + 1;
  if (7 < iVar4) {
    iVar4 = 7;
  }
  uVar1 = FUN_00428df0();
  switch(uVar1) {
  case 0:
    FUN_004bea92(local_14,s_image_0_d_pcx_004e71d4,iVar4);
    piVar2 = (int *)FUN_004b2c80(local_14,&param_1,&local_18);
    FUN_00430e10(piVar2,0xfe);
    uVar1 = 199;
    iVar3 = param_1 / 2;
    iVar4 = iVar3 + 0x9f;
    iVar5 = 199 - local_18;
    iVar6 = 0x9f;
    break;
  case 1:
    FUN_004bea92(local_14,s_image_0_d_pcx_004e71c4,iVar4);
    piVar2 = (int *)FUN_004b2c80(local_14,&param_1,&local_18);
    FUN_00430e10(piVar2,0xfe);
    uVar1 = 0x1df;
    iVar3 = param_1 / 2;
    iVar4 = iVar3 + 0x13f;
    iVar5 = 0x1df - local_18;
    iVar6 = 0x13f;
    break;
  default:
    uVar1 = FUN_00428df0(0x194);
    FUN_004afee0(s___s___Illegal_resolution__d_at_l_004e7208,
                 s_D__work_rcsk_Code_game_gfx_pbar__004e71e4,uVar1);
    FUN_004aff70();
    return;
  case 3:
  case 4:
  case 6:
    FUN_004bea92(local_14,s_image_0_d_tga_004e71b4,iVar4);
    piVar2 = (int *)FUN_004ac010(local_14,&local_18,&param_1,0x800,&DAT_006ab7c8);
    FUN_00430e10(piVar2,0);
    iVar4 = (DAT_004fe930 * local_18) / 0x500;
    FUN_004b6ec0(piVar2,DAT_006a64c0,0,0,local_18,param_1,(DAT_004fe930 / 2 - iVar4) + -1,
                 (DAT_004fe934 - (DAT_004fe934 * param_1) / 0x1e0) + -1,
                 DAT_004fe930 / 2 + -1 + iVar4,DAT_004fe934 + -1,8);
    (**(code **)(*piVar2 + 8))(piVar2);
    FUN_004aff70();
    return;
  }
  FUN_004b6ec0(piVar2,DAT_006a64c0,0,0,param_1,local_18,iVar6 - iVar3,iVar5,iVar4,uVar1,8);
  (**(code **)(*piVar2 + 8))(piVar2);
  FUN_004aff70();
  return;
}

