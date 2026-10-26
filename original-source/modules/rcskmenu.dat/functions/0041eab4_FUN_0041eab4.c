/*
 * FUN_0041eab4 at 0041eab4
 * undefined __register FUN_0041eab4(byte param_1, undefined4 param_2, undefined * param_3)
 * Address ranges: 0041eab4-0041eb72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041eab4(byte param_1,undefined4 param_2,undefined *param_3)

{
  LPCSTR lpProcName;
  FARPROC pFVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined *local_8;
  
  puStack_18 = (undefined1 *)0x41eaca;
  local_8 = param_3;
  FUN_00403f84((int)param_3);
  puStack_1c = &LAB_0041eb73;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  if ((&DAT_0047d704)[param_1] == '\0') {
    if (DAT_0047d700 == (HMODULE)0x0) {
      pFVar1 = (FARPROC)0x0;
    }
    else {
      puStack_18 = &stack0xfffffffc;
      if (((param_1 == 0) && (puStack_18 = &stack0xfffffffc, DAT_0047d70c == '\0')) &&
         (puStack_18 = &stack0xfffffffc,
         DAT_0047d6f4 = FUN_0041eab4(4,DAT_0047d6f4,"GetMonitorInfoA"), DAT_0047d70c == '\0')) {
        FUN_00403b50((int *)&local_8);
      }
      lpProcName = FUN_00403f94(local_8);
      pFVar1 = GetProcAddress(DAT_0047d700,lpProcName);
    }
    if ((pFVar1 != (FARPROC)0x0) && (param_1 != 0)) {
      DAT_0047d70c = '\x01';
    }
    (&DAT_0047d704)[param_1] = 1;
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0041eb7a;
  puStack_1c = (undefined1 *)0x41eb72;
  FUN_00403b50((int *)&local_8);
  return;
}

