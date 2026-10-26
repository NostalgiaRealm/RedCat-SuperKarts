/*
 * FUN_004b4ab0 at 004b4ab0
 * undefined FUN_004b4ab0(void)
 * Address ranges: 004b4ab0-004b4bdf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b4ab0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_ESI;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  uVar4 = param_2;
  if ((param_4 != -1) && (iVar2 = FUN_004b9570(param_2,param_4,0), iVar2 != 0)) {
    return 0x3e9;
  }
  uVar7 = 1;
  puVar6 = local_8;
  puVar5 = local_4;
  piVar1 = *(int **)(param_1 * 0x44 + 0x28 + DAT_006ab798);
  iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,0,param_3,puVar5,puVar6,&param_2,&param_4,1);
  if (iVar2 != 0) {
    uVar3 = FUN_004b3910(iVar2);
    FUN_004afee0(s__s__d____error_locking_sound_buf_005009c8,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x4fb,param_1,uVar3);
  }
  if ((puVar5 != (undefined1 *)0x0) && (iVar2 = FUN_004bf930(puVar6,puVar5,1,uVar4), iVar2 != 1)) {
    return 0x3e9;
  }
  if ((unaff_ESI != 0) && (iVar2 = FUN_004bf930(uVar7,unaff_ESI,1,uVar4), iVar2 != 1)) {
    return 0x3e9;
  }
  piVar1 = *(int **)(param_1 * 0x44 + 0x28 + DAT_006ab798);
  iVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1,puVar6,puVar5,uVar7,unaff_ESI);
  if (iVar2 != 0) {
    uVar4 = FUN_004b3910(iVar2);
    FUN_004afee0(s__s__d____error_unlocking_sound_b_00500994,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x50e,param_1,uVar4);
  }
  return 0;
}

