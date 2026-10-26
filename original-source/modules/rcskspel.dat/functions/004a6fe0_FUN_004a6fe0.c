/*
 * FUN_004a6fe0 at 004a6fe0
 * undefined FUN_004a6fe0(void)
 * Address ranges: 004a6fe0-004a706b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004a6fe0(int *param_1,int param_2)

{
  if (param_1[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 5,param_1[1],(int)param_1 + 0x2d);
  }
  if ((param_2 < 0) || (param_1[1] <= param_2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 5,param_2,param_1[1]);
  }
  if (*(char *)(param_1[4] + param_2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 5,param_2);
  }
  return param_2 * 9 + *param_1;
}

