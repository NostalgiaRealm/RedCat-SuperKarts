/*
 * FUN_00419e30 at 00419e30
 * undefined FUN_00419e30(void)
 * Address ranges: 00419e30-00419f60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419e30(void)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  
  FUN_00419d50();
  iVar1 = FUN_00419370(4);
  do {
    if (iVar1 < 0) {
      return;
    }
    switch(iVar1) {
    case 0:
      pcVar6 = s_Current_value_004e1ebc;
      pcVar5 = s_Parameter_A__steepness_004e1ecc;
      uVar4 = 0x3f800000;
      uVar3 = 0x3f800000;
      puVar2 = &DAT_00505bec + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 1:
      pcVar6 = s_Current_value_004e1ee4;
      pcVar5 = s_Parameter_B__fall_off_004e1ef4;
      uVar4 = 0x3f000000;
      uVar3 = 0x3f000000;
      puVar2 = &DAT_00505bf4 + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 2:
      pcVar6 = s_Current_value_004e1f0c;
      pcVar5 = s_Parameter_C__fall_off_moment_004e1f1c;
      uVar4 = 0x3f000000;
      uVar3 = 0x3f000000;
      puVar2 = &DAT_00505bfc + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 3:
      pcVar6 = s_Current_factor_004e1f3c;
      pcVar5 = s_Friction_factor_of_tires_004e1f4c;
      uVar4 = 0x3ba3d70a;
      uVar3 = 0x3ba3d70a;
      puVar2 = &DAT_00505c04 + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    default:
      goto switchD_00419e50_default;
    }
    FUN_00419290(puVar2,uVar3,uVar4,pcVar5,pcVar6);
switchD_00419e50_default:
    FUN_00419d50();
    iVar1 = FUN_00419370(4);
  } while( true );
}

