/*
 * FUN_004a3170 at 004a3170
 * undefined FUN_004a3170(void)
 * Address ranges: 004a3170-004a33ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004a3170(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (DAT_006a5e84 < 1) {
    return 0xffffffff;
  }
  iVar5 = 0;
  iVar3 = DAT_006a5e84;
  do {
    if ((iVar5 < 0) || (iVar3 <= iVar4)) {
      FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar4,
                   &DAT_006a5e94,iVar3,&DAT_006a5ead);
      iVar3 = DAT_006a5e84;
    }
    if (*(char *)(DAT_006a5e90 + iVar4) != '\0') {
      if (DAT_006a5e8c == 0) {
        FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x92,&DAT_006a5e94,iVar3,&DAT_006a5ead);
        iVar3 = DAT_006a5e84;
      }
      if ((iVar5 < 0) || (iVar3 <= iVar4)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x92,&DAT_006a5e94,iVar4,iVar3);
        iVar3 = DAT_006a5e84;
      }
      if (*(char *)(DAT_006a5e90 + iVar4) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x92,&DAT_006a5e94,iVar4);
        iVar3 = DAT_006a5e84;
      }
      if (*(int *)(iVar5 + 8 + DAT_006a5e80) != 0) {
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_text_cpp_004fca28,0x93,&DAT_006a5e94,iVar3,&DAT_006a5ead)
          ;
          iVar3 = DAT_006a5e84;
        }
        if ((iVar5 < 0) || (iVar3 <= iVar4)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_text_cpp_004fca28,0x93,&DAT_006a5e94,iVar4,iVar3);
        }
        if (*(char *)(DAT_006a5e90 + iVar4) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_text_cpp_004fca28,0x93,&DAT_006a5e94,iVar4);
        }
        piVar1 = *(int **)(iVar5 + 8 + DAT_006a5e80);
        iVar2 = (**(code **)(*piVar1 + 0x60))(piVar1);
        iVar3 = DAT_006a5e84;
        if (iVar2 != 0) {
          if (DAT_006a5e8c == 0) {
            FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                         s_D__work_libs_DX3D_text_cpp_004fca28,0x94,&DAT_006a5e94,DAT_006a5e84,
                         &DAT_006a5ead);
          }
          if ((iVar5 < 0) || (DAT_006a5e84 <= iVar4)) {
            FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                         s_D__work_libs_DX3D_text_cpp_004fca28,0x94,&DAT_006a5e94,iVar4,DAT_006a5e84
                        );
          }
          if (*(char *)(DAT_006a5e90 + iVar4) == '\0') {
            FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                         s_D__work_libs_DX3D_text_cpp_004fca28,0x94,&DAT_006a5e94,iVar4);
          }
          piVar1 = *(int **)(iVar5 + 8 + DAT_006a5e80);
          (**(code **)(*piVar1 + 0x6c))(piVar1);
          FUN_004a46e0(iVar4);
          iVar3 = DAT_006a5e84;
        }
      }
    }
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x48;
  } while (iVar4 < iVar3);
  return 0xffffffff;
}

