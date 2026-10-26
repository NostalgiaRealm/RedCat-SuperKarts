/*
 * FUN_00426678 at 00426678
 * undefined __register FUN_00426678(int param_1, int * param_2, char param_3)
 * Address ranges: 00426678-004266be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426678(int param_1,int *param_2,char param_3)

{
  undefined4 uVar1;
  
  FUN_00414aa4(param_1,(int)param_2,param_3);
  if (param_3 == '\x01') {
    if (param_2 == *(int **)(param_1 + 0x2c)) {
      FUN_00426638(param_1,0);
    }
    else {
      uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00425f90);
      if ((char)uVar1 != '\0') {
        FUN_004266e0(param_1,(int)param_2);
      }
    }
  }
  return;
}

