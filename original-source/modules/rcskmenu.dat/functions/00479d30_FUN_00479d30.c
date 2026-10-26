/*
 * FUN_00479d30 at 00479d30
 * undefined FUN_00479d30(void)
 * Address ranges: 00479d30-00479d97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00479d30(undefined4 *param_1,int *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined *puStack_c;
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_c = (undefined *)0x0;
  puStack_1c = &LAB_00479d98;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_004028e4(0,(int *)&puStack_c);
  FUN_004081c4(puStack_c,&iStack_8);
  FUN_00403dd8(&iStack_8,(undefined4 *)&DAT_00479db0);
  FUN_0044d690(param_1,"(IMAGEBASE)",iStack_8,param_2);
  *in_FS_OFFSET = param_2;
  puStack_1c = &LAB_00479d9f;
  uStack_20 = 0x479d97;
  FUN_00403b74((int *)&puStack_c,2);
  return;
}

