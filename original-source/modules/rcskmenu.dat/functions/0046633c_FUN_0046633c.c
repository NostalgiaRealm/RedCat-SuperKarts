/*
 * FUN_0046633c at 0046633c
 * undefined __register FUN_0046633c(int param_1, char param_2)
 * Address ranges: 0046633c-004663b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046633c(int param_1,char param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined4 *local_c;
  undefined1 local_5;
  
  puStack_18 = &stack0xfffffffc;
  local_c = (undefined4 *)0x0;
  puStack_1c = &LAB_004663b9;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  local_5 = param_2 != *(char *)(param_1 + 0x200);
  if ((bool)local_5) {
    if ((param_2 == '\0') &&
       ((*(char *)(param_1 + 0x20e) == '\x02' || (*(char *)(param_1 + 0x20e) == '\x03')))) {
      FUN_00405438((undefined4 *)PTR_PTR_0047c900,(int *)&local_c);
      FUN_0046593c(local_c);
    }
    *(char *)(param_1 + 0x200) = param_2;
    if (param_2 == '\0') {
      *(undefined1 *)(param_1 + 0x20c) = 0;
    }
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_004663c0;
  puStack_1c = (undefined1 *)0x4663b8;
  FUN_00403b50((int *)&local_c);
  return;
}

