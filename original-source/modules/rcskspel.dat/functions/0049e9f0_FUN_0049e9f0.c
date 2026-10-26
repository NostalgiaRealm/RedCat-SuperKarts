/*
 * FUN_0049e9f0 at 0049e9f0
 * undefined FUN_0049e9f0(void)
 * Address ranges: 0049e9f0-0049ea22
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049e9f0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x224);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  *param_3 = *(undefined4 *)(param_1 + 0x264);
  param_3[1] = *(undefined4 *)(param_1 + 0x268);
  param_3[2] = *(undefined4 *)(param_1 + 0x26c);
  return;
}

