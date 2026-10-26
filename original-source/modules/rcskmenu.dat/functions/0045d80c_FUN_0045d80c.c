/*
 * FUN_0045d80c at 0045d80c
 * undefined FUN_0045d80c(void)
 * Address ranges: 0045d80c-0045d89b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045d80c(int *param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_18 [4];
  undefined4 uStack_8;
  
  puVar4 = auStack_18;
  for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  uStack_8 = param_3;
  if (param_4 == (int *)0x0) {
    FUN_00403b34("Assertion failure");
  }
  uVar1 = FUN_00403024(param_4,(int)&PTR_FUN_00452e7c);
  if ((char)uVar1 == '\0') {
    FUN_00403b34("Assertion failure");
  }
  piVar2 = FUN_00453450((int)param_4,6);
  param_1[0x80] = (int)piVar2;
  param_1[0x81] = param_4[0x14];
  FUN_00446cf0(param_1,auStack_18,uStack_8);
  return;
}

