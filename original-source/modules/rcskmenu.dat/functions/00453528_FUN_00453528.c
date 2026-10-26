/*
 * FUN_00453528 at 00453528
 * undefined __register FUN_00453528(int param_1, undefined4 param_2, undefined4 param_3, undefined1 param_4)
 * Address ranges: 00453528-00453548
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453528(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  if (*(short *)(param_1 + 0x6a) != 0) {
    (**(code **)(param_1 + 0x68))(*(undefined4 *)(param_1 + 0x6c),param_1,param_2,param_4,param_3);
  }
  return;
}

