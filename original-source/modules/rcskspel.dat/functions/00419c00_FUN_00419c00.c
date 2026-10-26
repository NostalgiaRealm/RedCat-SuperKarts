/*
 * FUN_00419c00 at 00419c00
 * undefined FUN_00419c00(void)
 * Address ranges: 00419c00-00419d37
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419c00(void)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  
  FUN_00419b80();
  iVar1 = FUN_00419370(5);
  do {
    if (iVar1 < 0) {
      return;
    }
    switch(iVar1) {
    case 0:
      pcVar6 = s_Current_value_004e1ce0;
      pcVar5 = s_Parameter_A__max_power_004e1cf0;
      uVar4 = 0x358637bd;
      uVar3 = 0x358637bd;
      puVar2 = &DAT_00505b84 + (DAT_0053bef0 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 1:
      pcVar6 = s_Current_value_004e1d08;
      pcVar5 = s_Parameter_B__peak_position_004e1d18;
      uVar4 = 0x3ba3d70a;
      uVar3 = 0x3ba3d70a;
      puVar2 = &DAT_00505b8c + (DAT_0053bef0 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 2:
      pcVar6 = s_Current_value_004e1d34;
      pcVar5 = s_Parameter_C__default_force_004e1d44;
      uVar4 = 0x40a00000;
      uVar3 = 0x40a00000;
      puVar2 = &DAT_00505b94 + (DAT_0053bef0 + DAT_0053be2c * 0x2b) * 4;
      break;
    case 3:
      FUN_00419950();
      goto switchD_00419c20_default;
    case 4:
      pcVar6 = s_Current_maximum_004e1d60;
      pcVar5 = s_Maximum_RPM_in_gear_004e1d70;
      uVar4 = 0x42c80000;
      uVar3 = 0x42c80000;
      puVar2 = &DAT_00505bcc + (DAT_0053bef0 + DAT_0053be2c * 0x2b) * 4;
      break;
    default:
      goto switchD_00419c20_default;
    }
    FUN_00419290(puVar2,uVar3,uVar4,pcVar5,pcVar6);
switchD_00419c20_default:
    FUN_00419b80();
    iVar1 = FUN_00419370(5);
  } while( true );
}

