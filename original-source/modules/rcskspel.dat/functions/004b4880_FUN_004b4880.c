/*
 * FUN_004b4880 at 004b4880
 * undefined FUN_004b4880(void)
 * Address ranges: 004b4880-004b4907
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b4880(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_ESI;
  
  iVar2 = param_1;
  if (DAT_006ab7b4 == 0) {
    return 0;
  }
  if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
    FUN_004afee0(s__s__d____sound_buffer_index_ille_005008b8,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x42d,param_1);
  }
  iVar3 = DAT_006ab798 + iVar2 * 0x44;
  if (*(int *)(iVar3 + 0x30) == 0) {
    return 0;
  }
  piVar1 = *(int **)(iVar3 + 0x28);
  iVar3 = (**(code **)(*piVar1 + 0x20))(piVar1,&param_1);
  if (iVar3 != 0) {
    uVar4 = FUN_004b3910(iVar3);
    FUN_004afee0(s__s__d____sound_buffer_index_ille_00500840,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x436,iVar2,uVar4);
  }
  return unaff_ESI;
}

