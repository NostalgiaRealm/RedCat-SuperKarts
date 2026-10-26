/*
 * FUN_0045fac0 at 0045fac0
 * int __register FUN_0045fac0(int * param_1, int param_2)
 * Address ranges: 0045fac0-0045fb06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0045fac0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = param_1[0x7f];
  if (iVar1 != param_1[0x80]) {
    iVar2 = FUN_0043f0b0(param_1);
    iVar2 = ((iVar2 + param_1[0x86] * -2) * (param_2 - iVar1)) / (param_1[0x80] - param_1[0x7f]) +
            param_1[0x86];
  }
  return iVar2;
}

