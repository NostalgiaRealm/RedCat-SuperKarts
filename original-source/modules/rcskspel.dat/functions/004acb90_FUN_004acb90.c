/*
 * FUN_004acb90 at 004acb90
 * undefined FUN_004acb90(void)
 * Address ranges: 004acb90-004acc89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004acb90(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d18eb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_006a62ec == 0) {
    ExceptionList = &pvStack_c;
    FUN_004afee0(s__s__d____viewport_array_not_init_004fdf08,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x3c,param_1);
  }
  iVar2 = FUN_004acae0();
  pvVar3 = operator_new(0x40);
  uStack_4 = 0;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004acf40();
  }
  piVar1 = DAT_006a62e8;
  uStack_4 = 0xffffffff;
  if (DAT_006a62e8[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x40,DAT_006a62e8 + 5,DAT_006a62e8[1],
                 (int)DAT_006a62e8 + 0x2d);
  }
  if ((iVar2 < 0) || (piVar1[1] <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x40,piVar1 + 5,iVar2,piVar1[1]);
  }
  if (*(char *)(piVar1[4] + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x40,piVar1 + 5,iVar2);
  }
  *(undefined4 *)(*piVar1 + iVar2 * 4) = uVar4;
  ExceptionList = pvStack_c;
  return iVar2;
}

