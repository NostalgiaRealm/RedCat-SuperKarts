/*
 * FUN_004a1380 at 004a1380
 * undefined FUN_004a1380(void)
 * Address ranges: 004a1380-004a13fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004a1380(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,param_3,param_4,param_1 + 5,param_1[1],
                 (int)param_1 + 0x2d);
  }
  if ((param_2 < 0) || (param_1[1] <= param_2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,param_3,param_4,param_1 + 5,param_2,
                 param_1[1]);
  }
  if (*(char *)(param_1[4] + param_2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,param_3,param_4,param_1 + 5,param_2);
  }
  return *param_1 + param_2 * 4;
}

