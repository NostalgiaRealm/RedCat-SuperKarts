/*
 * FUN_004af0d0 at 004af0d0
 * undefined FUN_004af0d0(void)
 * Address ranges: 004af0d0-004af471
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004af0d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_004afce0(s_D3DDevice_Name___<_s>_004fe800,param_3);
  FUN_004afce0(s_D3DDevice_Desc___<_s>_004fe7e8,param_2);
  FUN_004afce0(s_D3DDevice_GUID____d_004fe7d0,*param_1,param_1[1],param_1[2],param_1[3]);
  if (param_6[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,param_6 + 5
                 ,param_6[1],(int)param_6 + 0x2d);
  }
  iVar3 = param_6[2];
  iVar1 = param_6[1];
  if (iVar3 < iVar1) {
    iVar2 = param_6[4];
    iVar4 = iVar3;
    do {
      if (*(char *)(iVar2 + iVar4) == '\0') goto LAB_004af1a2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  iVar4 = 0;
  if (0 < iVar3) {
    iVar2 = param_6[4];
    do {
      if (*(char *)(iVar2 + iVar4) == '\0') {
LAB_004af1a2:
        *(undefined1 *)(iVar2 + iVar4) = 1;
        param_6[2] = iVar4;
        if (iVar4 == -1) {
          return 0;
        }
        iVar3 = *(int *)((int)param_6 + 0x46);
        if (iVar3 != 0) {
          if (param_6[3] == 0) {
            FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                         param_6 + 5,param_6[1],(int)param_6 + 0x2d);
          }
          if ((iVar4 < 0) || (param_6[1] <= iVar4)) {
            FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                         param_6 + 5,iVar4,param_6[1]);
          }
          if (*(char *)(param_6[4] + iVar4) == '\0') {
            FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                         param_6 + 5,iVar4);
          }
          *(int *)(*param_6 + 0x1d0 + iVar4 * 0x1d8) = iVar3;
          iVar3 = *(int *)((int)param_6 + 0x46);
          if (param_6[3] == 0) {
            FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                         param_6 + 5,param_6[1],(int)param_6 + 0x2d);
          }
          if ((iVar3 < 0) || (param_6[1] <= iVar3)) {
            FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                         param_6 + 5,iVar3,param_6[1]);
          }
          if (*(char *)(param_6[4] + iVar3) == '\0') {
            FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                         param_6 + 5,iVar3);
          }
          *(int *)(*param_6 + 0x1cc + iVar3 * 0x1d8) = iVar4;
        }
        if (param_6[3] == 0) {
          FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                       param_6 + 5,param_6[1],(int)param_6 + 0x2d);
        }
        if ((iVar4 < 0) || (param_6[1] <= iVar4)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                       param_6 + 5,iVar4,param_6[1]);
        }
        if (*(char *)(param_6[4] + iVar4) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                       param_6 + 5,iVar4);
        }
        FUN_004ad120(param_3);
        if (param_6[3] == 0) {
          FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                       param_6 + 5,param_6[1],(int)param_6 + 0x2d);
        }
        if ((iVar4 < 0) || (param_6[1] <= iVar4)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                       param_6 + 5,iVar4,param_6[1]);
        }
        if (*(char *)(param_6[4] + iVar4) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                       param_6 + 5,iVar4);
        }
        FUN_004ad120(param_2);
        iVar3 = FUN_004af820(iVar4);
        *(undefined4 *)(iVar3 + 0x19c) = *param_1;
        *(undefined4 *)(iVar3 + 0x1a0) = param_1[1];
        *(undefined4 *)(iVar3 + 0x1a4) = param_1[2];
        *(undefined4 *)(iVar3 + 0x1a8) = param_1[3];
        FUN_004af820(iVar4);
        FUN_004ae7f0(param_4,param_5);
        FUN_004af820(iVar4);
        FUN_004aedf0();
        if (*(int *)((int)param_6 + 0x4a) == 0) {
          *(int *)((int)param_6 + 0x4a) = iVar4;
        }
        *(int *)((int)param_6 + 0x46) = iVar4;
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,param_6 + 5,
               iVar1,(int)param_6 + 0x2d);
  return 0;
}

