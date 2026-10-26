/*
 * FUN_004acae0 at 004acae0
 * undefined FUN_004acae0(void)
 * Address ranges: 004acae0-004acb8c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004acae0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_006a62ec == 0) {
    FUN_004afee0(s__s__d____viewport_array_not_init_004fdf08,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x31);
  }
  iVar3 = DAT_006a62e8;
  if (*(int *)(DAT_006a62e8 + 0xc) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 DAT_006a62e8 + 0x14,*(undefined4 *)(DAT_006a62e8 + 4),DAT_006a62e8 + 0x2d);
  }
  iVar1 = *(int *)(iVar3 + 8);
  iVar2 = *(int *)(iVar3 + 4);
  if (iVar1 < iVar2) {
    iVar5 = *(int *)(iVar3 + 0x10);
    iVar4 = iVar1;
    do {
      if (*(char *)(iVar5 + iVar4) == '\0') goto LAB_004acb83;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  iVar4 = 0;
  if (0 < iVar1) {
    iVar5 = *(int *)(iVar3 + 0x10);
    do {
      if (*(char *)(iVar5 + iVar4) == '\0') {
LAB_004acb83:
        *(undefined1 *)(iVar5 + iVar4) = 1;
        *(int *)(iVar3 + 8) = iVar4;
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,iVar3 + 0x14,
               iVar2,iVar3 + 0x2d);
  return -1;
}

