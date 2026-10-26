/*
 * FUN_00431f00 at 00431f00
 * undefined __register FUN_00431f00(int param_1, uint * param_2)
 * Address ranges: 00431f00-00431f78
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431f00(int param_1,uint *param_2)

{
  LPCSTR lpString;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar1;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  uint *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  puStack_18 = &LAB_00431f79;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  uVar1 = *(char *)(param_1 + 0x94) == '\0';
  if ((bool)uVar1) {
    FUN_00403ba4((int *)(param_1 + 0x7c),param_2);
  }
  else {
    puStack_14 = &stack0xfffffffc;
    FUN_00431eb8(param_1,(int *)&local_8);
    FUN_00403ee0(local_8,param_2);
    if ((!(bool)uVar1) || (*(int *)(param_1 + 0x7c) != 0)) {
      lpString = FUN_00403f94((undefined *)param_2);
      SetWindowTextA(*(HWND *)(param_1 + 0x24),lpString);
      FUN_00403b50((int *)(param_1 + 0x7c));
    }
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00431f80;
  puStack_18 = (undefined1 *)0x431f78;
  FUN_00403b50((int *)&local_8);
  return;
}

