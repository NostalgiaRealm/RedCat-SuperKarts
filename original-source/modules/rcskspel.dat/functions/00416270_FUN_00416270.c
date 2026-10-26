/*
 * FUN_00416270 at 00416270
 * undefined FUN_00416270(void)
 * Address ranges: 00416270-00416560
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416270(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = FUN_004a6200(s_S_SHADOW_004e0f34);
  DAT_0053b9d4 = FUN_004a02b0(0,0,0,0,0,0,uVar2,0,0);
  *(undefined4 *)(DAT_006a5c38 + DAT_0053b9d4 * 0xa9 + 0xa1) = 2;
  if (DAT_0053b9d4 < 0) {
    FUN_004afee0(s__init_car_shadow_object__Not_eno_004e0f40);
  }
  iVar3 = *(int *)(*(int *)(*(int *)(DAT_006a5c38 + DAT_0053b9d4 + 4 + DAT_0053b9d4 * 0xa8) * 9 + 4
                           + DAT_006a5f78) +
                  *(int *)(DAT_006a5c38 + DAT_0053b9d4 + DAT_0053b9d4 * 0xa8 + 8) * 4) * 0x10;
  iVar1 = *(int *)(iVar3 + DAT_006a5f30);
  iVar3 = *(int *)(iVar3 + DAT_006a5f30 + 4);
  iVar4 = iVar1 * 0xbc;
  if (*(int *)(iVar4 + 0x84 + DAT_006a5ee0) != 4) {
    FUN_004afee0(s__s__d____shadow_mesh___d__is_not_004e0f98,
                 s_D__work_rcsk_Code_game_Car_main__004e0f74,0x2b5,iVar1);
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x10) = 0x80000000;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x14) = 0;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x30) = 0x80000000;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x34) = 0;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x50) = 0x80000000;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x54) = 0;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x70) = 0x80000000;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x74) = 0;
  *(undefined4 *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x10) = 0x80000000;
  iVar3 = iVar3 * 0x48;
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x38) =
       2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x3c) =
       2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x18) =
       1.0 - 2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x1c) =
       2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x78) =
       1.0 - 2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x7c) =
       1.0 - 2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x58) =
       2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  *(float *)(*(int *)(iVar4 + 0x80 + DAT_006a5ee0) + 0x5c) =
       1.0 - 2.0 / (float)*(int *)(iVar3 + 0x24 + DAT_006a5e80);
  return;
}

