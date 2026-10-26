/*
 * FUN_00402ae4 at 00402ae4
 * int * __register FUN_00402ae4(int * param_1, int * param_2, uint param_3)
 * Address ranges: 00402ae4-00402b52
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00402ae4(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_3 >> 2;
  do {
    if (uVar1 == 0) {
LAB_00402b14:
      uVar1 = param_3 & 3;
      if (((uVar1 != 0) && ((char)*param_1 == (char)*param_2)) &&
         ((uVar1 == 1 ||
          ((*(char *)((int)param_1 + 1) == *(char *)((int)param_2 + 1) &&
           ((uVar1 == 2 || (*(char *)((int)param_1 + 2) == *(char *)((int)param_2 + 2))))))))) {
        return (int *)0x0;
      }
      return param_1;
    }
    if (*param_1 != *param_2) {
      return param_1;
    }
    if (uVar1 == 1) {
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      goto LAB_00402b14;
    }
    if (param_1[1] != param_2[1]) {
      return param_1;
    }
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    uVar1 = uVar1 - 2;
  } while( true );
}

