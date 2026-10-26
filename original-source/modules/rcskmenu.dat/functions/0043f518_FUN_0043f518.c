/*
 * FUN_0043f518 at 0043f518
 * undefined __register FUN_0043f518(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 0043f518-0043f562
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f518(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  if (param_2 != (int *)param_1[9]) {
    if (param_1 == param_2) {
      piVar1 = FUN_0040ad20((int *)&DAT_0040de0c,'\x01',(undefined4 *)PTR_PTR_0047c8ac);
      FUN_00403604(piVar1);
      param_3 = extraout_ECX;
    }
    if ((int *)param_1[9] != (int *)0x0) {
      FUN_004425d4((int *)param_1[9],param_1);
      param_3 = extraout_ECX_00;
    }
    if (param_2 != (int *)0x0) {
      FUN_00442500(param_2,param_1,param_3);
      FUN_0043ed90((int)param_1);
    }
  }
  return;
}

