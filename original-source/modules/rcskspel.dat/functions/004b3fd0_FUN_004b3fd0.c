/*
 * FUN_004b3fd0 at 004b3fd0
 * undefined FUN_004b3fd0(void)
 * Address ranges: 004b3fd0-004b40d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b3fd0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  byte unaff_SI;
  int iVar5;
  
  iVar4 = param_1;
  if (DAT_006ab7b4 == 0) {
    return 0;
  }
  if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
    FUN_004afee0(s__s__d____illegal_sound_buffer_in_00500544,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x1e2,param_1,DAT_006ab78c);
  }
  iVar5 = iVar4 * 0x44;
  if (*(int *)(iVar5 + 0x30 + DAT_006ab798) == 0) {
    return 0;
  }
  piVar1 = *(int **)(iVar5 + 0x28 + DAT_006ab798);
  iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,&param_1);
  if (iVar2 != 0) {
    uVar3 = FUN_004b3910(iVar2);
    FUN_004afee0(s__s__d____getting_sound_status_fa_00500514,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x1ea,iVar4,uVar3);
  }
  if ((unaff_SI & 1) != 1) {
    return 0;
  }
  piVar1 = *(int **)(iVar5 + 0x28 + DAT_006ab798);
  iVar4 = (**(code **)(*piVar1 + 0x48))(piVar1);
  if (iVar4 != 0) {
    uVar3 = FUN_004b3910(iVar4);
    FUN_004afee0(s__s__d____error_releasing_sound_b_00500578,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x1f2,uVar3);
  }
  piVar1 = *(int **)(iVar5 + 0x28 + DAT_006ab798);
  iVar4 = (**(code **)(*piVar1 + 0x34))(piVar1,0);
  if (iVar4 != 0) {
    uVar3 = FUN_004b3910(iVar4);
    FUN_004afee0(s__s__d____error_releasing_sound_b_00500578,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x1f5,uVar3);
  }
  return 1;
}

