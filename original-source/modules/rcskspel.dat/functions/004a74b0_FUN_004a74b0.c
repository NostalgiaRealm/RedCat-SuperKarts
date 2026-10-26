/*
 * FUN_004a74b0 at 004a74b0
 * undefined FUN_004a74b0(void)
 * Address ranges: 004a74b0-004a75da
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a74b0(char *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < DAT_006a5ee4) {
    iVar4 = 0;
    iVar3 = DAT_006a5ee4;
    do {
      if ((iVar4 < 0) || (iVar3 <= iVar5)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar5,
                     &DAT_006a5ef4,iVar3,&DAT_006a5f0d);
        iVar3 = DAT_006a5ee4;
      }
      if (*(char *)(DAT_006a5ef0 + iVar5) != '\0') {
        if (DAT_006a5eec == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x28,&DAT_006a5ef4,iVar3,&DAT_006a5f0d)
          ;
          iVar3 = DAT_006a5ee4;
        }
        if ((iVar4 < 0) || (iVar3 <= iVar5)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x28,&DAT_006a5ef4,iVar5,iVar3);
        }
        if (*(char *)(DAT_006a5ef0 + iVar5) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x28,&DAT_006a5ef4,iVar5);
        }
        puVar1 = (undefined4 *)(iVar4 + 0xa8 + DAT_006a5ee0);
        if (*(int *)(iVar4 + 0xac + DAT_006a5ee0) == 0) {
          FUN_004afee0(s__s__d____string_is_not_initialis_004fb8fc,s___str_h_004fcac4,0x3c);
        }
        iVar2 = __strcmpi((char *)*puVar1,param_1);
        iVar3 = DAT_006a5ee4;
        if (iVar2 == 0) {
          return iVar5;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xbc;
    } while (iVar5 < iVar3);
  }
  return -1;
}

