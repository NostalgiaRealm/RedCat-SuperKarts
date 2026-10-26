/*
 * FUN_004a6470 at 004a6470
 * undefined FUN_004a6470(void)
 * Address ranges: 004a6470-004a65c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a6470(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s__s__d____004fd014,s_D__work_libs_DX3D_Animsys_cpp_004fce58,0x154);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    iVar2 = 0;
    do {
      FUN_004afce0(s__s__d____004fd014,s_D__work_libs_DX3D_Animsys_cpp_004fce58,0x159);
      if ((iVar2 < 0) || (DAT_006a5f7c <= iVar1)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar1,
                     &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
      }
      if (*(char *)(DAT_006a5f88 + iVar1) != '\0') {
        FUN_004afce0(s__s__d____004fd014,s_D__work_libs_DX3D_Animsys_cpp_004fce58,0x15c);
        if (DAT_006a5f84 == 0) {
          FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                       &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
        }
        if ((iVar2 < 0) || (DAT_006a5f7c <= iVar1)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                       &DAT_006a5f8c,iVar1,DAT_006a5f7c);
        }
        if (*(char *)(DAT_006a5f88 + iVar1) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                       &DAT_006a5f8c,iVar1);
        }
        FUN_004bff99(*(undefined4 *)(iVar2 + 4 + DAT_006a5f78));
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 9;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  FUN_004afce0(s__s__d____004fd014,s_D__work_libs_DX3D_Animsys_cpp_004fce58,0x160);
  return;
}

