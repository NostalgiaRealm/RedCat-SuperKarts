/*
 * FUN_00402fe0 at 00402fe0
 * int * __register FUN_00402fe0(int param_1, int * param_2)
 * Address ranges: 00402fe0-00403023
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00402fe0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  do {
    piVar1 = *(int **)(param_1 + -0x48);
    if (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
      piVar1 = piVar1 + 1;
      do {
        if ((((*param_2 == *piVar1) && (param_2[1] == piVar1[1])) && (param_2[2] == piVar1[2])) &&
           (param_2[3] == piVar1[3])) {
          return piVar1;
        }
        piVar1 = piVar1 + 7;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (*(int **)(param_1 + -0x24) == (int *)0x0) {
      return (int *)0x0;
    }
    param_1 = **(int **)(param_1 + -0x24);
  } while( true );
}

