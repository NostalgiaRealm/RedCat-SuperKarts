/*
 * FUN_004be381 at 004be381
 * undefined FUN_004be381(void)
 * Address ranges: 004be381-004be401
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004be381(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  undefined4 *puVar3;
  int unaff_EBP;
  int iVar4;
  
  FUN_004c0dec();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004d36cc;
  iVar4 = extraout_ECX[3];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  while (iVar4 != 0) {
    iVar4 = iVar4 + -1;
    uVar1 = *(uint *)(extraout_ECX[2] + iVar4 * 4);
    if (uVar1 != 0) {
      iVar2 = *(int *)(uVar1 + 4);
      if ((iVar2 != 0) && (iVar2 != -1)) {
        *(int *)(uVar1 + 4) = iVar2 + -1;
      }
      puVar3 = (undefined4 *)(~-(uint)(*(int *)(uVar1 + 4) != 0) & uVar1);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
    }
  }
  FUN_004bff99(extraout_ECX[2]);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040b4f0(1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_004d36d4;
  return;
}

