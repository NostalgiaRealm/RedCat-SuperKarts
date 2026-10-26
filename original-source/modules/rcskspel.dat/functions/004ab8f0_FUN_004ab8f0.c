/*
 * FUN_004ab8f0 at 004ab8f0
 * undefined FUN_004ab8f0(void)
 * Address ranges: 004ab8f0-004abb80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ab8f0(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_006a629c != 0) {
    if (DAT_006a629c == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a62bd,&DAT_006a62a4,
                   DAT_006a6294);
      FUN_004bc150(DAT_006a6290);
    }
    if (DAT_006a629c != 0) {
      FUN_004bc150(DAT_006a62a0);
      DAT_006a629c = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                 &DAT_006a62bd,&DAT_006a62a4,param_1);
  }
  DAT_006a6290 = operator_new(param_1 * 4);
  DAT_006a6294 = param_1;
  DAT_006a6298 = 0;
  DAT_006a62a0 = operator_new(param_1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_006a62bd,&DAT_006a62a4,DAT_006a6294)
  ;
  DAT_006a629c = 1;
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      iVar1 = iVar2 + 1;
      *(undefined1 *)((int)DAT_006a62a0 + iVar2) = 0;
      iVar2 = iVar1;
    } while (iVar1 < (int)param_1);
  }
  DAT_004fd9fc = FUN_004abc90();
  DAT_004fda00 = FUN_004abc90();
  iVar2 = DAT_004fd9fc;
  if (DAT_006a629c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x18,&DAT_006a62a4,DAT_006a6294,
                 &DAT_006a62bd);
  }
  if ((iVar2 < 0) || ((int)DAT_006a6294 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x18,&DAT_006a62a4,iVar2,DAT_006a6294);
  }
  if (*(char *)((int)DAT_006a62a0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x18,&DAT_006a62a4,iVar2);
  }
  iVar2 = DAT_004fd9fc;
  if (DAT_006a6234 != 1) {
    FUN_004afee0(s__s__d____device_was_not_initiali_004fc8ac,s___d3dev_h_004fc8d4,0xb8);
  }
  if (DAT_006a626c != iVar2) {
    DAT_006a626c = iVar2;
    if (DAT_006a629c == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s___d3dev_inl_004fc8a0,0x198,
                   &DAT_006a62a4,DAT_006a6294,&DAT_006a62bd);
    }
    if ((iVar2 < 0) || ((int)DAT_006a6294 <= iVar2)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___d3dev_inl_004fc8a0,0x198,
                   &DAT_006a62a4,iVar2,DAT_006a6294);
    }
    if (*(char *)((int)DAT_006a62a0 + iVar2) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___d3dev_inl_004fc8a0,0x198,
                   &DAT_006a62a4,iVar2);
    }
    iVar2 = (**(code **)(*DAT_006a621c + 100))
                      (DAT_006a621c,1,
                       *(undefined4 *)(*(int *)((int)DAT_006a6290 + iVar2 * 4) + 0x50));
    if (iVar2 != 0) {
      uVar3 = FUN_004aaa00(iVar2);
      FUN_004afee0(s__s__d_____MATERIAL__error_settin_004fda20,s___d3dev_inl_004fc8a0,0x199,uVar3);
    }
  }
  return;
}

