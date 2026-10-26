/*
 * FUN_00419550 at 00419550
 * undefined FUN_00419550(void)
 * Address ranges: 00419550-00419769
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419550(void)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  
  FUN_00419480();
  iVar1 = FUN_00419370(9);
  do {
    if (iVar1 < 0) {
      return;
    }
    switch(iVar1) {
    case 0:
      pcVar6 = s_Current_weight_004e1974;
      pcVar5 = s_Adjust_car_weight_004e1984;
      uVar4 = 0x42480000;
      uVar3 = 0x42480000;
      puVar2 = &DAT_00505b60 + DAT_0053be2c * 0xac;
      break;
    case 1:
      pcVar6 = s_Current_share_value_004e1998;
      pcVar5 = s_Adjust_car_weight_share_front_004e19ac;
      uVar4 = 0x3d4ccccd;
      uVar3 = 0x3d4ccccd;
      puVar2 = &DAT_00505b64 + DAT_0053be2c * 0xac;
      break;
    case 2:
      pcVar6 = s_Current_share_value_004e19cc;
      pcVar5 = s_Adjust_car_weight_share_rear_004e19e0;
      uVar4 = 0x3d4ccccd;
      uVar3 = 0x3d4ccccd;
      puVar2 = &DAT_00505b68 + DAT_0053be2c * 0xac;
      break;
    case 3:
      pcVar6 = s_Current_wheel_radius_004e1a00;
      pcVar5 = s_Adjust_wheel_radius_004e1a18;
      uVar4 = 0x3c23d70a;
      uVar3 = 0x3c23d70a;
      puVar2 = &DAT_00505b6c + DAT_0053be2c * 0xac;
      break;
    case 4:
      pcVar6 = s_Current_distance_004e1a2c;
      pcVar5 = s_Adjust_distance_GC_>front_wheels_004e1a40;
      uVar4 = 0x3d4ccccd;
      uVar3 = 0x3d4ccccd;
      puVar2 = &DAT_00505b70 + DAT_0053be2c * 0xac;
      break;
    case 5:
      pcVar6 = s_Current_distance_004e1a64;
      pcVar5 = s_Adjust_distance_GC_>rear_wheels_004e1a78;
      uVar4 = 0x3d4ccccd;
      uVar3 = 0x3d4ccccd;
      puVar2 = &DAT_00505b74 + DAT_0053be2c * 0xac;
      break;
    case 6:
      pcVar6 = s_Current_surface_004e1a98;
      pcVar5 = s_Adjust_surface_exposed_to_air_fr_004e1aa8;
      uVar4 = 0x3dcccccd;
      uVar3 = 0x3dcccccd;
      puVar2 = &DAT_00505b78 + DAT_0053be2c * 0xac;
      break;
    case 7:
      pcVar6 = s_Current_angle_004e1ad0;
      pcVar5 = s_Adjust_maximum_steering_angle_004e1ae0;
      uVar4 = 0x3ba3d70a;
      uVar3 = 0x3ba3d70a;
      puVar2 = &DAT_00505b7c + DAT_0053be2c * 0xac;
      break;
    case 8:
      pcVar6 = s_Current_force_004e1b00;
      pcVar5 = s_Adjust_maximum_brake_force_004e1b10;
      uVar4 = 0x437a0000;
      uVar3 = 0x437a0000;
      puVar2 = &DAT_00505b80 + DAT_0053be2c * 0xac;
      break;
    default:
      goto switchD_00419570_default;
    }
    FUN_00419290(puVar2,uVar3,uVar4,pcVar5,pcVar6);
switchD_00419570_default:
    FUN_00419480();
    iVar1 = FUN_00419370(9);
  } while( true );
}

