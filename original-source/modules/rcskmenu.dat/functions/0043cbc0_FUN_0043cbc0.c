/*
 * FUN_0043cbc0 at 0043cbc0
 * undefined1 __register FUN_0043cbc0(undefined4 * param_1, int param_2, int * param_3)
 * Address ranges: 0043cbc0-0043cbf0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0043cbc0(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  *param_3 = 0;
  while( true ) {
    if ((int)param_1[2] <= *param_3) {
      return 0;
    }
    iVar1 = FUN_0040f6b0(param_1,*param_3);
    if (param_2 == *(int *)(iVar1 + 4)) break;
    *param_3 = *param_3 + 1;
  }
  return 1;
}

