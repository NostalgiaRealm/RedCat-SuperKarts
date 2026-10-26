/*
 * FUN_004a0d80 at 004a0d80
 * undefined FUN_004a0d80(void)
 * Address ranges: 004a0d80-004a10f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a0d80(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  undefined4 *puVar4;
  undefined4 unaff_EDI;
  undefined4 *puVar5;
  undefined4 auStack_40 [16];
  
  FUN_004a09d0();
  if (*(int *)(param_1 + 0x95) == -1) {
    iVar3 = *(int *)(param_1 + 4);
    if (DAT_006a5f84 == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,400,&DAT_006a5f8c,DAT_006a5f7c,
                   &DAT_006a5fa5);
    }
    if ((iVar3 < 0) || (DAT_006a5f7c <= iVar3)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,400,&DAT_006a5f8c,iVar3,DAT_006a5f7c);
    }
    if (*(char *)(DAT_006a5f88 + iVar3) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,400,&DAT_006a5f8c,iVar3);
    }
    iVar3 = *(int *)(*(int *)(iVar3 * 9 + 4 + DAT_006a5f78) + *(int *)(param_1 + 8) * 4);
    if (DAT_006a5f3c == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,400,&DAT_006a5f44,DAT_006a5f34,
                   &DAT_006a5f5d);
    }
    if ((iVar3 < 0) || (DAT_006a5f34 <= iVar3)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,400,&DAT_006a5f44,iVar3,DAT_006a5f34);
    }
    if (*(char *)(DAT_006a5f40 + iVar3) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,400,&DAT_006a5f44,iVar3);
    }
  }
  iVar3 = *(int *)(param_1 + 0x99);
  if (iVar3 == -1) {
    iVar3 = *(int *)(param_1 + 4);
    if (DAT_006a5f84 == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x197,&DAT_006a5f8c,DAT_006a5f7c,
                   &DAT_006a5fa5);
    }
    if ((iVar3 < 0) || (DAT_006a5f7c <= iVar3)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x197,&DAT_006a5f8c,iVar3,DAT_006a5f7c)
      ;
    }
    if (*(char *)(DAT_006a5f88 + iVar3) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x197,&DAT_006a5f8c,iVar3);
    }
    iVar3 = *(int *)(*(int *)(iVar3 * 9 + 4 + DAT_006a5f78) + *(int *)(param_1 + 8) * 4);
    if (DAT_006a5f3c == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x197,&DAT_006a5f44,DAT_006a5f34,
                   &DAT_006a5f5d);
    }
    if ((iVar3 < 0) || (DAT_006a5f34 <= iVar3)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x197,&DAT_006a5f44,iVar3,DAT_006a5f34)
      ;
    }
    if (*(char *)(DAT_006a5f40 + iVar3) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                   s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x197,&DAT_006a5f44,iVar3);
    }
    iVar3 = *(int *)(iVar3 * 0x10 + DAT_006a5f30);
  }
  puVar4 = (undefined4 *)(param_1 + 0x10);
  puVar5 = auStack_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (DAT_006a6234 != 1) {
    FUN_004afee0(s__s__d____device_was_not_initiali_004fc8ac,s___d3dev_h_004fc8d4,0xb8);
  }
  puVar4 = auStack_40;
  puVar5 = &DAT_006a61dc;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar2 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
  if (iVar2 != 0) {
    uVar1 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,s___d3dev_inl_004fc8a0,0x14,uVar1);
  }
  DAT_006a5c84 = DAT_006a5c84 + 1;
  if (*(int *)(unaff_ESI + 0xa5) == 0) {
    if (DAT_006a6288 != 0) {
      DAT_006a6288 = 0;
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
  }
  else if (DAT_006a6288 == 0) {
    DAT_006a6288 = 1;
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
  }
  FUN_004a7e10(iVar3,unaff_EDI);
  return;
}

