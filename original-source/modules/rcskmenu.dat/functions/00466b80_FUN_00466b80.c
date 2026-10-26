/*
 * FUN_00466b80 at 00466b80
 * undefined FUN_00466b80(void)
 * Address ranges: 00466b80-00466bb1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466b80(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  byte bVar3;
  undefined4 auStack_1c [4];
  
  bVar3 = 0;
  FUN_004661dc(param_1,(int)auStack_1c);
  puVar2 = auStack_1c;
  for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
    param_2 = param_2 + (uint)bVar3 * -2 + 1;
  }
  FUN_00441acc();
  return;
}

