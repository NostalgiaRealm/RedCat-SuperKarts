/*
 * FUN_00446100 at 00446100
 * undefined FUN_00446100(void)
 * Address ranges: 00446100-0044616c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00446100(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1[1];
  *param_1 = &PTR_FUN_004d2700;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    for (iVar3 = *(int *)(iVar1 + 4); iVar3 != iVar2; iVar3 = iVar3 + 0x2c) {
      FUN_0040b4b0();
      FUN_0040b4b0();
    }
    FUN_004bc150(*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
    param_1[1] = 0;
    return;
  }
  param_1[1] = 0;
  return;
}

