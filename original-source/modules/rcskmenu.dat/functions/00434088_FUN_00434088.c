/*
 * FUN_00434088 at 00434088
 * undefined __register FUN_00434088(int * param_1, int * param_2)
 * Address ranges: 00434088-004340a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434088(int *param_1,int *param_2)

{
  HIMAGELIST p_Var1;
  
  if (param_2 != (int *)0x0) {
    p_Var1 = (HIMAGELIST)FUN_004339b0(param_2);
    FUN_00433ef0(param_1,p_Var1);
  }
  return;
}

