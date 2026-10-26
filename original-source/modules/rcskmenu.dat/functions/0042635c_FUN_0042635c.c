/*
 * FUN_0042635c at 0042635c
 * undefined __register FUN_0042635c(int * param_1, int * param_2, uint param_3)
 * Address ranges: 0042635c-0042638c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042635c(int *param_1,int *param_2,uint param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  FUN_00414be4(param_1,param_2,param_3);
  piVar1 = (int *)param_2[0xb];
  uVar2 = FUN_00403024(piVar1,(int)&PTR_FUN_004260b4);
  if ((char)uVar2 != '\0') {
    FUN_00426404((int)param_1,(int)piVar1);
  }
  return;
}

