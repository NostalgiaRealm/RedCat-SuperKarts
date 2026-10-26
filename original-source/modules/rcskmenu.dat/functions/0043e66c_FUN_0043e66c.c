/*
 * FUN_0043e66c at 0043e66c
 * undefined FUN_0043e66c(void)
 * Address ranges: 0043e66c-0043e6d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e66c(int param_1)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  uint *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (uint *)0x0;
  puStack_14 = &LAB_0043e6d3;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  cVar2 = FUN_00426804(param_1);
  if (cVar2 != '\0') {
    FUN_0043f64c(*(int *)(param_1 + 0x18),(int *)&puStack_8);
    puVar1 = puStack_8;
    iVar3 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    FUN_00403ee0(puVar1,*(uint **)(iVar3 + 0x54));
  }
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0043e6da;
  puStack_14 = (undefined1 *)0x43e6d2;
  FUN_00403b50((int *)&puStack_8);
  return;
}

