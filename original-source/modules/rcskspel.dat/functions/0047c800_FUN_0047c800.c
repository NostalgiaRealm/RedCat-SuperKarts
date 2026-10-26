/*
 * FUN_0047c800 at 0047c800
 * undefined FUN_0047c800(void)
 * Address ranges: 0047c800-0047c837
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047c800(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
    FUN_0040b4b0();
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

