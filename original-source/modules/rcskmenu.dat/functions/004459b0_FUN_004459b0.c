/*
 * FUN_004459b0 at 004459b0
 * undefined __register FUN_004459b0(int * param_1, byte param_2, undefined4 param_3)
 * Address ranges: 004459b0-00445a13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004459b0(int *param_1,byte param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  puStack_18 = &LAB_00445a14;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  if ((param_2 != *(byte *)(param_1 + 0x5f)) &&
     (*(byte *)(param_1 + 0x5f) = param_2, ((*(byte *)(param_1 + 8) & 0x10) == 0 & param_2) != 0)) {
    FUN_00403088(param_1,&local_8,param_3);
    FUN_004054a8(param_1 + 0x52,local_8);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00445a1b;
  puStack_18 = (undefined1 *)0x445a13;
  FUN_00405490((int *)&local_8);
  return;
}

