/*
 * FUN_0042ec20 at 0042ec20
 * undefined __register FUN_0042ec20(int * param_1)
 * Address ranges: 0042ec20-0042ec9e;0042ecc1-0042ecc7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ec20(int *param_1)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  char local_9;
  int *local_8;
  
  puStack_1c = &stack0xfffffffc;
  puStack_20 = &LAB_0042ec9f;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  local_9 = '\0';
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 0xd0))();
  if ((cVar1 != '\0') && (local_9 = '\x01', *(short *)((int)local_8 + 0x27a) != 0)) {
    (*(code *)local_8[0x9e])(local_8[0x9f],local_8,&local_9);
  }
  if (local_9 == '\0') {
    local_8[0x8d] = 0;
  }
  else if (local_9 == '\x02') {
    FUN_0042ed64(local_8);
  }
  *in_FS_OFFSET = uStack_24;
  return;
}

