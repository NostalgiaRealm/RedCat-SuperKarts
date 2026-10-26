/*
 * FUN_00459e14 at 00459e14
 * undefined __register FUN_00459e14(int param_1, byte param_2, int * param_3)
 * Address ranges: 00459e14-00459e48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00459e14(int param_1,byte param_2,int *param_3)

{
  byte bVar1;
  
  FUN_00403b50(param_3);
  bVar1 = 0;
  do {
    if (bVar1 == param_2) {
      FUN_00403ba4(param_3,*(undefined4 **)(param_1 + 4 + (uint)bVar1 * 4));
      return;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 != 0x53);
  return;
}

