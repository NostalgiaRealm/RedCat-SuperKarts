/*
 * FUN_0045a958 at 0045a958
 * undefined __register FUN_0045a958(int param_1)
 * Address ranges: 0045a958-0045a9bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045a958(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined *local_c;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined *)0x0;
  puStack_18 = &LAB_0045a9be;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_c);
  FUN_004081c4(local_c,(int *)&local_8);
  FUN_00403dd8((int *)&local_8,(undefined4 *)"race.ini");
  FUN_0045a5dc(param_1,local_8);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0045a9c5;
  puStack_18 = (undefined1 *)0x45a9bd;
  FUN_00403b74((int *)&local_c,2);
  return;
}

