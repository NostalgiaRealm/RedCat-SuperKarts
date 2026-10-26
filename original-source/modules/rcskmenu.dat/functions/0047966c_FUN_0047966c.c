/*
 * FUN_0047966c at 0047966c
 * undefined __register FUN_0047966c(void)
 * Address ranges: 0047966c-004796f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047966c(void)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  undefined4 *local_8;
  
  puStack_c = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_10 = &LAB_004796f4;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 != '\x02') {
    cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
    if (cVar1 != '\x01') goto LAB_004796cf;
  }
  FUN_00403e1c((int *)&local_8,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  FUN_0045a5dc(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80),local_8);
LAB_004796cf:
  FUN_0045b334(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  *in_FS_OFFSET = uStack_14;
  puStack_c = &LAB_004796fb;
  puStack_10 = (undefined1 *)0x4796f3;
  FUN_00403b50((int *)&local_8);
  return;
}

