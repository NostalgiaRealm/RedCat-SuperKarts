/*
 * FUN_0040b368 at 0040b368
 * undefined __register FUN_0040b368(void)
 * Address ranges: 0040b368-0040b428
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040b368(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  puStack_14 = &LAB_0040b429;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  FUN_00405438((undefined4 *)PTR_PTR_0047c6b4,(int *)&local_8);
  DAT_0047d5fc = FUN_0040ac64((int *)&DAT_0040720c,'\x01',local_8);
  FUN_00405438((undefined4 *)PTR_PTR_0047c838,(int *)&local_c);
  DAT_0047d600 = FUN_0040ac64((int *)&DAT_00407694,'\x01',local_c);
  *(undefined1 **)PTR_DAT_0047c60c = &LAB_0040aee4;
  *(undefined1 **)PTR_DAT_0047c730 = &LAB_0040b358;
  *(undefined **)PTR_DAT_0047c698 = &DAT_004070f4;
  *(undefined1 **)PTR_DAT_0047c70c = &LAB_0040b0ac;
  *(code **)PTR_DAT_0047c738 = FUN_0040b28c;
  *(code **)PTR_DAT_0047c864 = FUN_0040afe4;
  *(undefined1 **)PTR_DAT_0047c5f8 = &LAB_0040b000;
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0040b430;
  puStack_14 = (undefined1 *)0x40b428;
  FUN_00403b74((int *)&local_c,2);
  return;
}

