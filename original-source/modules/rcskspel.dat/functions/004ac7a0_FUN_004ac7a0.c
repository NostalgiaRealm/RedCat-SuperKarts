/*
 * FUN_004ac7a0 at 004ac7a0
 * undefined FUN_004ac7a0(void)
 * Address ranges: 004ac7a0-004ac852
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ac7a0(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_006a62f0;
  iVar1 = DAT_006a62e8;
  uVar3 = 0;
  if ((DAT_006a62e0 != 0) && (DAT_006a625c != 0)) {
    uVar3 = param_1 | 2;
  }
  if (*(int *)(DAT_006a62e8 + 0xc) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_D3dlib_cpp_004fdc08
                 ,0xcf,DAT_006a62e8 + 0x14,*(undefined4 *)(DAT_006a62e8 + 4),DAT_006a62e8 + 0x2d);
  }
  if ((iVar2 < 0) || (*(int *)(iVar1 + 4) <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_D3dlib_cpp_004fdc08
                 ,0xcf,iVar1 + 0x14,iVar2,*(undefined4 *)(iVar1 + 4));
  }
  if (*(char *)(*(int *)(iVar1 + 0x10) + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_D3dlib_cpp_004fdc08
                 ,0xcf,iVar1 + 0x14,iVar2);
  }
  FUN_004ad080(uVar3);
  return 0;
}

