/*
 * FUN_004795d4 at 004795d4
 * undefined __register FUN_004795d4(void)
 * Address ranges: 004795d4-0047964c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004795d4(void)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  undefined4 *local_8;
  
  puStack_c = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_10 = &LAB_0047964d;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 != '\x04') {
    cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
    if (cVar1 != '\x03') goto LAB_00479637;
  }
  FUN_00403e1c((int *)&local_8,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  FUN_0045a3c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80),local_8);
LAB_00479637:
  *in_FS_OFFSET = uStack_14;
  puStack_c = &LAB_00479654;
  puStack_10 = (undefined1 *)0x47964c;
  FUN_00403b50((int *)&local_8);
  return;
}

