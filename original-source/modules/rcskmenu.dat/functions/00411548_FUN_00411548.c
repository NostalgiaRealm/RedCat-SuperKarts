/*
 * FUN_00411548 at 00411548
 * undefined FUN_00411548(void)
 * Address ranges: 00411548-00411579
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411548(int param_1,int param_2,int *param_3)

{
  if ((param_2 < 0) || (*(int *)(param_1 + 0x10) <= param_2)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  FUN_00403ba4(param_3,*(undefined4 **)(*(int *)(param_1 + 0xc) + param_2 * 8));
  return;
}

