/*
 * FUN_00418ce4 at 00418ce4
 * undefined __register FUN_00418ce4(void)
 * Address ranges: 00418ce4-00418d7f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418ce4(void)

{
  DWORD DVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_118;
  undefined1 *puStack_114;
  undefined1 *puStack_110;
  undefined4 *local_108;
  CHAR local_104 [256];
  
  puStack_110 = &stack0xfffffffc;
  local_108 = (undefined4 *)0x0;
  puStack_114 = &LAB_00418d80;
  uStack_118 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_118;
  DVar1 = GetLastError();
  if (DVar1 != 0) {
    DVar1 = FormatMessageA(0x1000,(LPCVOID)0x0,DVar1,0x400,local_104,0x100,(va_list *)0x0);
    if (DVar1 != 0) {
      FUN_00403d80((int *)&local_108,local_104,0x100);
      piVar2 = FUN_0040ac64((int *)&DAT_0040ddb0,'\x01',local_108);
      FUN_00403604(piVar2);
      goto LAB_00418d67;
    }
  }
  FUN_00418c90();
LAB_00418d67:
  *in_FS_OFFSET = uStack_118;
  puStack_110 = &LAB_00418d87;
  puStack_114 = (undefined1 *)0x418d7f;
  FUN_00403b50((int *)&local_108);
  return;
}

