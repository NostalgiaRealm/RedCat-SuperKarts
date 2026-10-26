/*
 * FUN_00460700 at 00460700
 * undefined FUN_00460700(void)
 * Address ranges: 00460700-00460774
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460700(int *param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 extraout_ECX;
  
  bVar2 = FUN_0046063c((int)param_1);
  if ((!bVar2) && (param_2 != (int *)param_1[9])) {
    if ((*(short *)((int)param_1 + 0x202) != 0) && (param_1[9] != 0)) {
      iVar1 = param_1[9];
      *(int *)(iVar1 + 0x28) = param_1[0x80];
      *(int *)(iVar1 + 0x2c) = param_1[0x81];
      param_1[0x80] = 0;
      param_1[0x81] = 0;
    }
    if (param_2 != (int *)0x0) {
      param_1[0x80] = param_2[10];
      param_1[0x81] = param_2[0xb];
      param_2[0xb] = (int)param_1;
      param_2[10] = (int)FUN_004606c4;
    }
  }
  FUN_0043f518(param_1,param_2,extraout_ECX);
  return;
}

