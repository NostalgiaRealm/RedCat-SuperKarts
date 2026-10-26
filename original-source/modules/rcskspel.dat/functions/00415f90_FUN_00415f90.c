/*
 * FUN_00415f90 at 00415f90
 * undefined FUN_00415f90(void)
 * Address ranges: 00415f90-0041626d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00415f90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_c [12];
  
  if ((param_1 < 0) || (9 < param_1)) {
    FUN_004afee0(s__add_car__tryimg_to_add_an_inval_004e0dac,param_1,9);
  }
  if ((((DAT_005072b8 == '\0') || (param_9 = param_9 + 1, param_9 < 0)) ||
      (DAT_00508610 + 1 <= param_9)) || (iVar3 = param_9 * 0x14, (&DAT_005072c0)[param_9 * 5] != 1))
  {
    uVar7 = FUN_00493a20(param_2);
    puVar4 = (undefined4 *)FUN_004933c0(auStack_c,uVar7,param_3,param_4);
    uStack_30 = *puVar4;
    uStack_2c = puVar4[1];
    uStack_28 = puVar4[2];
  }
  else {
    uVar7 = *(undefined4 *)(&DAT_005072c4 + iVar3);
    uStack_30 = *(undefined4 *)(&DAT_005072c8 + iVar3);
    uStack_2c = *(undefined4 *)(&DAT_005072cc + iVar3);
    uStack_28 = *(undefined4 *)(&DAT_005072d0 + iVar3);
    (&DAT_005072c0)[param_9 * 5] = 0;
  }
  iVar8 = param_1 * 300;
  uVar5 = FUN_0049de80(s_TOEREN1_004e0374 + iVar8);
  uVar2 = (&DAT_004e0298)[param_1 * 0x4b];
  FUN_004afce0(s__s__d____Adding_object_004e0e0c,s_D__work_rcsk_Code_game_Car_main__004e0de8,0x25f);
  iVar6 = FUN_0048fb60(uStack_30,uStack_2c,uStack_28,0,0,0,uVar2,0,param_6,param_7,0,uVar5);
  iVar3 = iVar6 * 0xd0;
  puVar1 = (uint *)(iVar3 + 4 + DAT_0067ee20);
  *puVar1 = *puVar1 | 3;
  FUN_004afce0(s__s__d____Initializing_physics_004e0e48,s_D__work_rcsk_Code_game_Car_main__004e0e24,
               0x267);
  FUN_0048fda0(iVar6,0,0,0,0,*(undefined4 *)(&DAT_004e02a0 + iVar8),0x3e4ccccd,
               *(undefined4 *)(&DAT_004e02a4 + iVar8),*(undefined4 *)(&DAT_004e02a8 + iVar8));
  FUN_004afce0(s__s__d____Setting_chunk_angle_phy_004e0e8c,
               s_D__work_rcsk_Code_game_Car_main__004e0e68,0x26b);
  FUN_00493540(iVar6,uVar7,param_5);
  *(undefined4 *)(iVar3 + 0x20 + DAT_0067ee20) = uVar7;
  *(undefined4 *)(iVar3 + 0x1c + DAT_0067ee20) = uVar7;
  *(undefined4 *)(iVar3 + 0x38 + DAT_0067ee20) = param_4;
  if (((param_8 == 1) || (param_8 == 3)) || (param_8 == 4)) {
    *(undefined4 *)(iVar3 + 8 + DAT_0067ee20) = 1;
  }
  FUN_004afce0(s__s__d____Setting_waypoint_004e0ed8,s_D__work_rcsk_Code_game_Car_main__004e0eb4,
               0x278);
  iVar3 = iVar3 + DAT_0067ee20;
  uVar7 = FUN_00493430(uVar7,param_3,param_4);
  *(undefined4 *)(iVar3 + 0x24) = uVar7;
  FUN_004937e0(iVar6,0);
  FUN_00416570(iVar6);
  FUN_004165f0(iVar6,param_8);
  FUN_004939d0(iVar6);
  FUN_004a09e0();
  FUN_004afce0(s__s__d____Done_adding_car_004e0f18,s_D__work_rcsk_Code_game_Car_main__004e0ef4,0x296
              );
  return iVar6;
}

