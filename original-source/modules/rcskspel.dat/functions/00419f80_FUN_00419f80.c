/*
 * FUN_00419f80 at 00419f80
 * undefined FUN_00419f80(void)
 * Address ranges: 00419f80-0041a0b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419f80(void)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  
  FUN_00419dc0();
  iVar1 = FUN_00419370(4);
  do {
    if (iVar1 < 0) {
      return;
    }
    switch(iVar1) {
    case 0:
      pcVar6 = s_Current_value_004e1f68;
      pcVar5 = s_Parameter_A__steepness_004e1f78;
      uVar4 = 0x3f800000;
      uVar3 = 0x3f800000;
      puVar2 = &DAT_00505bd4 + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 1:
      pcVar6 = s_Current_value_004e1f90;
      pcVar5 = s_Parameter_B__fall_off_004e1fa0;
      uVar4 = 0x3f000000;
      uVar3 = 0x3f000000;
      puVar2 = &DAT_00505bdc + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 2:
      pcVar6 = s_Current_value_004e1fb8;
      pcVar5 = s_Parameter_C__fall_off_moment_004e1fc8;
      uVar4 = 0x3f000000;
      uVar3 = 0x3f000000;
      puVar2 = &DAT_00505be4 + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 3:
      pcVar6 = s_Current_factor_004e1fe8;
      pcVar5 = s_Friction_factor_of_tires_004e1ff8;
      uVar4 = 0x3ba3d70a;
      uVar3 = 0x3ba3d70a;
      puVar2 = &DAT_00505c04 + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
      break;
    default:
      goto switchD_00419fa0_default;
    }
    FUN_00419290(puVar2,uVar3,uVar4,pcVar5,pcVar6);
switchD_00419fa0_default:
    FUN_00419dc0();
    iVar1 = FUN_00419370(4);
  } while( true );
}

