/*
 * FUN_0043b760 at 0043b760
 * undefined FUN_0043b760(void)
 * Address ranges: 0043b760-0043b78a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043b760(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_0049de80(param_2);
    *(undefined4 *)(param_1 * 0xd0 + 0x18 + DAT_0067ee20) = uVar1;
  }
  return;
}

