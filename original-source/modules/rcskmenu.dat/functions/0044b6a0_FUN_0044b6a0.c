/*
 * FUN_0044b6a0 at 0044b6a0
 * undefined __register FUN_0044b6a0(int param_1)
 * Address ranges: 0044b6a0-0044b71e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b6a0(int param_1)

{
  UINT_PTR UVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_18 = &LAB_0044b71f;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  KillTimer(*(HWND *)(param_1 + 0x28),1);
  if (((*(UINT *)(param_1 + 0x24) != 0) && (*(char *)(param_1 + 0x38) != '\0')) &&
     (*(short *)(param_1 + 0x32) != 0)) {
    UVar1 = SetTimer(*(HWND *)(param_1 + 0x28),1,*(UINT *)(param_1 + 0x24),(TIMERPROC)0x0);
    if (UVar1 == 0) {
      FUN_00405438((undefined4 *)PTR_PTR_0047c9b8,(int *)&local_8);
      piVar2 = FUN_0040ac64((int *)&DAT_0040ddb0,'\x01',local_8);
      FUN_00403604(piVar2);
    }
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0044b726;
  puStack_18 = (undefined1 *)0x44b71e;
  FUN_00403b50((int *)&local_8);
  return;
}

