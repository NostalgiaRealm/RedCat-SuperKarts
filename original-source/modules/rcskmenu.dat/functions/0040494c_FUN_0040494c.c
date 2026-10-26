/*
 * FUN_0040494c at 0040494c
 * undefined __register FUN_0040494c(undefined4 param_1, undefined4 * param_2, undefined4 param_3)
 * Address ranges: 0040494c-004049a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040494c(VARIANTARG *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  VARIANT *pVVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  VARIANT local_14;
  
  pVVar2 = &local_14;
  for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)&pVVar2->n1 = *param_2;
    param_2 = param_2 + 1;
    pVVar2 = (VARIANT *)((int)&pVVar2->n1 + 4);
  }
  puStack_24 = (undefined1 *)0x40496f;
  FUN_00404c70(&local_14);
  puStack_28 = &LAB_004049a8;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_24 = &stack0xfffffffc;
  (*DAT_0047d3ec)(&local_14);
  FUN_004049d0(param_1,&local_14,param_3);
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_004049af;
  puStack_28 = (undefined1 *)0x4049a7;
  FUN_00404c68(&local_14);
  return;
}

