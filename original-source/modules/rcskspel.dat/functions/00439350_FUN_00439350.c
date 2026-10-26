/*
 * FUN_00439350 at 00439350
 * undefined FUN_00439350(void)
 * Address ranges: 00439350-004393a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00439350(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1[1];
  *param_1 = &PTR_FUN_004d268c;
  if (iVar1 == 0) {
    param_1[1] = 0;
    return;
  }
  iVar2 = *(int *)(iVar1 + 8);
  for (iVar3 = *(int *)(iVar1 + 4); iVar3 != iVar2; iVar3 = iVar3 + 0x44) {
    FUN_004389b0();
  }
  FUN_004bc150(*(undefined4 *)(iVar1 + 4));
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_004bc150(iVar1);
  param_1[1] = 0;
  return;
}

