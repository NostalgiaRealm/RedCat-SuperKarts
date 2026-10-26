/*
 * FUN_0045fb08 at 0045fb08
 * int __register FUN_0045fb08(int * param_1)
 * Address ranges: 0045fb08-0045fb5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0045fb08(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[0x86];
  iVar1 = param_1[0x7f];
  if (iVar1 != param_1[0x80]) {
    iVar2 = FUN_0043f0b0(param_1);
    iVar2 = (((iVar2 - *(int *)(param_1[0x84] + 0x38)) + param_1[0x86] * -2) *
            (param_1[0x81] - iVar1)) / (param_1[0x80] - param_1[0x7f]) + param_1[0x86];
  }
  return iVar2;
}

