/*
 * FUN_00439a38 at 00439a38
 * undefined __register FUN_00439a38(int * param_1, undefined4 param_2, undefined4 param_3, undefined1 param_4)
 * Address ranges: 00439a38-00439a68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439a38(int *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  if ((*(ushort *)(param_1 + 8) & 9) == 0) {
    (**(code **)(*param_1 + 0x30))(param_1,param_3,param_4);
  }
  return;
}

