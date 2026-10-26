/*
 * FUN_004a6200 at 004a6200
 * undefined FUN_004a6200(void)
 * Address ranges: 004a6200-004a6336
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004a6200(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    iVar2 = 0;
    do {
      if ((iVar2 < 0) || (*(int *)(param_1 + 0xa8) <= iVar3)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar3,
                     param_1 + 0xb8,*(undefined4 *)(param_1 + 0xa8),param_1 + 0xd1);
      }
      if (*(char *)(*(int *)(param_1 + 0xb4) + iVar3) != '\0') {
        if (*(int *)(param_1 + 0xb0) == 0) {
          FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                       param_1 + 0xb8,*(undefined4 *)(param_1 + 0xa8),param_1 + 0xd1);
        }
        if ((iVar2 < 0) || (*(int *)(param_1 + 0xa8) <= iVar3)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                       param_1 + 0xb8,iVar3,*(undefined4 *)(param_1 + 0xa8));
        }
        if (*(char *)(*(int *)(param_1 + 0xb4) + iVar3) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                       param_1 + 0xb8,iVar3);
        }
        iVar1 = __strcmpi(param_2,(char *)(*(int *)(param_1 + 0xa4) + iVar2));
        if (iVar1 == 0) {
          return iVar3;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x19;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  FUN_004afee0(s_find_anim_name_index___anim_<_s>_004fcfe4,param_2);
  return 0;
}

