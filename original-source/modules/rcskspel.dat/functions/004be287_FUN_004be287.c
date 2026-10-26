/*
 * FUN_004be287 at 004be287
 * undefined FUN_004be287(void)
 * Address ranges: 004be287-004be2ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004be287(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *unaff_retaddr;
  
  FUN_004c0dec();
  uVar2 = DAT_006b6690;
  if (DAT_006b6690 != 0) {
    iVar1 = *(int *)(DAT_006b6690 + 4);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      *(int *)(DAT_006b6690 + 4) = iVar1 + -1;
    }
    puVar3 = (undefined4 *)(~-(uint)(*(int *)(uVar2 + 4) != 0) & uVar2);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
  }
  ExceptionList = unaff_retaddr;
  return;
}

