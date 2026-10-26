/*
 * FUN_00449310 at 00449310
 * undefined __register FUN_00449310(void)
 * Address ranges: 00449310-004493a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00449310(void)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int *piVar3;
  int in_stack_00000004;
  
  piVar3 = (int *)(in_stack_00000004 + -4);
  iVar1 = *(int *)(*piVar3 + 0x18);
  if (*(char *)(*(int *)(*(int *)(*piVar3 + 0x60) + 0x14) + 0x10) == '\x01') {
    iVar2 = FUN_004472ac(*(int *)(*piVar3 + 0x60),'\x01');
    if (*(int *)(*piVar3 + 0x54) <= iVar2 + iVar1) {
      *(int *)(*piVar3 + 0x54) = iVar2 + iVar1;
    }
    iVar2 = FUN_004491e4(*piVar3,*(int *)(*piVar3 + 0x60),extraout_ECX);
    if (iVar2 - iVar1 <= *(int *)(*piVar3 + 0x54)) {
      *(int *)(*piVar3 + 0x54) = iVar2 - iVar1;
    }
  }
  else {
    iVar2 = FUN_004472ac(*(int *)(*piVar3 + 0x60),'\x02');
    if (*(int *)(*piVar3 + 0x50) <= iVar2 + iVar1) {
      *(int *)(*piVar3 + 0x50) = iVar2 + iVar1;
    }
    iVar2 = FUN_004491e4(*piVar3,*(int *)(*piVar3 + 0x60),extraout_ECX_00);
    if (iVar2 - iVar1 <= *(int *)(*piVar3 + 0x50)) {
      *(int *)(*piVar3 + 0x50) = iVar2 - iVar1;
    }
  }
  return;
}

