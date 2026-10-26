/*
 * FUN_004b3f30 at 004b3f30
 * undefined FUN_004b3f30(void)
 * Address ranges: 004b3f30-004b3fc2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004b3f30(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte unaff_SI;
  
  iVar2 = param_1;
  if (DAT_006ab7b4 == 0) {
    return false;
  }
  if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
    FUN_004afee0(s__s__d____illegal_sound_buffer_in_00500544,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x16f,param_1,DAT_006ab78c);
  }
  iVar3 = DAT_006ab798 + iVar2 * 0x44;
  if (*(int *)(iVar3 + 0x30) == 0) {
    return false;
  }
  piVar1 = *(int **)(iVar3 + 0x28);
  iVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,&param_1);
  if (iVar3 != 0) {
    uVar4 = FUN_004b3910(iVar3);
    FUN_004afee0(s__s__d____getting_sound_status_fa_00500514,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x177,iVar2,uVar4);
  }
  return (unaff_SI & 1) == 1;
}

