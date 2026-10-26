/*
 * FUN_0041b398 at 0041b398
 * undefined FUN_0041b398(void)
 * Address ranges: 0041b398-0041b405
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b398(int *param_1,undefined *param_2)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar2;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined *puStack_c;
  uint *puStack_8;
  
  puStack_1c = &stack0xfffffffc;
  puStack_8 = (uint *)0x0;
  puStack_c = (undefined *)0x0;
  uVar2 = 1;
  puStack_20 = &LAB_0041b406;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  iVar1 = param_1[9];
  FUN_00408230(param_2,&puStack_c);
  FUN_0040b794(puStack_c,(int *)&puStack_8);
  FUN_00403ee0(puStack_8,(uint *)&DAT_0041b41c);
  if ((bool)uVar2) {
    *(undefined1 *)(param_1 + 9) = 0;
  }
  FUN_0041a1d4(param_1,param_2);
  *(char *)(param_1 + 9) = (char)iVar1;
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0041b40d;
  puStack_20 = (undefined1 *)0x41b405;
  FUN_00403b74((int *)&puStack_c,2);
  return;
}

