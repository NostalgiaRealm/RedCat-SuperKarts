/*
 * FUN_004afb10 at 004afb10
 * undefined FUN_004afb10(void)
 * Address ranges: 004afb10-004afc74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004afb10(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004afce0(s_exit_lights_004fe898);
  iVar3 = 0;
  iVar2 = DAT_006a63f4;
  if (0 < DAT_006a63f4) {
    do {
      if ((iVar3 < 0) || (iVar2 <= iVar3)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar3,
                     &DAT_006a6404,iVar2,&DAT_006a641d);
        iVar2 = DAT_006a63f4;
      }
      if (*(char *)(DAT_006a6400 + iVar3) != '\0') {
        if (DAT_006a63fc == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Light_cpp_004fe87c,0x1e,&DAT_006a6404,iVar2,&DAT_006a641d
                      );
          iVar2 = DAT_006a63f4;
        }
        if ((iVar3 < 0) || (iVar2 <= iVar3)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Light_cpp_004fe87c,0x1e,&DAT_006a6404,iVar3,iVar2);
          iVar2 = DAT_006a63f4;
        }
        if (*(char *)(DAT_006a6400 + iVar3) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Light_cpp_004fe87c,0x1e,&DAT_006a6404,iVar3);
          iVar2 = DAT_006a63f4;
        }
        iVar1 = *(int *)(DAT_006a63f0 + iVar3 * 4);
        if (iVar1 != 0) {
          FUN_004afc80();
          FUN_004bc150(iVar1);
          iVar2 = DAT_006a63f4;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if (DAT_006a63fc == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a641d,&DAT_006a6404,iVar2);
    FUN_004bc150(DAT_006a63f0);
  }
  if (DAT_006a63fc != 0) {
    FUN_004bc150(DAT_006a6400);
    DAT_006a63fc = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  return;
}

