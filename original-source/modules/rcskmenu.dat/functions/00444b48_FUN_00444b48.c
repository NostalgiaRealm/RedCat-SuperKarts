/*
 * FUN_00444b48 at 00444b48
 * undefined __register FUN_00444b48(int * param_1, int param_2)
 * Address ranges: 00444b48-00444b7c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444b48(int *param_1,int param_2)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar1;
  
  FUN_00440f18(param_1,param_2);
  uVar1 = extraout_var;
  if ((PTR_DAT_0047c9d8[9] != '\0') && (*(int *)(param_2 + 4) == 0)) {
    FUN_00442cd4((int)param_1);
    uVar1 = extraout_var_00;
  }
  FUN_004426ec((int)param_1,CONCAT22(uVar1,0xb03d));
  return;
}

