/*
 * FUN_00430248 at 00430248
 * undefined __register FUN_00430248(int param_1, int * param_2)
 * Address ranges: 00430248-0043027f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430248(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  FUN_0040f504(*(int **)(param_1 + 0x44),(int)param_2);
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00428110);
  if ((char)uVar1 != '\0') {
    FUN_0040f504(*(int **)(param_1 + 0x40),(int)param_2);
    FUN_00432c30(DAT_0047d770);
  }
  return;
}

