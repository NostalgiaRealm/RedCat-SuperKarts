/*
 * FUN_004abc90 at 004abc90
 * undefined FUN_004abc90(void)
 * Address ranges: 004abc90-004abf07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004abc90(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d18ab;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_004abbf0();
  pvVar3 = operator_new(0x68);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004abf10();
  }
  local_4 = 0xffffffff;
  if (DAT_006a629c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x6e,&DAT_006a62a4,DAT_006a6294,
                 &DAT_006a62bd);
  }
  if ((iVar2 < 0) || (DAT_006a6294 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x6e,&DAT_006a62a4,iVar2,DAT_006a6294);
  }
  if (*(char *)(DAT_006a62a0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x6e,&DAT_006a62a4,iVar2);
  }
  *(undefined4 *)(DAT_006a6290 + iVar2 * 4) = uVar4;
  if (DAT_006a629c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x6f,&DAT_006a62a4,DAT_006a6294,
                 &DAT_006a62bd);
  }
  if ((iVar2 < 0) || (DAT_006a6294 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x6f,&DAT_006a62a4,iVar2,DAT_006a6294);
  }
  if (*(char *)(DAT_006a62a0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x6f,&DAT_006a62a4,iVar2);
  }
  iVar1 = *(int *)(DAT_006a6290 + iVar2 * 4);
  *(undefined4 *)(iVar1 + 0x14) = DAT_006a5d90;
  *(undefined4 *)(iVar1 + 0x18) = DAT_006a5d94;
  *(undefined4 *)(iVar1 + 0x1c) = DAT_006a5d98;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  if (*(int *)(iVar1 + 0x5c) == 1) {
    *(undefined4 *)(iVar1 + 0x58) = 0;
    (**(code **)(**(int **)(iVar1 + 0x54) + 0xc))(*(int **)(iVar1 + 0x54),iVar1);
  }
  if (DAT_006a629c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x70,&DAT_006a62a4,DAT_006a6294,
                 &DAT_006a62bd);
  }
  if ((iVar2 < 0) || (DAT_006a6294 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x70,&DAT_006a62a4,iVar2,DAT_006a6294);
  }
  if (*(char *)(DAT_006a62a0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x70,&DAT_006a62a4,iVar2);
  }
  iVar1 = *(int *)(DAT_006a6290 + iVar2 * 4);
  *(undefined4 *)(iVar1 + 4) = DAT_006a5d90;
  *(undefined4 *)(iVar1 + 8) = DAT_006a5d94;
  *(undefined4 *)(iVar1 + 0xc) = DAT_006a5d98;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  if (*(int *)(iVar1 + 0x5c) == 1) {
    *(undefined4 *)(iVar1 + 0x58) = 0;
    (**(code **)(**(int **)(iVar1 + 0x54) + 0xc))(*(int **)(iVar1 + 0x54),iVar1);
  }
  piVar5 = (int *)FUN_004a1380(iVar2,s_D__work_libs_DX3D_Material_cpp_004fda58,0x71);
  iVar1 = *piVar5;
  if (*(int *)(iVar1 + 0x58) != 0) {
    *(undefined4 *)(iVar1 + 0x58) = 0;
    (**(code **)(**(int **)(iVar1 + 0x54) + 0xc))(*(int **)(iVar1 + 0x54),iVar1);
  }
  ExceptionList = pvStack_c;
  return iVar2;
}

