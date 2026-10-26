/*
 * FUN_00440a04 at 00440a04
 * undefined __register FUN_00440a04(int * param_1, int param_2)
 * Address ranges: 00440a04-00440a49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440a04(int *param_1,int param_2)

{
  FUN_0043f21c(param_1,param_1);
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  if ((*(byte *)(param_1 + 0x10) & 2) != 0) {
    FUN_0043f868(param_1,'\x01');
  }
  if ((*(byte *)(param_1 + 0x10) & 8) != 0) {
    *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) | 2;
  }
  FUN_004409c0(param_1,param_2,0,0);
  return;
}

